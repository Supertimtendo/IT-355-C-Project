/*
Lucas Beebe
3/17/23
IT 355 (001)
Rule: FIO30
*/
#include<stdlib.h>
#include<stdio.h>



int main(){
    char msgStr[50];
    printf("Enter your name: ");
    char welcomePrintout[] = "Hi %s, it is nice to meet you\n";
    scanf("%49s",msgStr);
    fprintf(stdout, welcomePrintout,msgStr);

}