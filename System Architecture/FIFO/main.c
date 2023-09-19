/*
    Author: Ziad Hisham
    Driver: FIFO
    Source File: main.c
*/

#include "fifo.h"

int main(void)
{
    uint8 temp = 0, i;

    // declare FIFO buffers
    FIFO_Buffer_t UART_FIFO;

    // FIFO initalization + saftey
    if (FIFO_init(&UART_FIFO, buffer, WIDTH) == FIFO_OK)
        printf("xxxxxx Initialized xxxxxx");

    for (i = 0; i < WIDTH + 2; i++)
    {
        printf("\n Enqueueing (%x)", i);
        if (FIFO_Enqueue(&UART_FIFO, i) == FIFO_OK)
        {
            printf(" \t ====> queued successfully ");
        }
        else
            printf("\t ====> failed to queue ");
    }

    for (i = 0; i < WIDTH + 2; i++)
    {
        printf("\n Enqueueing (%x)", i);
        if (FIFO_Enqueue(&UART_FIFO, i) == FIFO_OK)
        {
            printf(" \t ====> queued successfully ");
        }
        else
            printf("\t ====> failed to queue ");
    }
    printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");

    FIFO_Print(&UART_FIFO);
    if (FIFO_Dequeue(&UART_FIFO, &temp) == FIFO_OK)
        printf("\t dequeued successfully");
    
    printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
    FIFO_Print(&UART_FIFO);

    return 0;
}