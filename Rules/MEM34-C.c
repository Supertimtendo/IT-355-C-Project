/**
 * @file MEM34-C.c
 * @author Trevor Murphy
 * @brief MEM34-C Only Free memory allocated dynamically.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main(){

    int *array;

    // Initial array memory allocation & data setting
    int arraySize=10,i;
    array = (int*) malloc(arraySize*sizeof(int));
    for(i=0;i<arraySize;i++){
        array[i]=i;
    }

    // Reallocation of memory with new size and setting of new data
    arraySize=5;
    array = (int*) realloc(array,arraySize*sizeof(int));
    for(i=0;i<arraySize;i++){
        array[i]=i*2;
    }

    // Memory is freed
    free(array);

    return 0;
}