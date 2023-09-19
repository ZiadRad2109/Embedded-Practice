/*  Driver for FIFO data structure (Queue)
    Author: Ziad Hisham
    Source file: fifo.c
*/
#include "fifo.h"

// FIFO APIs

/*
    Description: Adds items to queue
    Output: FIFO status
    Input: FIFO buffer, item to be added
*/
FIFO_Status_t FIFO_Enqueue(FIFO_Buffer_t *fifo_buffer, ELEMENT_TYPE item)
{
    // check for queue availability
    if (fifo_buffer->head == NULL || fifo_buffer->base == NULL || fifo_buffer->tail == NULL)
    {
        return FIFO_NULL;
    }
    // check if queue is full
    else if (FIFO_is_full(fifo_buffer) == FIFO_FULL)
    {
        return FIFO_FULL;
    }

    // dereference head = item
    else
    {
        *fifo_buffer->head = item;
        // head points to next element but check if head is at the end
        // so that it circulates
        if (fifo_buffer->head == (fifo_buffer->base + (fifo_buffer->length * sizeof(ELEMENT_TYPE))))
        {
            fifo_buffer->head == fifo_buffer->base;
        }
        else
            fifo_buffer->head++;
        // increment count
        fifo_buffer->count++;
        // return ok
        return FIFO_OK;
    }
}

/*
    Description: removes items from queue
    Output: FIFO status
    Input: FIFO buffer, item (dummy)
*/
FIFO_Status_t FIFO_Dequeue(FIFO_Buffer_t *fifo_buffer, ELEMENT_TYPE *item)
{
    // check for queue availability
    if (fifo_buffer->head == NULL || fifo_buffer->base == NULL || fifo_buffer->tail == NULL)
    {
        return FIFO_NULL;
    }

    // check if fifo is empty
    else if (fifo_buffer->count == 0)
    {
        return FIFO_EMPTY;
    }

    // set dereferenced item dummy to the dereferenced tail
    *item = *fifo_buffer->tail;

    // decrement count
    fifo_buffer->count--;

    // increment tail but check if tail reached end of buffer
    if (fifo_buffer->tail == (fifo_buffer->base + (fifo_buffer->length * sizeof(ELEMENT_TYPE))))
    {
        fifo_buffer->tail = fifo_buffer->base;
    }
    else
    {
        fifo_buffer->tail++;
    }
    return FIFO_OK;
}

/*
    Description: Initializes queue
    Output: FIFO status
    Input: FIFO buffer, array to be assigned queue and size
*/
FIFO_Status_t FIFO_init(FIFO_Buffer_t *fifo_buffer, ELEMENT_TYPE *array_buffer, ELEMENT_TYPE length){

    //check if array buffer is available
    if(array_buffer == NULL){
        return FIFO_NULL;
    }
    else{
        fifo_buffer->head = array_buffer;
        fifo_buffer->tail = array_buffer;
        fifo_buffer->base = array_buffer;
        fifo_buffer->length = length;
        fifo_buffer->count = 0;
        return FIFO_OK;
    }
}

/*
    Description: Checks if queue is full
    Output: FIFO status
    Input: FIFO buffer
*/
FIFO_Status_t FIFO_is_full(FIFO_Buffer_t *fifo_buffer){
    // check for queue availability
    if (fifo_buffer->head == NULL || fifo_buffer->base == NULL || fifo_buffer->tail == NULL)
    {
        return FIFO_NULL;
    }

    //check if count = size
    else if (fifo_buffer->count == WIDTH){
        return FIFO_FULL;
    }
    else{
        return FIFO_OK;
    }
}

/*
    Description: Prints Queue
    Output: void
    Input: FIFO buffer
*/
void FIFO_Print(FIFO_Buffer_t *fifo_buffer){
    ELEMENT_TYPE* temp; // will be used to loop
    ELEMENT_TYPE i;
    
    //check if fifo is empty
    if(fifo_buffer->count ==0 ){
        printf("\n Queue is empty");
    }
    else{
        temp = fifo_buffer->tail;
        printf("\n ========= Queue =========");
        for ( i = 0; i < fifo_buffer->count; i++)
        {
            printf("\t %x \n",*temp);
            temp++;
        }
        printf("=========================\n");
    }

}
