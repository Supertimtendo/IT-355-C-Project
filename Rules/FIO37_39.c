/*
Lucas Beebe
3/19/23
IT 355 (001)
Rules: FIO37-C: Do not assume that fgets() or fgetws() returns a nonempty string when successful
     and FIO39-C: Do not alternately input and output from a stream without an intervening flush or positioning call
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    char messageBuffer[100];
    char readBuffer[100];
    FILE *fp;
    
    //opening the file
    fp = fopen("testText.txt", "w+");
    if(fp == NULL){
        fprintf(stderr, "Error opening the file");
        exit(1);
    }

    //getting input message from the user
    fprintf(stdout, "Enter a message: ");
    if(fgets(messageBuffer, sizeof(messageBuffer),stdin)){
        //checking if the input contain a newline char
        if(strlen(messageBuffer) == 0){
            fprintf(stderr, "fgets() succeeded, but the string is empty");
        }
    }else{
        fprintf(stderr, "fgets() failed to read user input");
    }
    
    /*
    Since the string length is passed as an argument for fwrite, it make it very important that the messageBuffer was
    checked for any newline values previously as the length could've been wrong.
    */
    int bytesWritten = fwrite(messageBuffer,1, strlen(messageBuffer), fp);


    
    fflush(fp);

    //sets the position of the reading to the beginning of the file
    int seekVal = fseek(fp, 0L,SEEK_SET);
    if(seekVal != 0){
        fprintf(stderr, "fseek() failed to reset position at the beginning of the file");
        exit(1);
    }


    //reading from the file
    if(fgets(readBuffer,sizeof(readBuffer),fp)){
        if(strlen(messageBuffer) == 0){
            fprintf(stderr, "fgets() succeeded, but the string is empty");
        }
    }else{
        fprintf(stderr, "fgets() failed to read from file");
    }
    printf("This is the readBuffer: %s",readBuffer);
    

    fclose(fp);

}