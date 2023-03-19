/**
 * @file MEM10-C.c
 * @author Trevor Murphy
 * @brief MEM10-C. Define and use a pointer validation function 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

// pointer validity check
int checkValidity(int *ptr){
    if (ptr != NULL){
        return 1; // return true
    }else{
        return 0; // return false
    }
}

int main(){

    int *intPtr = (int*) malloc(sizeof(int));

    printf("intPtr valid? %d\n",checkValidity(intPtr));

    free(intPtr);
    intPtr = NULL;

    printf("intPtr valid after free() and set to NULL? %d\n",checkValidity(intPtr));

    return 0;
}