/*
Lucas Beebe
3/17/23
IT 355 (001)
Rule: MSC32
*/
#include<stdlib.h>
#include<stdio.h>
#include<time.h>


int main(){
    struct timespec ts;
    int random_num;
    srandom(ts.tv_nsec ^ ts.tv_sec); //properly seeding the random number generator

    //generating 5 random numbers: each time this program is run, different numbers will be printed
    for(int i = 1; i <= 5; i++){
        random_num = random(); //generating the random number 
        printf("Random num %d: %d\n",i,random_num);
    }

    return 0;
}