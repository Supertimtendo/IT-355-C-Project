/*
Lucas Beebe
3/17/23
IT 355 (001)
Rec: ARR02
*/
#include<stdlib.h>
#include<stdio.h>

int main(){
    int powersOfTwo[7] = {1,2,4,8,16,32,64};
    char username[6] = "guard";
    for(int i = 0; i < 6; i++){
        printf("2 to the power of %d: %d\n", i, powersOfTwo[i]);
    }
    fprintf(stdout, username);
    
    return 0;
}