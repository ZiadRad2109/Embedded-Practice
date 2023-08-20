//c function to sum numbers from 1 to 100
#include <stdio.h>

int sum_100();

void main(void){
    printf("sum of digits to 100 = %d", sum_100(100));
}
int sum_100(int i){

    if(i>0){

    return i+sum_100(i-1);
    }
    else return i;
}