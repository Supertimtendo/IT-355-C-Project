/*
Lucas Beebe
3/19/23
IT 355 (001)
Recs: FIO01-C: Be careful using functions that use file names for identification
 and FIO05-C: Identify files using multiple file attributes

 Both of these recommendations are done throughout this program because they both have to do with ensuring the intial
 file being used is the same when it is reopened. 
*/
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>


int main(){
    struct stat original;
    struct stat new;
    char *readWriteFile = "testText.txt";

    //opening the file
    int fd = open(readWriteFile, O_WRONLY);
    if(fd < 0){
        fprintf(stderr, "open() failed");
        exit(1);
    }

    char buffer[17] = "This is for IT355";

    //writing to the file
    write(fd, buffer, sizeof(buffer));

    if (fstat(fd, &original) == -1){
        fprintf(stderr, "fstat() failed");
        exit(1);
    }

    close(fd);

    fd = -1;
    fd = open(readWriteFile, O_RDONLY);
    if (fd < 0){
        fprintf(stderr, "open() failed");
        exit(1);
    }

    if (fstat(fd, &new) < 0){
        fprintf(stderr, "fstat() failed");
        exit(1);
    }

    //check to make sure that the two files are the same
    if((original.st_dev != new.st_dev) || (original.st_ino != new.st_ino)){
        fprintf(stderr, "The file was changed... ERROR");
        exit(1);
    }

    char readBuffer[100];

    //reading from the file and printing out what was read to stdout
    int bytesRead = read(fd, readBuffer, sizeof(readBuffer));
    printf("Read from file: %s", readBuffer);
    return 0;
}