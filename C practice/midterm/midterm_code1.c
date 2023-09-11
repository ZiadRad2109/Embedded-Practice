#include <stdio.h>

// c function to take a number and sum all digits?
int sum_digits(int n);

void main(void)
{
    int num;
    printf("enter a number: ");
    scanf("%d", &num);

    printf("\nsum of %d digits = %d", num, sum_digits(num));
}
int sum_digits(int n)
{
    static int add;
    int rem = 0;
    if (n != 0)
    {
        rem = n % 10;
        add += rem;

        sum_digits(n / 10);
    }
    else
        return 0;
    return add;
}
