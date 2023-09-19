/*  Driver for FIFO data structure (Queue)
    Author: Ziad Hisham
    Header File: fifo.h
*/
#ifndef FIFO_H_
#define FIFO_H_
#include <stdio.h>
#include <stdlib.h>
#include "Platform_Types.h"

// User Configuration
#define ELEMENT_TYPE uint8
#define WIDTH 5

// declare array buffer to be used as a queue
ELEMENT_TYPE buffer[WIDTH];

// FIFO Data type info
typedef struct
{
    ELEMENT_TYPE length;
    ELEMENT_TYPE *base;
    ELEMENT_TYPE *tail;
    ELEMENT_TYPE *head;
    ELEMENT_TYPE count;
} FIFO_Buffer_t;

// FIFO status enum
typedef enum 
{
    FIFO_OK,
    FIFO_FULL,
    FIFO_EMPTY,
    FIFO_NULL
}FIFO_Status_t;

// FIFO APIs

/*
    Description: Adds items to queue
    Output: FIFO status
    Input: FIFO buffer, item to be added
*/
FIFO_Status_t FIFO_Enqueue(FIFO_Buffer_t *fifo_buffer, ELEMENT_TYPE item);

/*
    Description: removes items from queue
    Output: FIFO status
    Input: FIFO buffer, item (dummy)
*/
FIFO_Status_t FIFO_Dequeue(FIFO_Buffer_t *fifo_buffer, ELEMENT_TYPE *item);

/*
    Description: Initializes queue
    Output: FIFO status
    Input: FIFO buffer, array to be assigned queue and size
*/
FIFO_Status_t FIFO_init(FIFO_Buffer_t *fifo_buffer, ELEMENT_TYPE *array_buffer, ELEMENT_TYPE length);

/*
    Description: Checks if queue is full
    Output: FIFO status
    Input: FIFO buffer
*/
FIFO_Status_t FIFO_is_full(FIFO_Buffer_t *fifo_buffer);

/*
    Description: Prints Queue
    Output: void
    Input: FIFO buffer
*/
void FIFO_Print(FIFO_Buffer_t *fifo_buffer);

#endif // !FIFO_H_
