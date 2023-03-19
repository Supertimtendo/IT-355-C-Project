/**
 * @file MEM07-C.c
 * @author Trevor Murphy
 * @brief MEM07-C. Ensure that the arguments to calloc(), when multiplied, do not wrap
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main(){

    int *value;
    size_t num_elements;

    // Check if num_elements will cause value to wrap around
    if(num_elements > SIZE_MAX/sizeof(int)){
        printf("num_elements too great\n");
        return 0;
    }

    // Allocate memory
    value = (int *)calloc(num_elements, sizeof(int));
    if(value == NULL){
        printf("Memory allocation failed\n");
        return 0;
    }

    return 0;
}