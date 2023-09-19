/*  Driver for LIFO data structure (Stack)
    Author: Ziad Hisham
    Header File: lifo.h
*/
#ifndef LIFO_H_
#define LIFO_H_
#include <stdio.h>
#include <stdlib.h>
#include "Platform_Types.h"

// User Configurations
#define ELEMENT_TYPE uint32 //<-- change here
#define LENGTH 5

// LIFO information
typedef struct
{
    ELEMENT_TYPE length;
    ELEMENT_TYPE *base;
    ELEMENT_TYPE *head;
    ELEMENT_TYPE count; //--> can be optimized for a smaller data type
} LIFO_Buffer_t;

// LIFO Status
typedef enum
{
    LIFO_OK,
    LIFO_FULL,
    LIFO_EMPTY,
    LIFO_NULL // lifo unavailable or unitialized
} LIFO_Status;

/* Driver APIs*/

/*
    Description: Adds item to the stack (push)
    output: LIFO Status -->enum
    Input: Stack buffer by reference and the item to be added
*/
LIFO_Status LIFO_Push(LIFO_Buffer_t *lifo_buffer, ELEMENT_TYPE item);

/*
    Description: Gets item from stack (pop)
    output: LIFO Status -->enum
    Input: Stack buffer by reference and the item to be added by reference (dummy)
*/
LIFO_Status LIFO_Pop(LIFO_Buffer_t *lifo_buffer, ELEMENT_TYPE *item);

/*
    Description: Initalizes Stack buffer
    output: LIFO Status -->enum
    Input: Stack buffer by reference, the array to be assigned the stack and the length
*/
LIFO_Status LIFO_init(LIFO_Buffer_t *lifo_buffer, ELEMENT_TYPE *array_buffer, ELEMENT_TYPE length);

#endif // !LIFO_H_
