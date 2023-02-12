/**
 * @file INT01.c
 * @author Tom Freier
 * @version 1.0
 * @date 2023-02-11
 * 
 * Shows the proper way to use SEI recommendation INT17-C. Define integer constants in an implementation-independent manner
 */

#include <stdio.h>
// Assigning an unsigned type to -1 will cause it to wrap around to the maximum value. Thus giving the max value regardless of the given compiler implementation.
const unsigned long MAX_LONG_VAL = -1;

/**
 * @brief Prints the maximum long value from the MAX_LONG_VAL constant.
 * @return Returns 0 for exit success 
*/
int main(){
    printf("Max long val: %lu\n", MAX_LONG_VAL);
    return 0;
}