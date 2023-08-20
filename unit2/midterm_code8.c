// c function to take an array and revers its elements?
#include <stdio.h>

void reverse();

void main(void)
{

    reverse();
}
void reverse()
{
    printf("enter size of the array: ");
    int size;
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        printf("enter array element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("\n array = ");
    for (int n = 0; n < size; n++)
    {
        printf(" %d ",arr[n]);

    }
    int rev[size];
    int k=size-1;
    for (int j = 0; j <size; j++)
    {
        rev[j] = arr[k];
        k--;
    } 
    printf("\n reversed = ");
    for (int l = 0; l < size; l++)
    {
        printf(" %d ",rev[l]);

    }
}
