#include <stdio.h>
#include <string.h>

int main(){
    char buffer[1024];
    char appendBuffer[1024];
    FILE *fp;
    
    

    fp = fopen("testText.txt", "a+");
    if(fp == NULL){
        fprintf(stderr, "Error opening the file");
        exit(1);
    }

    if(fgets(buffer, sizeof(buffer),stdin)){
        char *p = strchr(buffer, '\n');
        if (p){
            *p = '\0';
        }
    }

    int bytesWritten = fwrite(appendBuffer,1, sizeof(appendBuffer), fp);
    if(bytesWritten != sizeof(appendBuffer)){
        fprintf(stderr, "Error writing to the file");
    }

    fflush(fp);

    int bytesRead = fread(buffer, sizeof(buffer), 1, fp);
    fclose(fp);

}