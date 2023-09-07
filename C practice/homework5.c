#include <stdio.h>

// Ex4 store student info
struct Sstudent
{
    char name[50];
    unsigned short roll;
    float marks;
};

void main(void)
{
    // short num_students = 3;
    struct Sstudent student[10]; //[num_students];
    printf("\nEnter student information \n");

    for (int i = 0; i < 10; i++)
    {
        student[i].roll = i + 1;
        printf("\nRoll number: %d", student[i].roll);
        printf("\nName: ");
        scanf("%s",&student[i].name);
        // scanf("%s",&student.name);

        printf("\nMarks: ");
        scanf("%f", &student[i].marks);

    }
    printf("\n---------------------\nDisplaying Info ");
    for (int i = 0; i < 10; i++)
    {
        printf("\n Name: %s", student[i].name);
        printf("\n Roll: %d", student[i].roll);
        printf("\n Marks: %.2f", student[i].marks);
        printf("\n");
    }
}

// EX3 Add cmplx numbers
//  struct complex
//  {
//      float real;
//      float imaginary;
//  };

// void addcmplx(struct complex A,struct complex B){
//     float addreal, addim;
//     addreal = A.real+B.real;
//     addim = A.imaginary+B.imaginary;
//     printf("sum = %.2f + %.2fi",addreal,addim);
// }

// void main(void){
//     printf("enter first complex number: ");
//     struct complex first,second;
//     scanf("%f %f",&first.real,&first.imaginary);
//     printf("\nenter second complex number: ");
//     scanf("%f %f",&second.real,&second.imaginary);

//     addcmplx(first,second);
// }

// EX2 Add Two Distances
//  struct Sdistance
//  {
//      unsigned int feet;
//      float inches;
//  };

// void Add(struct Sdistance A,struct Sdistance B){
//     int addfeet = A.feet + B.feet;
//     float addinches = A.inches+B.inches;
//     if (addinches>12){
//         addfeet++;
//         addinches -= 12;
//     }
//     printf("\nsum of the two distances = %d\' %.2f \" ",addfeet,addinches);
// }
// void main(void){
//     printf("Enter 1st distance: \n");
//     struct Sdistance first;
//     struct Sdistance second;

//     printf("Feet: ");
//     scanf("%d",&first.feet);
//     printf("\nInches: ");
//     scanf("%f",&first.inches);

//     printf("\nEnter 2nd distance: ");
//     printf("Feet: ");
//     scanf("%d",&second.feet);
//     printf("\nInches: ");
//     scanf("%f",&second.inches);

//     Add(first,second);
// }

// //EX1 store student info

// struct Sstudent
// {
//     char name[50];
//     unsigned short roll;
//     float marks;
// };

// void main(void){
//     //short num_students = 3;
//     struct Sstudent student;//[num_students];
//     printf("\nEnter student information \n");
//     printf("Name: ");
//     gets(&student.name);
//     //scanf("%s",&student.name);
//     printf("\nRoll number: ");
//     scanf("%d",&student.roll);
//     printf("\nMarks: ");
//     scanf("%f",&student.marks);

//     printf("\n---------------------\nDisplaying Info ");
//     printf("\n Name: %s",student.name);
//     printf("\n Roll: %d",student.roll);
//     printf("\n Marks: %f",student.marks);
// }