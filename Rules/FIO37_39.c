/*
Lucas Beebe
3/17/23
IT 355 (001)
Rules: FIO37 and FIO39
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    char userInputBuffer[1024];
    char readBuffer[1024];
    FILE *fp;
    
    

    fp = fopen("testText.txt", "a+");
    if(fp == NULL){
        fprintf(stderr, "Error opening the file");
        exit(1);
    }

    for(int i = 0; i < 5; i++){
        if(fgets(userInputBuffer, sizeof(userInputBuffer),stdin)){
            char *newLinePointer = strchr(userInputBuffer, '\n');
            if (newLinePointer){
                *newLinePointer = '\0';
            }
    }
    }
    

    int bytesWritten = fwrite(userInputBuffer,1, sizeof(userInputBuffer), fp);
    if(bytesWritten != sizeof(userInputBuffer)){
        fprintf(stderr, "Error writing to the file");
    }

    fflush(fp);

    int bytesRead = fread(readBuffer, sizeof(readBuffer), 1, fp);
    fprintf(stdin, readBuffer);

    fclose(fp);

}