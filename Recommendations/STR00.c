/**
 * @file STR00.c
 * @author Tim Buranicz
 * @version 1.0
 * Shows the proper way to use rule STR00-C
 */

#include <stdio.h>

/**
 * Shows the different basic recommended applications of different types
 */
void values(){
    //Use signed/unsigned for smaller integer values
    signed char neg = '2';
    printf("%c\n",neg);
    unsigned char pos = '2';
    printf("%c\n", pos);
    //Use plain char for strings
    char* c = "ABC";
    printf("%s\n",c);
    //Use integers for larger numbers
    int i = 10000;
    printf("%i\n", i);
    //Use wide chars for larger strings or sentences
    wchar_t* wc = L"Test sentence";
    printf("%ls\n", wc);
}

/**
* Main function
* @return Return 0 for exit success
*/
int main(){
    values();
    return 0;
}
