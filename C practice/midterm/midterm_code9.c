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
