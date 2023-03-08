#include<stdlib.h>
#include<stdio.h>

int main(){
    char *file_name = "testText.txt";
    FILE *fd = fopen(file_name, "w+");
    if(fd == NULL){

    }
    
    fclose(fd);
    return 0;
}