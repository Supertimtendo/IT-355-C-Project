#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int getPower(int base, int exp){
    int rtn_pow = 0;
    if(base > 0 || (base == 0 && exp > 0) || (base < 0 && sizeof(exp) == sizeof(int))){
        rtn_pow = pow(base, exp);
    }
    return rtn_pow;
}

int main(){
    int num = getPower(2, 10);
    printf("Num is %d",num);
    return 0;
}