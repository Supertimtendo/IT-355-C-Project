/**
 * @file STR32.c
 * @author Tim Buranicz
 * @version 1.0
 * Shows the proper way to use rule STR32-C
 */
#include <stdio.h>
/**
 * Method demonstrating the correct way to initialize a char array
 */
void print(){
    //Do not initialize a value for this array, the compiler will do it automatically
    //Or if you do want to initialize it, make sure to consider the null termination symbol
    char c[] = "TEST";
    printf(c);
}

/**
* Main function
* @return Return 0 for exit success
*/
int main(){
    print();
    return 0;
}



