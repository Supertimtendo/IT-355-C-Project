/*
Lucas Beebe
3/19/23
IT 355 (001)
Rec: ARR02-C: Explicitly specify array bounds, even if implicitly defined by an initializer
*/
#include<stdlib.h>
#include<stdio.h>

int main(){
    //intializing the arrays while also specifying the bounds of the arrays
    int powersOfTwo[7] = {1,2,4,8,16,32,64};
    char randomText[6] = "guard";

    //printing out each element of the powersOfTwo array
    for(int i = 0; i < 6; i++){
        printf("2 to the power of %d: %d\n", i, powersOfTwo[i]);
    }

    //printing out the randomText char array
    fprintf(stdout, randomText);
    
    return 0;
}