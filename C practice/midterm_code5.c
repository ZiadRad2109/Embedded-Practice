//c function to count number of ones in binary number?
#include <stdio.h>

void count_bin(int num);

void main(void){
printf("enter a number: ");
int number;
scanf("%d",&number);
count_bin(number);
}
void count_bin(int num){
    int count=0;
    while(num>0){
    if(num&1){
        count++;
    }
    num = num>>1;
    }
    printf("number of ones = %d", count);
}