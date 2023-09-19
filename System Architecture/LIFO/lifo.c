/*  Driver for LIFO data structure (Stack)
    Author: Ziad Hisham
    Source file: lifo.c
*/

#include "lifo.h"

/* Driver APIs*/

/*
    Description: Adds item to the stack (push)
    output: LIFO Status -->enum
    Input: Stack buffer by reference and the item to be added
*/
LIFO_Status LIFO_Push(LIFO_Buffer_t *lifo_buffer, ELEMENT_TYPE item)
{
    // check LIFO validity i.e if base or head is null return LIFO_NULL
    if (lifo_buffer->base == NULL || lifo_buffer->head == NULL)
        return LIFO_NULL;

    // Check if LIFO is full
    if (lifo_buffer->count == lifo_buffer->length)
        return LIFO_FULL;

    // Add element (dereferenced head) and make head point to next address
    *(lifo_buffer->head) = item;
    lifo_buffer->head++;

    // increment counter
    lifo_buffer->count++;
    return LIFO_OK;
}

/*
    Description: Gets item from stack (pop)
    output: LIFO Status -->enum
    Input: Stack buffer by reference and the item to be added by reference (dummy)
*/
LIFO_Status LIFO_Pop(LIFO_Buffer_t *lifo_buffer, ELEMENT_TYPE *item)
{

    // check validity
    if (lifo_buffer->base == NULL || lifo_buffer->head == NULL){
        return LIFO_NULL;
    }

    // check if lifo is empty
    if(lifo_buffer->count == 0){
        return LIFO_EMPTY;
    }

    // decrement head
    lifo_buffer->head--;
    *item = *(lifo_buffer->head);

    // decrement count
    lifo_buffer->count--;
    return LIFO_OK;
}

/*
    Description: Initalizes Stack buffer
    output: LIFO Status -->enum
    Input: Stack buffer by reference, the array to be assigned the stack and the length
*/
LIFO_Status LIFO_init(LIFO_Buffer_t *lifo_buffer, ELEMENT_TYPE *array_buffer, ELEMENT_TYPE length){
    
    //check if array is valid
    if(array_buffer ==NULL){
        return LIFO_NULL;
    }

    //assign base address and head address to the array address
    lifo_buffer->head = array_buffer;
    lifo_buffer->base = array_buffer;

    //assign count =0 and length
    lifo_buffer->count=0;
    lifo_buffer->length = length; 

    return LIFO_OK;
}
