/*
Lucas Beebe
3/19/23
IT 355 (001)
Rule: FLP32-C: Prevent or detect domain and range errors in math functions
*/

#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int getPower(int base, int exp){
    int rtn_pow = 0;

    //check to make sure that the base and exponent are valid
    if(base > 0 || (base == 0 && exp > 0) || (base < 0 && sizeof(exp) == sizeof(int))){
        //using pow() function from the math library
        rtn_pow = pow(base, exp);
    }
    return rtn_pow;
}

int main(){

    //calling the getPower() function twice with different arguments
    //each time, the power and arguments are printed to stdout
    int num = getPower(2, 10);
    printf("2^10 is %d\n",num);
    int num2 = getPower(-5,3);
    printf("-5^3 is %d\n", num2);
    return 0;
}