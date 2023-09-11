#include <stdio.h>
#include <string.h>
int main(void){
    int arr_size=0;
    printf("input array size: ");
    scanf("%d",&arr_size);
    printf("\ninput %d elements: ", arr_size);
    int arr[arr_size];
    int* ptr_arr = arr;
    for(int i=0;i<arr_size;i++){
        printf("\n element %d : ",i+1);
        scanf("%d",&arr[i]);
    }    
    int reverse[arr_size];
    
    int* ptr_rev = reverse;

    ptr_arr = &arr[arr_size-1];
    printf("\nreverse: \n");
    for(int j = arr_size-1;j>=0;j--){

        
        printf("\nelement %d = %d",j+1,*ptr_arr);
        ptr_arr--;
    }
    
//     char input_str[50];
//     char rev[50];
//     printf("input a string: ");
//     scanf("%s",&input_str);
//     printf("\n string reverse ");
//     char *i_str = input_str;
//     char* r_str = rev;
//     int i =0;
//     //for(int i = sizeof(input_str);i>0;i--)
// while(*i_str){
//     i_str++;
//     i++;
// }
//     for(i;i>=0;i--){
//         i_str--;
//         *r_str = *i_str;
        
//         r_str++;
//     }
//     *r_str = '\0';
//     printf("\n %s", rev);
//     char alphabet[27];
//     char* alpha=alphabet;
//     //printf("%d \t %s",*alpha,alpha);
//     for(int i =0; i<26;i++){
//         *alpha = i+'A';
//         printf("%c  ",*alpha);
//         alpha++;
    
        
//     }
// alpha = alphabet;
// // for(int i=0;i<26;i++){

// // 
// // alpha++;
// // }
    return 0;
}