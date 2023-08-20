// c function to reverse words in string?(failed)
#include <stdio.h>
#include <string.h>
void reverseword(char *str);

void main(void)
{
    char* str1 = "ziad hisham";
    reverseword(str1);
}
void reverseword(char *str)
{
    int size = strlen(str);
    int start, fin;
    fin = size - 1;
    for (int i = fin; i >= 0; i--)
    {
        if (str[i] == ' ' || i == 0)
            start = 0; // 1st word
        else
            start = i + 1; // 2nd word
        for (int j = start; j <= fin; j++)
        {
            printf("%c", str[j]);
        }
        fin = i - 1;
        printf(" ");
    }
}
/*
    char str[100];
    int i, j, len, startIndex, endIndex;

    printf("\n Please Enter any String :  ");
    gets(str);

    len = strlen(str);
    endIndex = len - 1;

    printf("\n *****  Given String in Reverse Order  ***** \n");
    for(i = len - 1; i >= 0; i--)
    {
        if(str[i] == ' ' || i == 0)
        {
            if(i == 0)
            {
                startIndex = 0;
            }
            else
            {
                startIndex = i + 1;
            }
            for(j = startIndex; j <= endIndex; j++)
            {
                printf("%c", str[j]);
            }
            endIndex = i - 1;
            printf(" ");
        }
    }
*/