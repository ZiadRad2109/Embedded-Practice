#include <stdio.h>
int main()
{
   unsigned int a=1;
   void *u =&a;
   unsigned char *y=u;
   printf("%d\n",*(y+1)); 
return 0;
}

// int fact(int n);

// int main(void)
// {
//     //int x;
    // float i =0, j =0;
    // printf("enter f 1 : ");
    // scanf("%f",&i);
    // printf("enter f 2 : ");
    // scanf("%f",&j);
    // printf("sum = %f", i*j);

    // char a=0;
    // printf("enter character : ");
    // scanf("%c",&a);
    // printf("ASCII value = %d",a);

    /*to swap two integers without temp var*/ // REVIse
    // int a=0,b=0;
    // printf("enter i 1 : ");
    // scanf("%d",&a);
    // printf("enter i 2 : ");
    // scanf("%d",&b);

    // a ^= b;
    // b ^= a;
    // a^=b;
    // printf("swapped i 1 = %d \n",a);
    // printf("swapped i 2 = %d",b);

    /*CHECK EVEN OR ODD*/
    // int a=0;
    // printf("enter int 1 : ");
    // scanf("%d",&a);
    // if ((a%2)==0) printf("number even");
    // else printf("number odd");

    /*CHECK VOWEL OR CONSTANT*/
    // char a=0;
    // printf("enter character 1 : ");
    // scanf("%c",&a);
    // if ((a == 'a')||(a == 'e')||(a == 'i')||(a == 'o')||(a == 'u'))printf("vowel");
    // else printf("consonant");

    /*POSITIVE OR NEGATIVE*/
    // int a=0;
    // printf("enter int 1 : ");
    // scanf("%d",&a);
    // if (a>=0) printf("number POSITIVE");
    // else printf("number NEGATIVE");

    /*check if in alphabet*/
    // char a=0;
    // printf("enter character 1 : ");
    // scanf("%c",&a);
    // if ((a>=65 && a<=90)||(a>=97 && a<=122))printf("alphabetical");
    // else printf("non-alphabetic");

    /*sum of natural numbers*/
    // int a=0,sum=0;
    // printf("enter int 1 : ");
    // scanf("%d",&a);
    // for(int i=0;i<=a;i++){
    //     sum+=i;
    // }
    // printf("sum of ints up to %d = %d",a,sum);

    /*factorial*/
    // int a=0,fact=1;
    // printf("enter int 1 : ");
    // scanf("%d",&a);
    // if(a>0){
    // for(int i =1;i<=a;i++) fact*=i;
    // printf("factorial of %d = %d",a,fact);
    // }
    // else printf("ERROR");

    /*simple calculator*/
    // float a = 0; float b = 0;
    // char operator;
    // float result = 1.0;
    // printf("ENTER MATH OPERATION + , - , X , / \n");
    // scanf("%c", &operator);
    // printf("\n");
    // printf("enter int 1 : \n");
    // scanf("%f", &a);
    // printf("\n");
    // printf("enter int 2 : \n");
    // scanf("%f", &b);
    // printf("\n");
    // switch (operator)
    // {
    // case '+':
    // {
    //     result = a + b;
    //     printf("%d + %d = %d", a, b, result);
    //     break;
    // }
    // case '-':
    // {
    //     result = a - b;
    //     printf("%d - %d = %d", a, b, result);
    //     break;
    // }
    // case '*':
    // {
    //     result = a * b;
    //     printf("%d * %d = %d", a, b, result);
    //     break;
    // }
    // case '/':
    // {
    //     result = a / b;
    //     printf("%.1f / %.1f = %.1f", a, b, result);
    //     break;
    // }
    // default:
    //     printf("invalid operand");
    // }


    /*quiz test*/
//int i = 0x10+10+10;
//printf("%x",i);

//     char *hamada = "Hello World";
//     hamada[0]= "g";
//     printf("%s",hamada);

// return 0;
// }
// int fact(int n){
//     int factorial =1;
//     for(int i =1; i<=n;i++){
//         factorial*=i;
//         printf("%d %d\n",i,factorial);
//     }
//     return (int)factorial;
// }