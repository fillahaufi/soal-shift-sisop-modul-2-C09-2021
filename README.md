# soal-shift-sisop-modul-2-C09-2021
# Laporan Resmi Modul 2 #

## Soal 1 ##
### Pengerjaan ###
#### Soal 1a. ####
1. Diminta untuk membuat nama folder sesuai dengan ketentuan yaitu Musyik untuk mp3, Fylm untuk mp4, dan Pyoto untuk jpg.
```
child1 = fork();
 if (child1 < 0) exit(0);
 if (child1 == 0){
     char *argv[] = {"mkdir", "-p", "/home/fajrinam/modul2/soal1/Musyik", NULL};
     execv("/bin/mkdir", argv);
 }
child2 = fork();
 if (child2 < 0) exit(0);
 if (child2 == 0){
     char *argv[] = {"mkdir", "-p", "/home/fajrinam/modul2/soal1/Fylm", NULL};
     execv("/bin/mkdir", argv);
 }
child3 = fork();
 if (child3 < 0) exit(0);
 if (child3 == 0){
     char *argv[] = {"mkdir", "-p", "/home/fajrinam/modul2/soal1/Pyoto", NULL};
     execv("/bin/mkdir", argv);
 }
```
#### Soal 1b. ####
1. Diminta untuk mendownload Musik, Film dan Foto dari link yang telah disediakan.
```
while (wait(&status) > 0);
 child4 = fork();
 if (child4 < 0) exit(0);
 if (child4 == 0){
     char *arg[] = {"wget", "--no-check-certificate", "https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download", "-O", "Musik_for_Stevany.zip", "-o", "/dev/null", NULL};
     execv("/usr/bin/wget", arg);
 }
while (wait(&status1) > 0);
 child5 = fork();
 if (child5 < 0) exit(0);
 if (child5 == 0){
     char *arg[] = {"wget", "--no-check-certificate", "https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download", "-O", "Film_for_Stevany.zip", "-o", "/dev/null", NULL};
     execv("/usr/bin/wget", arg);
 }
while (wait(&status2) > 0);
 child6 = fork();
 if (child6 < 0) exit(0);
 if (child6 == 0){
     char *arg[] = {"wget", "--no-check-certificate", "https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download", "-O", "Foto_for_Stevany.zip", "-o", "/dev/null", NULL};
     execv("/usr/bin/wget", arg);
 }
```
#### Soal 1c. ####
1. Diminta agar folder yang dibuat tidak berisikan zip, maka perlu untuk meng-extract terlebih dahulu.
```
while (wait(&status3) > 0);
 child7 = fork();
 if (child7 < 0) exit(0);
 if (child7 == 0){
     char *arg[] = {"unzip", "-o", "-q", "./Musik_for_Stevany.zip", NULL};
     execv("/usr/bin/unzip", arg);
 }
while (wait(&status4) > 0);
 child8 = fork();
 if (child8 < 0)exit(0);
 if (child8 == 0){
     char *arg[] = {"unzip", "-o", "-q", "./Film_for_Stevany.zip", NULL};
     execv("/usr/bin/unzip", arg);
 }
while (wait(&status5) > 0);
 child9 = fork();
 if (child9 < 0) exit(0);
 if (child9 == 0){
     char *arg[] = {"unzip", "-o", "-q", "./Foto_for_Stevany.zip", NULL};
     execv("/usr/bin/unzip", arg);
 }
```
#### Soal 1d. ####
1. Diminta hanya memindahkan file ke dalam folder yang telah dibuat sebelumnya.
```
while (wait(&status6) > 0);
 child10 = fork();
 if (child10 < 0) exit(0);
 if (child10 == 0){
     char *argv[] = {"find", "./MUSIK", "-mindepth", "1", "-type", "f", "-exec", "mv", "-t", "./Musyik", "{}", "+", NULL};
     execv("/usr/bin/find", argv);
 }
while (wait(&status7) > 0);
 child11 = fork();
 if (child11 < 0) exit(0);
 if (child11 == 0){
     char *argv[] = {"find", "./FILM", "-mindepth", "1", "-type", "f", "-exec", "mv", "-t", "./Fylm", "{}", "+", NULL};
     execv("/usr/bin/find", argv);
 }
while (wait(&status8) > 0);
 child12 = fork();
 if (child12 < 0) exit(0);
 if (child12 == 0) {
     char *argv[] = {"find", "./FOTO", "-mindepth", "1", "-type", "f", "-exec", "mv", "-t", "./Pyoto", "{}", "+", NULL};
     execv("/usr/bin/find", argv);
 }
```
#### Soal 1e. ####
1. Diminta untuk menjalankan semua hal diatas secara otomatis 6 jam sebelum waktu ulang tahun dari Stevany.
- Ulang Tahun Stevany : 09 April Pukul 22.22 WIB
```
if (t->tm_mon+1 == 4 && t->tm_mday == 9 && t->tm_hour == 16 && t->tm_min == 22 && t->tm_sec == 0){
...
...
}
```
#### Soal 1f. ####
1. Pada waktu ulang tahun Stevany, semua folder akan di zip dengan format nama Lopyu_Stevany.zip
- Ulang Tahun Stevany : 09 April Pukul 22.22 WIB
```
if (t->tm_mon+1 == 4 && t->tm_mday == 9 && t->tm_hour == 22 && t->tm_min == 22 && t->tm_sec == 0){
  child14 = fork();
  if (child14 == 0){
      child15 = fork();
      if (child15 < 0) exit(0);
      if (child15 == 0){
          char *arg[] = {"zip", "-q", "-rm", "Lopyu_Stevany.zip", "./Musyik", "./Fylm", "./Pyoto", NULL};
          execv("/usr/bin/zip", arg);
      }
  }
```
2. Kemudian semua folder akan di delete sehingga hanya menyisakan file Lopyu_Stevany.zip
```
while (wait(&status11) > 0);
 child16 = fork();
 if (child16 < 0) exit(0);
 if (child16 == 0){
     char *arg[] = {"rm", "-r", "./MUSIK", "./FILM", "./FOTO", NULL};
     execv("/bin/rm", arg);
 }
```

