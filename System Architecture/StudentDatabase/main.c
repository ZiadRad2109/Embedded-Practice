#include "Student.h"

int main(void)
{
    char temp_text[40];
    printf("\n ============================");
    printf("\n ===== Welcome to Our Student Database =====");
    while(1){
        printf("\n ============================");
        printf("\n Choose one of the following options: ");
        printf("\n (1)\t Add Student");
        printf("\n (2)\t Delete Student");
        printf("\n (3)\t View Database");
        printf("\n (4)\t Clear Database");
        //printf("\n (5)\t Get Student");

        printf("\n Enter option number: ");
        gets(temp_text);
        printf("\n ============================");

        switch (atoi(temp_text))
        {
        case 1:
            Add_Student();
            break;
        case 2:
            Delete_Student();
            break;
        case 3:
            View_Students();
            break;
        case 4:
            Clear_DataBase();
            break;
        // case 5:
        //     uint8* student_id;
        //     printf("\n enter student id: ");
        //     scanf("%d",student_id);
        //     Get_Student(&student_id);
        //     break;
        
        default:
        printf("\n Wrong Option please try again");
            break;
        }
    }

    return 0;
}

/* APIs */
/**********************Add student**********************/

void Add_Student()
{
    struct Sstudent *pNewStudent;
    struct Sstudent *pLastStudent;
    char temp_text[40];

    // check if list is empty
    if (gpFirstStudent == NULL)
    {
        // create new student
        pNewStudent = (struct Sstudent *)malloc(sizeof(struct Sstudent));

        // assign first student pointer to new student
        gpFirstStudent = pNewStudent;
    }
    else
    {
        // navigate to last node (pNext points to null)

        pLastStudent = gpFirstStudent; // start address
        while (pLastStudent->pNextStudent != NULL)
        {
            pLastStudent = pLastStudent->pNextStudent;
        }

        // create new record
        pNewStudent = (struct Sstudent *)malloc(sizeof(struct Sstudent));
        // set pNext of previously last node to the newly created record
        pLastStudent->pNextStudent = pNewStudent;
    }

    // Fill in record: ID, Name, Height
    printf("Enter Student ID: ");
    gets(temp_text);
    pNewStudent->student.ID = atoi(temp_text);

    printf("\n Enter Student Name: ");
    gets(pNewStudent->student.name);

    printf("\n Enter Student Height: ");
    gets(temp_text);
    pNewStudent->student.height = atof(temp_text);
}

/**********************Delete student**********************/
uint8 Delete_Student()
{
    char temp_text[40];

    // get ID to be deleted
    printf("\n Enter student ID to be deleted: ");
    gets(temp_text);
    uint8 ID_delete = atoi(temp_text);

    // check if list isn't empty
    if (gpFirstStudent)
    {
        struct Sstudent *pSelectedStudent = gpFirstStudent;
        struct Sstudent *pPreviousStudent = NULL;

        while (pSelectedStudent)
        {
            // compare each node with selected ID
            if (pSelectedStudent->student.ID == ID_delete)
            {
                if (pPreviousStudent)
                {
                    // if 1st person is not selected
                    pPreviousStudent->pNextStudent = pSelectedStudent->pNextStudent;
                }
                else
                {
                    // if 1st student will be deleted
                    gpFirstStudent = pSelectedStudent->pNextStudent;
                }
                free(pSelectedStudent);
                printf("\n ---------Student Deleted--------- ");
                return 1;
            }
            // next instance
            pPreviousStudent = pSelectedStudent;
            pSelectedStudent = pSelectedStudent->pNextStudent;
        }
    }
    else
    {
        printf("\n Cannot find student ");
        return 0;
    }

    // else cannot find student
}

/**********************View all students**********************/
void View_Students()
{
    struct Sstudent *pCurrentStudent = gpFirstStudent;
    uint16 count = 0;
    if (gpFirstStudent == NULL)
    {
        printf("No entries available ... ");
    }
    else
    {
        printf("\n Student number (%d) ", count + 1);
        printf("\n Student ID: %d ", pCurrentStudent->student.ID);
        printf("\n Student Name: %s", pCurrentStudent->student.name);
        printf("\n Student height: %.1f ", pCurrentStudent->student.height);
        pCurrentStudent = pCurrentStudent->pNextStudent;
        count++;
    }
}

/**********************Delete All**********************/
void Clear_DataBase()
{
    struct Sstudent *pCurrentStudent = gpFirstStudent;

    if (gpFirstStudent == NULL)
    {
        printf("No entries available ... ");
    }
    else
    {
        while (pCurrentStudent)
        {
            struct Sstudent *pTempStudent = pCurrentStudent;
            pCurrentStudent = pCurrentStudent->pNextStudent;
            free(pTempStudent);
        }
        gpFirstStudent = NULL;
    }
}

/**********************Get Nth Student**********************/
struct Sstudent *Get_Student(uint8* id)
{
    struct Sstudent *pCurrentStudent = gpFirstStudent;
    while (pCurrentStudent)
    {
        if (pCurrentStudent->student.ID == *id)
        {
            return pCurrentStudent;
        }
        else
        {
            pCurrentStudent = pCurrentStudent->pNextStudent;
            if (pCurrentStudent->pNextStudent == NULL)
            {
                printf("\n Student Not Found ");
                return NULL;
            }
        }
    }
}

/**********************Get total number of entries**********************/
uint8 Total_Entries()
{
    uint8 count = 0;
    struct Sstudent *pCurrentStudent = gpFirstStudent;
    while (pCurrentStudent->pNextStudent != NULL)
    {
        count++;
    }
    return count;
}

// /**********************Get Nth student from end**********************/
// void Get_StudentFromEnd();

// /**********************Get Middle Node**********************/
// void Get_Middle_Node();

// /**********************Loop Detection**********************/
// void is_Loop();

// /**********************Reverse Entries**********************/
// void Reverse();
