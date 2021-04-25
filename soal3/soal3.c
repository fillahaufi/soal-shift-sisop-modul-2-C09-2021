#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <wait.h>
#include <sys/prctl.h>
#include <stdbool.h>
#include <syslog.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

int sign;

void cipherCrypt(char msg[], int key)
{
    for(int j = 0; msg[j] != '\0'; ++j)
    {
        char ch = msg[j];
        if(ch >= 'a' && ch <= 'z')
        {
            ch = ch + key;
            if(ch > 'z')
            {
                ch = ch - 'z' + 'a' - 1;
            }
            msg[j] = ch;
        }

        else if(ch >= 'A' && ch <= 'Z')
        {
            ch = ch + key;
            if(ch > 'Z')
            {
                ch = ch - 'Z' + 'A' - 1;
            }
            msg[j] = ch;
        }
    }
}

void daemonLurr()
{
	pid_t pid, sid;
    pid = fork();
    if(pid < 0)
    {
        exit(EXIT_FAILURE);
    }
    if(pid > 0)
    {
        exit(EXIT_SUCCESS);
    }

    umask(0);
    sid = setsid();
    if(sid < 0)
    {
        exit(EXIT_FAILURE);
    }
    // if((chdir("/")) < 0)
    // {
    //     exit(EXIT_FAILURE);
    // }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
}

void downloadPic(char awowo[])
{
    int statuslur;
    // char link[100];
    pid_t child_id;
    child_id = fork();
    if(child_id<0)
    {
        exit(0);
    }
    if(child_id == 0)
    {
        chdir(awowo);
        for(int i=0;i<10;i++){
            time_t rawtime;
            struct tm * timenow;

            time (&rawtime);
            timenow = localtime(&rawtime);
            char picname[100];
            char link[100];
            strftime(picname, 100, "%Y-%m-%d_%H:%M:%S", timenow);
            sprintf(link , "https://picsum.photos/%ld", (rawtime % 1000) + 50);
            pid_t child_id_pic;
            child_id_pic = fork();
            if(child_id_pic<0)
            {
                exit(0);
            }
            if(child_id_pic==0)
            {
                char *argv[]= {"wget", link, "-O", picname, "-o", "/dev/null", NULL};
                execv("/usr/bin/wget", argv);
            }
            sleep(5);
        }
        while(wait(&statuslur)>0);
        char msg_info[100] = "Download Success";
        cipherCrypt(msg_info, 5);

        FILE* downloadstatus = fopen("status.txt", "w");
        fprintf(downloadstatus,"%s", msg_info);
        fclose(downloadstatus);
        chdir("..");
    }
}

void createZip(char awowo[])
{
    char zipname[100];
    strcpy(zipname, awowo);
    strcat(zipname, ".zip");
    pid_t child_id;
    child_id = fork();
    if(child_id < 0) exit(0);
    if(child_id == 0)
    {
        char *argv[] = {"zip", "-r", zipname, awowo, NULL};
        execv("/usr/bin/zip", argv);
    }
}

void deleteDir(char awowo[])
{
    pid_t child_id;
    child_id = fork();
    if(child_id < 0) exit(0);
    if(child_id == 0)
    {
        char *argv[] = {"rm", "-r", awowo, NULL};
        execv("/bin/rm", argv);
    }
}

void createDir(char awowo[])
{
    pid_t child_id, child_id2;
    time_t rawtime;
    struct tm * timenow;
    int statDir, statEnc, statZip;

    time (&rawtime);
    timenow = localtime(&rawtime);
    // char awowo[40];
    strftime(awowo, 40, "%Y-%m-%d_%H:%M:%S" , timenow);

    child_id = fork();
    if (child_id < 0)
    {
        exit(0);
    }
    if(child_id==0)
    {
        if(fork() == 0)
        {
            char *argv[] = {"mkdir", awowo, NULL};
            execv("/bin/mkdir", argv);
        }
        else
        {
            while(wait(&statDir)>0);
            downloadPic(awowo);

            while(wait(&statEnc)>0);
            createZip(awowo);

            while(wait(&statZip)>0);
            deleteDir(awowo);

            // if(sign == 0) break;
        }
    }
}

void changeSign()
{
    sign = 0;
}

void createKiller(int x)
{
    if(x == 1)
    {
        FILE* killer;
        killer = fopen("killer.sh", "w");
        fprintf(killer, "#!/bin/bash\npkill -f soal3\necho \'Proccess have been killed!\'\nrm killer.sh");
        fclose(killer);
    }
    if(x == 2)
    {
        FILE* killer;
        killer = fopen("killer.sh", "w");
        fprintf(killer, "#!/bin/bash\nkillall -15 soal3\necho \'Proccess have been killed!\'\nrm killer.sh");
        fclose(killer);
        signal(SIGTERM, changeSign);
    }
}

int main(int argc, char* argv[])
{
    // createKiller();
    if(argv[1][1] == 'z')
    {
        createKiller(1);
    }
    if(argv[1][1] == 'x')
    {
        createKiller(2);
    }
    // else
    // {
    //     printf("-z / -x\n");
    //     exit(0);
    // }

    pid_t child_id;
    child_id = fork();
    if(child_id < 0)
        exit(0);
    if(child_id == 0)
    {
        char *argv[] = {"chmod", "u+x", "killer.sh", NULL};
        execv("/bin/chmmod", argv);
    }

    int status;
    while(wait(&status) > 0);

    daemonLurr();

    sign = 1;
    while(sign)
    {
        char foldname[40];
        createDir(foldname);

        if(sign == 0) break;

        sleep(40);
    }
}
