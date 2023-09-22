/***************************************
 *
 * Author: Ziad Hisham
 *
 * Project: Student Database
 *
 * Header file
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Platform_Types.h"

/* Student Data Structure */
struct S_student_data
{
    uint8 ID;
    char name[40];
    float32 height;
};

/* Linked list node */
struct Sstudent
{
    struct S_student_data student; // data
    struct Sstudent *pNextStudent; // pointer to next student
};

struct Sstudent *gpFirstStudent = NULL;
/* APIs */
/**********************Add student**********************/
void Add_Student();

/**********************Delete student**********************/
uint8 Delete_Student();

/**********************View all students**********************/
void View_Students();

/**********************Delete All**********************/
void Clear_DataBase();

/**********************Get Nth Student**********************/
struct Sstudent *Get_Student(uint8* id);

/**********************Get total number of entries**********************/
uint8 Total_Entries();

/**********************Get Nth student from end**********************/
void Get_StudentFromEnd();

/**********************Get Middle Node**********************/
void Get_Middle_Node();

/**********************Loop Detection**********************/
void is_Loop();

/**********************Reverse Entries**********************/
void Reverse();

#endif // !STUDENT_H_
