// c function to print all prime numbers between two numbers?
#include <stdio.h>

void findprime(int num1, int num2);

void main(void)
{
    int n1, n2;
    printf("enter first number: ");
    scanf("%d", &n1);
    printf("\nenter second number: ");
    scanf("%d", &n2);
    findprime(n1, n2);
}
void findprime(int num1, int num2)
{
    int prime_flag = 0;
    for (int i = num1; i <= num2; i++)
    {
        if (i == 2)
        {
            prime_flag = 1;
        }
        else
        {
            for (int j = 1; j <= i / 2; j++)
            {
                if (i % j == 0) // divisible
                    prime_flag = 0;
                else
                    prime_flag = 1;
            }
        }
        if (prime_flag == 1)
            printf("%d ", i);
        else
            ;
    }
}