## Soal 2 ##
### Pengerjaan ###
#### Soal 2a. ####
1. Diminta untuk mengekstrak zip ke yang diberikan kedalam "/home/[user]/modul2/petshop" dan menghapus folder-folder yang tidak perlukan
2. Dibuat dulu folder petshop jika belum ada, kemudian unzip folder pets.zip dengan pengecualian folder apex_cheats, musics, dan unimportant_files:
```
if (child_id == 0) {
    // this is child

    char *argv[] = {"mkdir", "-p", "petshop", NULL};
    execv("/bin/mkdir", argv);
    
    
  }
  
  while ((wait(&status)) > 0);
  char *argv2[] = {"unzip", "pets.zip", "-d", "/home/naufaldillah/modul2/petshop", "-x", "*apex_cheats/*", "*musics/*", "*unimportant_files/*", NULL};
  execv("/bin/unzip", argv2);
```
3. Dokumentasi:
![Ubuntu  Running  - Oracle VM VirtualBox 4_25_2021 2_45_15 PM](https://user-images.githubusercontent.com/68325900/115985444-14792480-a5d6-11eb-907a-05f4dd79f1ae.png)

#### Soal 2b. ####
1. Diminta untuk membuat folder setiap jenis peliharaan yang ada di dalam zip
2. Siapkan dulu struct data untuk mengambil file
```
struct dirent *de;

DIR *dr = opendir("/modul2/petshop");
```
3. Copy name file yang ada di folder lalu dipisahkan dengan strtok dan ambil nama peliharaan. Kemudian buat folder dengan nama peliharaan:
```
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
```
3. Kendala: Kode tidak bisa dijalankan

#### Soal 2c. ####
1. Diminta untuk memindahkan foto ke folder dengan kategori yang sesuai kemudian direnam dengan nama peliharaan
2. Kendala: Mengalami masalah dalam pengerjaan

#### Soaal 2d. ####
1. Diminta untuk memindahkan foto ke masing-masing kategori yang sesuai jika terdapat lebih dari satu peliharaan dalam foto
2. Kendala: Mengalami masalah dalam pengerjaan

#### Soal 2e. ####
1. Diminta untuk membuat file "keterangan.txt" yang berisi nama dan umur semuar peliharaan dalam folder tersebut.
2. Fungsi yang dijalankan:
```
  char *argv5[] = {"touch", "Keterangan.txt", NULL};
  execv("usr/bin/touch", argv5);
```
3. Kendala: Kode tidak bisa dijalankan


## Soal 3 ##
### Pengerjaan ###
#### Soal 3a. ####
1. Diminta untuk membuat sebuah folder tiap 40s dengan format nama timestamp sekarang
2. Fungsi yang dijalankan = 
```
void createDir(char awowo[])
{
    pid_t child_id, child_id2;
    time_t rawtime;
    struct tm * timenow;

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
        char *argv[] = {"mkdir", awowo, NULL};
        execv("/bin/mkdir", argv);
    }
}
```
3. Untuk pemanggilan tiap 40s maka di main dijalankan fungsi tersebut =
```
int main(int argc, char* argv[])
{
    int status;
    while(wait(&status) > 0);

    daemonLurr(); //fungsi pemanggilan daemon

    while(1)
    {
        char foldname[40];
        createDir(foldname);

        sleep(40);
    }
}
```
4. Dokumentasi = 

![image](https://user-images.githubusercontent.com/63279983/115980531-a0c81f00-a5b7-11eb-9f2a-c03804360eff.png)


#### Soal 3b. ####
1. Diminta mendownload gambar pada website picsum.photos tiap 5 detik dan diberi nama sesuai timestamp
2. Fungsi yang dijalankan = 
```
void downloadPic(char awowo[])
{
    int statuslur;
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
        chdir("..");
    }
}
```
3. Fungsi tersebut meminta sebuah variabel 'awowo' yang berarti meminta dimana folder tempat kita akan mendownload gambar yang diinginkan
4. Seperti pada pembuatan folder, kita menggunakan fungsi sleep(5) yang berarti akan mengulang fungsi tersebut dengan delay 5 detik
5. Pemanggilan fungsi download terdapat didalam fungsi pembuatan folder =
```
void createDir(char awowo[])
{
    pid_t child_id, child_id2;
    time_t rawtime;
    struct tm * timenow;
    int statDir;

    time (&rawtime);
    timenow = localtime(&rawtime);
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
        }
    }
}
```
6. dokumentasi = 

![image](https://user-images.githubusercontent.com/63279983/115980652-8b072980-a5b8-11eb-9d73-752ad3b7c09a.png)


#### Soal 3c. ####
1. Membuat sebuah file status.txt yang didalamnya tertulis "Download Success" yang terenskripsi dengan metode cipher, setelah itu folder tersebut di zip dan di delete
2. Untuk fungsi pembuatan file status.txt = 
```
char msg_info[100] = "Download Success";
cipherCrypt(msg_info, 5); // 5 karena kita akan men-shift tiap huruf sebanyak 5

FILE* downloadstatus = fopen("status.txt", "w");
fprintf(downloadstatus,"%s", msg_info);
```
3. Untuk fungsi enkripsi cipher =
```
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
```
4. Fungsi untuk pembuatan zip file =
```
void createZip(char awowo[]) // awowo sebagai nama file yang akan di zip
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
```
5. Fungsi untuk menghapus file =
```
void createZip(char awowo[]) // awowo sebagai nama file yang akan di zip
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
```
6. Untuk pemanggilan fungsi terdapat didalam fungsi pembuatan folder dibawah pemanggilan fungsi download gambar = 
```
void createDir(char awowo[])
{
    pid_t child_id, child_id2;
    time_t rawtime;
    struct tm * timenow;
    int statDir, statEnc, statZip;

    time (&rawtime);
    timenow = localtime(&rawtime);
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
        }
    }
}
```
7. Dokumentaasi =

![image](https://user-images.githubusercontent.com/63279983/115980871-28169200-a5ba-11eb-8650-564d8e63b287.png)

![image](https://user-images.githubusercontent.com/63279983/115980879-349aea80-a5ba-11eb-9e0a-cce78aeba80f.png)

![image](https://user-images.githubusercontent.com/63279983/115980887-41b7d980-a5ba-11eb-90da-c3ce8f719a50.png)


#### Soal 3d. ####
1. Membuat killer program yang akan menghentikan seluruh proses soal3 dan merupakan program bash
2. Fungsi yang dijalankan =
```
void createKiller()
{
    FILE* killer;
    killer = fopen("killer.sh", "w");
    fprintf(killer, "#!/bin/bash\npkill -f soal3\necho \'Proccess have been killed!\'\nrm killer.sh");
    fclose(killer);
}
```
3. Pemanggilan dilakukan pada main =
```
int main(int argc, char* argv[])
{
    createKiller();
    ...
}
```
4. Dokumentassi =

![image](https://user-images.githubusercontent.com/63279983/115981012-04078080-a5bb-11eb-83bf-69ef32225d65.png)

![image](https://user-images.githubusercontent.com/63279983/115981025-197caa80-a5bb-11eb-956b-60ef11f1782e.png)


#### Soal 3e. ####
1. Mmebuat argumen jika z maka proccess harus langsung dimatikan, jika x maka menunggu penghapusan file selesai baru mematikan proccess
2. Fungsi yang dijalankan = 
```
int main(int argc, char* argv[])
{
    if(argv[1][1] == 'z')
    {
        createKiller(1);
    }
    if(argv[1][1] == 'x')
    {
        createKiller(2);
    }
    ...
```
3. Disini kita memodifikasi fungsi createKiller() dengan menambahkan sebuah passingan value, jika argumen z maka pass value 1, jika x maka 2
4. Fungsi createKiller setelah dimodifikasi =
```
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
```
5. Kita juga mendefinisikan sebuah signal untuk menghentikan proccess sebagai variable global dan mendeklarasikan fungsi untuk mengubah signal =
```
int sign;

void changeSign()
{
    sign = 0;
}
```
6. Lalu pada main kita mengedit beberapa code menjadi =
```
int main(int argc, char* argv[])
{
    if(argv[1][1] == 'z')
    {
        createKiller(1);
    }
    if(argv[1][1] == 'x')
    {
        createKiller(2);
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
```
7. Dokumentasi = 

![image](https://user-images.githubusercontent.com/63279983/115981243-9a887180-a5bc-11eb-8b4b-2c0f2943e661.png)

![image](https://user-images.githubusercontent.com/63279983/115981293-d4597800-a5bc-11eb-8a8b-ce4c416ee253.png)

![image](https://user-images.githubusercontent.com/63279983/115981309-f18e4680-a5bc-11eb-91be-fa552904fc3e.png)

