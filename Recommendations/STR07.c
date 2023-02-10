/**
 * @file STR07.c
 * @author Tim Buranicz
 * @version 1.0
 * Shows the proper way to use rule STR07-C
 */
#include <stdio.h>
#include <string.h>

/**
 * Method demonstrating correct usage of safe string copy function
 * @param src Input string to copy over
 */
void safeCopy(char src[]){
    char dst[]="00000";
    //Safe string copy, has parameter for max destination length
    strcpy_s(dst, strlen(dst), src);
    printf(dst);
}

/**
* Main function
* @return Return 0 for exit success
*/
int main(){
    char src[] = "TEST";
    safeCopy(src);
    return 0;
}
