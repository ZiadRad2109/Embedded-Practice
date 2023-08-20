// c function to count the max number of ones between two zeros
#include <stdio.h>
int count_max_ones(int n);

void main(void)
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("max number of ones is = %d", count_max_ones(num));
}
int count_max_ones(int n)
{
    int count = 0, zeroflag, max = 0;
    while (n > 0)
    {
        if (n & 1)
        {
            zeroflag = 0;
        }
        else
            zeroflag = 1;
        if (!zeroflag)
        {
            if (count > max)
                max = count;
            count++;
        }
        else
        {
            count = 0;
        }
        n = n >> 1;
    }
    return max+1;
}