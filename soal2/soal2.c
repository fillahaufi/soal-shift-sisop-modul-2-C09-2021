#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <string.h>

int main() {
  pid_t child_id;
  pid_t child_id2;
  char animal_name_folder[101];
  int status;
  int status2;
  int return_value;
  
  struct dirent *de;
  
  //char text[100];
  //time_t now = time(NULL);
  //struct tm *t = localtime(&now);
  //strftime(text, sizeof(text)-1, "%d-%m-%Y_%H:%M:%S", t);

  child_id = fork();

  if (child_id < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }

  if (child_id == 0) {
    // this is child

    char *argv[] = {"mkdir", "-p", "petshop", NULL};
    execv("/bin/mkdir", argv);
    
    
  }
  
  while ((wait(&status)) > 0);
  char *argv2[] = {"unzip", "pets.zip", "-d", "/home/naufaldillah/modul2/petshop", "-x", "*apex_cheats/*", "*musics/*", "*unimportant_files/*", NULL};
  execv("/bin/unzip", argv2);
  
  sleep (1);
  while ((wait(&status2)) > 0);
  DIR *dr = opendir("/modul2/petshop");
  while((de = readdir(dr)) != NULL)
  {
    printf("Folder berhasil dibuat\n");
    strcpy(animal_name_folder, "/modul2/petshop");
    strcat(animal_name_folder, strtok(de->d_name, ";"));
    
    child_id2 = fork();
    
    if (child_id2 == 0) {
    	char *argv4[] = {"mkdir", "-p", animal_name_folder, NULL};
    	execv("/bin/mkdir", argv4);
    }
    	
    char *argv5[] = {"touch", "Keterangan.txt", NULL};
    execv("usr/bin/touch", argv5);
  }
}
