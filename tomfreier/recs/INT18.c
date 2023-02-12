/**
 * @file INT01.c
 * @author Tom Freier
 * @version 1.0
 * @date 2023-02-10
 * 
 * Shows the proper way to use SEI recommendation INT18-C. Evaluate integer expressions in a larger size before comparing or assigning to that size
 * 
 * When evaluating an integer expression, that expression must be evaluated in the larger size by explicitly casting one of the operands.
 */

#include <stdio.h>

/**
 * @brief Compares the sum of two operands with a specefied value and then prints a message to console indicating which value is larger.
 * 
 * The sum of the operands is explicitly cast to the long type to ensure the expression is evaluated in the larger size.
 * 
 * @param operand1 The first operand
 * @param operand2 The second operand
 * @param valToCompareWith The value to compare the sum of the operands with
*/
void compareValues(short operand1, short operand2, long valToCompareWith){
    /* Explicitly casting operand1 to the long type ensures that the expression will be evaluated in the long size, 
       instead of being evaluted in the short size.

       If evaluated in the short size there is a possibility of an integer overflow leading to an incorrect calculation. 
    */
    long sum = (long) operand1 + operand2; 
    if(sum >= valToCompareWith){
        printf("The sum of %hi + %hi = %li is larger than (or equal to): %li.\n", operand1, operand2, sum, valToCompareWith);
    }
    else{
        printf("The sum of %hi+%hi = %li is smaller than %li.\n", operand1, operand2, sum, valToCompareWith);
    }
}


/**
 * @brief Main function that calls compareValues() with two short values that when added would exceed the max value for hte short type.
 * 
 * @return Returns 0 for exit success 
*/
int main(){
    short operand1 = 17000;
    short operand2 = 17000;
    long compareVal = 30000;
    compareValues(operand1,operand2,compareVal); // Max short val is 32k, so adding operand 1 and 2 would overflow if not casted to the larger type 
    return 0;
}   