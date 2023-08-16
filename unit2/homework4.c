#include <stdio.h>
#include <string.h>
void prime(int num1, int num2);
int fact(int num);
void reverse(char *ch);
int power(int base,int pwr);

int main()
{
    // int interval1, interval2;
    // printf("enter 1st interval: ");
    // scanf("%d", &interval1);
    // printf("\n enter 2nd interval: ");
    // scanf("%d", &interval2);
    // printf("prime numbers between %d and %d are: ", interval1, interval2);
    // prime(interval1,interval2);
    //------------------------------EX2-----------------------------------------
    // int number;
    // printf("Enter a +ve integer: ");
    // scanf("%d",&number);
    // printf("factorial of %d = %d",number,fact(number));
    //------------------------------EX3-----------------------------------------
    // printf("enter a sentence :");
    // char sentence[20] ;
    // gets(sentence);
    // printf("sentence is ( %s )\n", sentence);
    // printf("reversed :");
    // reverse(sentence);
    //-------------------------------EX4-----------------------------------------
    printf("enter base: ");
    int b,exp;
    scanf("%d",&b);
    printf("\n enter exponent: ");
    scanf("%d",&exp);
    printf("%d to the power of %d is = %d",b,exp,power(b,exp));
    return 0;
}
/*EX 1*/
// Function to return prime numbers between two intervals
void prime(int num1, int num2)
{

    char prime;
    while (num1 < num2)
    {

        for (int counter = 2; counter <= num1 / 2; counter++)
        {
            if (num1 % counter == 0)
            {
                prime = 0;
                break;
            }

            else
            {
                prime = 1;
            }
        }
        if (prime == 1)
        {
            printf("%d ", num1);
        }
        num1++;
    }
}

/*EX 2
    Calculate factorial using recursion
*/
int fact(int num){
    if (num >1){
        return num*fact(num-1);
    }
    
}

//EX 3
//Reverse sentence using recursion
void reverse(char *ch){
    if (*ch != '\0'){
        reverse(ch + 1);
        printf("%c", *ch);
    }

}

//EX 4
//Power usimng recursion
int power(int base,int pwr){
    

    if (pwr>0){

        return base*power(base,pwr-1);
    }
    else return 1;

}