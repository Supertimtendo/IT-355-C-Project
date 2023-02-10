/**
 * @file ARR38.c
 * @author Tom Freier
 * @version 1.0
 * @date 2023-02-10
 * 
 * Shows the proper way to use SEI rule ARR38-C. Guarantee that library functions do not form invalid pointers
 * 
 */

#include <string.h>
#include <stdio.h>

/**
 * @brief Copies contents of one character array (original) to another character array (copy).
 * 
 * @param original Character array that is to be copied.
 * @param copy Character array that will hold the copy.
 * @param sizeOfCopy Size of the target array.
 * 
 * This function determines the number of bytes to be copied based on which of the two arrays has a larger size: the original array or the target array. 
 * The smaller of the two sizes is used to prevent buffer overflow attacks by not copying more bytes than the memory allocated for the target array. 
 * The actual copying is done using the memcpy library function.
 * 
 * Then both the original message and the copied message will be printed to console.
 */
void copyFromOneArrayToAnotherArray(const char *original, char *copy, size_t sizeOfCopy){
    size_t numBytes;
    /* Determing if the original string or the array being copied into has a larger size */
    if(sizeOfCopy < (strlen(original) + 1)){ // Length of string is longer, so we can only copy over the length of the copy array.
        numBytes = sizeOfCopy;
    }
    /* Length of array is longer, so we only need to copy over the length of the string. 
       Going any further would be going pass the memory allocated for the original string, potentially leading to buffer overflow attacks.
    */
    else{ 
        numBytes = strlen(original) + 1; // the plus 1 is for the null character at the end of the string
    }

    /* The above if statement ensure that the following library function won't form an invalid pointer, 
     * by exceeding the amount of memory allocated for the object referened (the object being referenced is the character array) by the copy pointer. 
     */
    memcpy(copy, original, numBytes);
    printf("Original message: %s\nCopied message: %s\n", original, copy);
}


/**
 * @brief Main function that calls the copyFromOneArrayToAnotherArray function twice,
 * once using an array that is too small to store the original string and once using an array with sufficient size.
 * 
 * @return Returns 0 for exit success
*/
int main(){
    size_t arraySize;
    char arrayWithTooSmallSize[10];
    char arrayWithSufficientSize[40];
    const char *original = "Message to be copied";


    printf("Copying to an array that is too small to store the original string.\n");
    arraySize = sizeof(arrayWithTooSmallSize);
    copyFromOneArrayToAnotherArray(original, arrayWithTooSmallSize, arraySize);

    
    printf("\n\nCopying to an array with sufficient size to store the original string.\n");
    arraySize = sizeof(arrayWithSufficientSize);
    copyFromOneArrayToAnotherArray(original, arrayWithSufficientSize, arraySize);


    return 0;
}