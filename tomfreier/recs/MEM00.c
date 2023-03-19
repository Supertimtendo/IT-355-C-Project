/**
 * @file INT01.c
 * @author Tom Freier
 * @version 1.0
 * @date 2023-02-10
 * 
 * Shows the proper way to use SEI recommendation MEM00-C. Allocate and free memory in the same module, at the same level of abstraction
 */

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Prints the values of an array to console
 * 
 * @param array Array of values to print
 * @param arraySize Size of the array
*/
void printArrayVals(int* array, const size_t arraySize){
    printf("%d\n",array[0]);
}

/**
 * @brief Allocates memory for an array, calls the printArrayVals() function on that array, then frees the allocated memory.
 * 
 * Provides an example of how the allocation of memory should be done in the same level of abstraction.
 * If the dynamically allocated memory was needed to be freed in a different level of abstraction can lead to errors if it were not to be freed.
 * In general, when you allocate memory in C you are expected to free that memory. You shouldn't expect someone else to free that memory.
 * 
 * @return Returns 0 for exit success 
*/
int main(){
    size_t size = 10;
    
    // Allocating memory in the 'main' function level of abstraction
    int * arr = (int *) malloc(size);

    for(size_t i = 0;i<size;i++){
        arr[i] = (int) i;
    }

    printArrayVals(arr, size); // Freeing memory in this function would be in violation of the recommendation.


    // Freeing memory in the same level of abstraction.
    free(arr);

    return 0;
}