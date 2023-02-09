/**
 * @file INT30.c
 * @author Tom Freier
 * @version 1.0
 * @date 2023-02-09
 * 
 * Shows the proper way to use SEI rule INT30-C: Ensure that unsigned integer operations do not wrap 
 * 
 */

#include <stdio.h>
#include <stddef.h>
#include <limits.h>
/**
 * @brief Adds two integers together and prints the sum to console. Will print to stderr if the sum is invalid.
 * 
 * A precondition test will be used to test if the operation is possible by seeing if UINT_MAX -a < b, 
 * if such a condition is valid then UINT_MAX < a + b, and thus the sum will fall in a valid range for an unsigned integer.
 * 
 * @param a 
 * @param b 
 */
void addTwoNumsPreConditionTest(unsigned int a, unsigned int b ){
  unsigned int sum;
  
  /* Precondition to test if the operation is possible and will be in the valid range for an unsigned int*/
  if (UINT_MAX - a < b){
    /* Handle error*/
    fprintf(stderr, "ERROR: sum of %u + %u is to large to fit in an unsigned int. \nThe sum of these two numbers must be below %u.\n", a, b, UINT_MAX);
  }
  else{
    sum = a + b;
    printf("Sum of %u+%u=%u.\n", a,b,sum);
  }
}

/**
 * @brief Adds two integers together and prints the sum to console. Will print to stderr if the sum is invalid.
 * 
 * A postcondition test will be used to test if the addition operation is possible. 
 * If the addition operation resulted in the sum to 'wrap' around to the minimum value, then it will be lower than (at least) one of the operands in the addition expression.
 * Clearly, if the result of a+b is less than a or less than b, then an unsigned integer wrap where to occur. 
 * 
 * @param a One operand to add to another
 * @param b The other operand in the addition expression
 */
void addTwoNumsPostConditionTest(unsigned int a, unsigned int b){
  unsigned int sum = a + b;
  /*
     Post condition test to see if the value of sum exceeded the maximum value and wrapped around
     Clearly, if the sum is less than one of the operands it wrapped around.
  */
  if(sum < a || sum < b){
    /* Handle error*/
    fprintf(stderr, "ERROR: sum of %u + %u is to large to fit in an unsigned int. \nThe sum of these two numbers must be below %u.\n", a, b, UINT_MAX);
  }
  else{
    printf("Sum of %u+%u=%u.\n", a,b,sum);
  }
}

/**
 * @brief Main function that calls the precondition and postcondition  test.
 * @return Returns 0 for exit success
 */
int main(){
  printf("Addition operation that will fall in the range of an unsigned int.\nExpected Result is for both values to be the same:\n\n");
  printf("Calling precondition test:\n");
  addTwoNumsPreConditionTest(2,3);
  printf("Calling postcondition test.\n");
  addTwoNumsPostConditionTest(2,3);


  printf("\n\nAddition operation that will NOT fall in the range of unsigned int and cause an unsigned int wrap.\n\n");
  printf("Calling precondition test:\n");
  addTwoNumsPreConditionTest(2,UINT_MAX-1);
  printf("Calling postcondition test.\n");
  addTwoNumsPostConditionTest(2,UINT_MAX-1);

  return 0;
}