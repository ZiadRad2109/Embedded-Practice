#include <stdio.h>

// c function to take an integer number and calculate it's square root?
float squareroot(float n);


void main(void)
{
    int num;
printf("enter a number: ");
scanf("%d",&num);
printf("\n square root of %d is %f",num,squareroot(num));
}
float squareroot(float n){
    if (n<=2)
return n;
else{
    float x,y;
    x=n;
    y=(x + (n/x))/2;

    while (((x-y)>=0.001)||((x-y)<=-0.001)){
        x=y;
        y=(x + (n/x))/2;
    }
    return y;
}
}