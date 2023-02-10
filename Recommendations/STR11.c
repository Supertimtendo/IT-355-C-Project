/**
 * @file STR11.c
 * @author Tim Buranicz
 * @version 1.0
 * Shows the proper way to use rule STR11-C
 */
#include <stdio.h>
/**
 * Method to demonstrate the correct way to intialize a char array string
 */
void charArray(){
    //Add const to make it immutable
    const char im[] = "Immutable";
    printf("%s\n",im);
    //Don't use const to make it mutable
    char m[] = "Mutable";
    printf("%s\n",m);
    //Shows that char array is editable
    m[0] = 'L';
    printf("%s\n",m);

}
/**
* Main function
* @return Return 0 for exit success
*/
int main(){
    charArray();
    return 0;
}
