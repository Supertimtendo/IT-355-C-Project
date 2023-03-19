/*
Lucas Beebe
3/19/23
IT 355 (001)
Rule: FIO30-C: Exclude user input from format strings
*/
#include<stdlib.h>
#include<stdio.h>



int main(){
    char nameStr[50];
    char sportStr[50];

    //first user input interaction
    printf("Enter your name: ");
    char welcomePrintout[] = "Hi %s, it is nice to meet you\n";
    scanf("%49s",nameStr);

    //using the user input as an argument to fprintf to remove the vulnerability of malicious code being run
    fprintf(stdout, welcomePrintout,nameStr);

    //second user input interaction
    printf("\nWhat is your favorite sport? ");
    char sportPrintout[] = "%s's favorite sport is %s\n";
    scanf("%49s",sportStr);

    //using the user input as arguments to fprintf to remove the vulnerability of malicious code being run
    fprintf(stdout, sportPrintout,nameStr,sportStr);
    

}