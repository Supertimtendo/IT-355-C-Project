/**
 * @file MEM31-C.c
 * @author Trevor Murphy
 * @brief MEM31-C Free Dynamically allocated memory when no longer needed.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main(){

    // Variables
    int *array;
    int arraySize=10,i;

    // Dynamically allocate memory for array
    array = (int*) malloc(arraySize*sizeof(int));

    // Fill array
    for(i=0;i<arraySize;i++){
        array[i]=i;
    }

    // Free dynamically allocated array
    free(array);

    return 0;
}