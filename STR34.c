/**
 * @file STR34.c
 * @author Tim Buranicz
 * @version 1.0
 * Shows the proper way to use rule STR34-C
 */
#include <stdio.h>

/**
 * Converts a given char character into the corresponding integer value
 * @param c Input value to get int of
 * @return Returns the integer value
 */
int charToInt(char c){
    //Default value if c doesn't exist
    int i=EOF;
    //Checks if c is empty or not
    if(c){
        i = (unsigned char) c;
    }
    else{
        printf("Input not valid");
    }
    printf("%d\n",i);
    return i;
}
/**
 * Converts a given integer value into its corresponding char ASCII value
 * @param i Integer input to convert
 * @return Returns the char ASCII value
 */
char intToChar(int i){
    char c = i;
    printf("%c\n",c);
    return c;
}
/**
* Main function
* @return Return 0 for exit success
*/
int main(){
    char c = intToChar(200);
    charToInt(c);
    return 0;
}
