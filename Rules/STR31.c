/**
 * @file STR31.c
 * @author Tim Buranicz
 * @version 1.0
 * Shows the proper way to use rule STR31-C
 */

#include <stdio.h>
#include <string.h>
/**
 * Method demonstrating correct way to copy strings, while properly terminating it
 * @param src Source string to copy from
 * @param dst Destination string to copy to
 */
void copy(char src[], char dst[]){
    //Gets lengths of each string
    size_t s_len = strlen(src);
    size_t d_len = strlen(dst);
    //Checks if destination string is large enough
    if(d_len>=s_len && src!= NULL){
        //Copies string
        for (int i = 0; i<s_len-1;++i) {
            dst[i] = src[i];
        }
        //Terminates the string at the end
        dst[s_len] = '\0';
    }
    else{
        printf("DST TOO SMALL");
    }
}

/**
* Main function
* @return Return 0 for exit success
*/
int main() {
    char src[] = "TEST";
    char dst[] = "EMPTY";
    copy(src,dst);
    printf("%s\n", dst);
    return 0;
}
