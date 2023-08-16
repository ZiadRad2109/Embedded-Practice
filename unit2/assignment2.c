#include <stdio.h>

void main(void){

    /*ADD TWO MATRICIES*/
//     int arr1 [2][2];
//     int arr2 [2][2];
//     int addelement =0;


//     printf("1st matrix: \n");
//     for(int i =0;i<2;i++){
//         for(int j =0;j<2;j++){
//             printf("enter value of array element [%d][%d]: ",i,j);
//             scanf("%d",&arr1[i][j]);
//             printf("\n");
//         }
//     }

//     printf("2nd matrix: \n");
//     for(int i =0;i<2;i++){
//         for(int j =0;j<2;j++){
//             printf("enter value of array element [%d][%d]: ",i,j);
//             scanf("%d",&arr2[i][j]);
//             printf("\n");
//         }
//     }

// printf("sum of both matricies : \n");
//     for(int i =0;i<2;i++){
//         for(int j =0;j<2;j++){
//             addelement = arr1[i][j]+arr2[i][j];
//             printf("%d  ",addelement);
//         }
// printf("\n");
//     }

/*AVERAGE OF ARRAY ELEMENTS*/
// int elements=0;
// printf("enter number of elements: ");
// scanf("%d",&elements);
// printf("\n");

// float sum =0;
// float avg=0.0;

// float arr[elements];
// for (int i =0; i<elements;i++){
// printf("enter element number %d : ",i+1);
// scanf("%f",&arr[i]);
// printf("\n");
// }
// for (int i =0; i<elements;i++){
//     sum+=arr[i];
// }
// avg = (float)(sum/elements);
// printf("average = %.1f",avg);

/*TRANSPOSE*/
// int row =0;
// printf("enter matrix row no_elements: ");
// scanf("%d",&row);
// printf("\n");

// int col =0;
// printf("enter matrix column no_elements: ");
// scanf("%d",&col);
// printf("\n");

// int mtrx [row][col];
// int trnspose [col][row];

// printf("enter matrix values: \n");

// for(int i =0;i<row;i++){
//     for(int j=0;j<col;j++){
//         printf("element [%d][%d]= ",i,j);
//         scanf("%d",&mtrx[i][j]);
//         printf("\n");
//     }
// }

// printf("Matrix Entered : \n");
// for(int i =0;i<row;i++){
//     for(int j=0;j<col;j++){
//         printf("%d ",mtrx[i][j]);
//     }
//     printf("\n");
// }


// for(int i =0;i<row;i++){
//     for(int j=0;j<col;j++){
//         trnspose[j][i]=mtrx[i][j];
//     }
// }


// printf("Matrix Transpose : \n");
// for(int i =0;i<col;i++){
//     for(int j=0;j<row;j++){
//         printf("%d ",trnspose[i][j]);
//     }
//     printf("\n");
// }


/*INSERT ELEMENT IN ARRAY*/
// int no_elements =0;
// printf("enter number of elements: ");
// scanf("%d",&no_elements);
// printf("\n");

// int arr[50]={0};
// printf("enter array elements: \n");
// for(int i =0;i<no_elements;i++){
//     scanf("%d",&arr[i]);
// }



// int element=0;
// int loc=0;
// printf("enter element : ");
// scanf("%d",&element);
// printf("\n");
// printf("enter element location : ");
// scanf("%d",&loc);
// printf("\n");


// // for(int i=no_elements-1;i>=no_elements-1;i--){
// //     arr[i+1]=arr[i];
// //     arr[loc-1]= element;
// // }
//     no_elements++;
//     for (int i = no_elements; i >= loc; i--) {
//         arr[i] = arr[i-1];
//     }
    
//     arr[loc-1] = element;

    


// printf("array after adding element: \n");
// for(int i =0;i<no_elements;i++){
//  printf("%d ",arr[i]);
// }

/*SEARCH IN ARRAY*/
// int no_elements =0;
// printf("enter number of elements: ");
// scanf("%d",&no_elements);
// printf("\n");

// int arr[no_elements];
// for(int i =0;i<no_elements;i++){
//     arr[i]=(i+1)*11;
// }

// for(int i =0;i<no_elements;i++){
//     printf("%d ",arr[i]);
// }
// printf("\n");

// int element=0;
// printf("element to be searched: ");
// scanf("%d",&element);
// printf("\n");
// int location=0;
// int c=0;
// for(int i =0;i<no_elements;i++){
//     if(arr[i]==element){
//         printf("number found at location : %d",i+1);
//         break;
//     }
//     c++;
// }
// if(c == no_elements)printf("not found");
}