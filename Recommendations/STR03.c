/**
 * @file STR03.c
 * @author Tim Buranicz
 * @version 1.0
 * Shows the proper way to use rule STR03-C
 */
#include <stdio.h>
#include <string.h>

/**
 * Method showing correct way to avoid truncating strings
 * @param src Source string to copy from
 * @param dst Destination string to copy to
 */
void copy(char src[], char dst[]){
    //Gets lengths of each string
    size_t s_len = strlen(src);
    size_t d_len = strlen(dst);
    //Checks if destination string is large enough
    if(d_len>=s_len && src!= NULL){
        //Use functions such as strncopy as opposed to strcopy
        strncpy(dst,src,d_len);
        //Remember to null-terminate the string
        dst[d_len] = '\0';
        printf(dst);
    }
    else{
        printf("DST TOO SMALL");
    }
}
/**
* Main function
* @return Return 0 for exit success
*/
int main(){
    char c[] = "TEST";
    char d[] = "0000";
    copy(c,d);
    return 0;
}
