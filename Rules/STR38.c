/**
 * @file STR38.c
 * @author Tim Buranicz
 * @version 1.0
 * Shows the proper way to use rule STR38-C
 */

#include <stddef.h>
#include <string.h>
#include <stdio.h>
/**
 * Method to copy over a wide string to another, and display it
 * @param wideC Wide string to copy over
 */
void wideCopy(wchar_t wideC[]) {
    wchar_t wideD[] = L"0000000000";
    //Uses wide versions of string copy and string length
    wcsncpy(wideD, wideC, wcslen(wideC));
    printf("%ls\n", wideD);
}
/**
 * Method to copy over a narrow string to another, and display it
 * @param narrowC Narrow string to copy over
 */
void narrowCopy(char narrowC[]) {
    char narrowD[] = "00000";
    //Uses narrow versions of string copy and string length
    strncpy(narrowD, narrowC, strlen(narrowC));
    printf("%s\n",narrowD);
}
/**
* Main function
* @return Return 0 for exit success
*/
int main(){
    wchar_t w[] = L"0123456789";
    char n[] = "01234";
    wideCopy(w);
    narrowCopy(n);
    return 0;
}
