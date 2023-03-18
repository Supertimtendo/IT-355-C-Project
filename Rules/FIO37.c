#include<stdlib.h>
#include<stdio.h>
#include<string.h>


int main(){
    char buffer[1024];
    if(fgets(buffer, sizeof(buffer),stdin)){
        char *pointerToEndofLine = strchr(buffer, '\n');
        if (pointerToEndofLine){
            *pointerToEndofLine = '\0';
        }
    }
    printf("This was your input: %s \n",buffer);
}