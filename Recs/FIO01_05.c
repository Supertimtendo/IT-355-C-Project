/*
Lucas Beebe
3/17/23
IT 355 (001)
Recs: FIO01 and FIO05
*/
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>

struct stat original;
struct stat new;

int main(){
    char *file_name = "testText.txt";

    //FIO01-C: The open() function doesn't rely solely on the filename
    int fd = open(file_name, O_WRONLY);
    if(fd == -1){
        perror("open() failed");
        exit(1);
    }

    char buffer[11] = "Hello World";

    write(fd, buffer, sizeof(buffer));

    if (fstat(fd, &original) == -1){
        perror("fstat() failed");
        exit(-1);
    }

    close(fd);

    fd = -1;
    fd = open(file_name, O_RDONLY);
    if (fd == -1){
        perror("open() failed");
        exit(1);
    }

    if (fstat(fd, &original) == -1){
        perror("fstat() failed");
        exit(-1);
    }


    if((original.st_dev != new.st_dev) || (original.st_ino != new.st_ino)){
        perror("Error: the file was changed");
        exit(-1);
    }
    return 0;
}