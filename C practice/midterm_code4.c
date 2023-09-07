//c function to revers digits in number?
#include <stdio.h>

void reverse(int num);

void main(void){
    int number;
printf("enter a number :");
scanf("%d",&number);
reverse(number);

}
void reverse(int num){
    int rev=0;
    int rem=0;
    
    while(num!=0){
        rem = num%10;
        rev = rev *10 +rem;
        num /=10;
    }
    printf("reversed number is %d: ",rev);
}