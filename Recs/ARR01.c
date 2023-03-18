/*
Lucas Beebe
3/17/23
IT 355 (001)
Rec: ARR01
*/
#include <stdlib.h>
#include <stdio.h>

//function that itializes the array with positive odd integers
void set_to_odds(int input_array[],size_t arr_length){
    for (size_t i = 0; i < arr_length; i++){
        input_array[i] = i*2 + 1;
    }
}

int main(){
    int num_array[25];

    //doing the size calculation prior to calling the function, otherwise size of pointer will be used
    size_t arr_length = sizeof(num_array) / sizeof(num_array[0]);
    set_to_odds(num_array, arr_length);

    //printing out the array
    printf("Odd Number Array: ");
    for (size_t i = 0; i < arr_length-1; i++){
        printf("%d, ",num_array[i]);
    }
    printf("%d", num_array[arr_length-1]);

    return 0;
}