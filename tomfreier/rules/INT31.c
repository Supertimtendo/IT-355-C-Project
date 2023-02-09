/**
 * @file INT31.c
 * @author Tom Freier
 * @version 1.0
 * @date 2023-02-09
 * 
 * Shows the proper way to use SEI rule INT31-C. Ensure that integer conversions do not result in lost or misinterpreted data 
 * 
 * There is a gurantee for all valueswhen converting an integer to the same signage and to a wider type.
 * However, when converting an integer to a different signage or a smaller type, the ranges must first be validated before the conversion.
 * 
 */

#include <stdio.h>
#include <stddef.h>
#include <limits.h>


/**
 * @brief Converts an unsigned int to a signed char and prints the results to console. Will print an error to stderr if the conversion is not valid.
 * 
 * A precondition test is done to validate that when converted the unsigned int will be in a valid range for a signed char type.
 * If this precondition test is failed, an error is printed to stderr.
 * 
 * @param unsignedInt The unsigned int to be converted to a signed char.
*/
void convertUnsignedIntToSignedChar(unsigned int unsignedInt){
    signed char signedChar;
    /* Doing precondition test to ensure the conversion is valid and won't result in a lost of data 
       Could also be the condition: unsignedInt >= SCHAR_MIN. 
       However, this is not necessary as an unsigned int cannot be negative and thus will never be smaller than the SCHAR_MIN value. 
    */
    if(unsignedInt <= SCHAR_MAX){ 
        /* Explicit cast to eliminate warning, this warning is there because this is unsafe without the precondition test*/
        signedChar = (signed char) unsignedInt;

        printf("Succesfully converted %u to %c.\n\n", unsignedInt, signedChar);
    }
    /*Precondition test failed */
    else{
        /* Handle error */

        /* Can safely print a signed char (%c to format) as a signed integer (%d to format) when printing, 
           Since the range of a signed int is greater than the range of values for a signed char.
           
           You are always safely able to cast the same signage to a larger type (ie, it is always safe to convert an unsigned int to an unsigned long).
           But, the reverse is not true if you are going to a smaller size you must validate the ranges first (ie, it may be unsafe to converted a signed long to a signed int). 
        */
        fprintf(stderr, "Error in converting unsigned int: %u to a signed char. The maximum value for a signed char is: %d\n", unsignedInt, SCHAR_MAX);
    }
}

/**
 * @brief Main function that does both a succesful call and unsuccesful call to convert an unsigned int to a signed char.
 * @return Returns 0 for exit success
 */
int main(){
    unsigned int n;
    // Value that can be converted
    n = 65;
    convertUnsignedIntToSignedChar(n);

    //Value that cannot be converted
    n = UINT_MAX;
    convertUnsignedIntToSignedChar(n);

    return 0;
}