#include <stdlib.h>
#include <stdio.h>

void set_to_odds(int input_array[],size_t arr_length){
    for (size_t i = 0; i < arr_length; i++){
        input_array[i] = i*2 + 1;
    }
}
int main(){
    int num_array[25];
    size_t arr_length = sizeof(num_array) / sizeof(num_array[0]);
    set_to_odds(num_array, arr_length);

    printf("Output Array: ");
    for (size_t i = 0; i < arr_length-1; i++){
        printf("%d, ",num_array[i]);
    }
    printf("%d", num_array[arr_length-1]);

    return 0;
}