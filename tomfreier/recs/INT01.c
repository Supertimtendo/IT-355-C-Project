/**
 * @file INT01.c
 * @author Tom Freier
 * @version 1.0
 * @date 2023-02-10
 * 
 * Shows the proper way to use SEI recommendation INT01-C. Use rsize_t or size_t for all integer values representing the size of an object.
 * 
 * This code shows why the rsize_t type should be used rather than the integer type when iterating through an array.
 * Since the size of the array is larger than the max int value, if an integer type was used it would not be able to reach the final element
 * before it exceeds its max value and overflows.
 */
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>


typedef size_t rsize_t;
/**
 * @brief Prints the final element of the given array
 * 
 * @param arrSize The size of the array
 * @param array The character array
*/
void printFinalArrayValue(rsize_t arrSize, const char *array){
    if (arrSize == 0 || arrSize > SIZE_MAX){
        fprintf(stderr, "Error arrSize:%ld is an invalid size.\n", arrSize);
        return;
    }
    
    /* Iterating to 2nd to last index */
    rsize_t i = 0;
    while(i < arrSize-1){
        i++;
    }

    char finalElem = array[i];
    printf("Final element: %c\n", finalElem);
}


/**
 * Main function that creates a char array that is two larger than the INT_MAX value and calls the printFinalArrayValue() function.
 * 
 * @return Returns 0 for exit success 
*/
int main(){
    rsize_t arraySize = (rsize_t) INT_MAX + 2;
    char charArray[arraySize]; // all vals are 0 by default
    charArray[arraySize-1] = (char) 2; // setting the final value to a unique value.
    // printFinalArrayValue(arraySize, charArray);
    return 0;   
}