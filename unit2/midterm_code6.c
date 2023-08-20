//c function to return unique number in array with one loop?
#include <stdio.h>

int unique(int num[],int size);

void main(void){
    int arr[]={4,2,5,2,5,7,4};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("unique element = %d",unique(arr,size));
}

int unique(int num[],int size){
    int unique=0;
    for(int i =0;i<size;i++){
        unique ^=num[i];
    }
    return unique;
}