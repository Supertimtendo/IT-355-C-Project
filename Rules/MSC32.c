#include<stdlib.h>
#include<stdio.h>
#include<time.h>

struct timespec ts;
int main(){

    srandom(ts.tv_nsec ^ ts.tv_sec);
    int random_num = random();
    printf("Random num %d",random_num);
    return 0;
}