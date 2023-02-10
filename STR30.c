/**
 * @file STR30.c
 * @author Tim Buranicz
 * @version 1.0
 * Shows the proper way to use rule STR30-C
 */

#include <stdio.h>
/**
 * Method demonstrating correct way to create a string in the form of a char pointer
 */
void pointer(){
    //Constant doesn't allow altering data, preventing buffer overflow
    char const *ptr = "Test";
    printf(ptr);
}
/**
 * Method demonstrating correct way to create a string in the form of a char array
 */
void array(){
    //Correct way to make a modifiable string in C
    char arr[] = "Test";
    printf(arr);
}
/**
 * Main function
 * @return Return 0 for exit success
 */
int main() {
    pointer();
    array();
    return 0;
}
