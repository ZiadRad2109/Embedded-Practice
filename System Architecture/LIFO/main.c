/*
    Author: Ziad Hisham
    Driver: LIFO
    Source File: main.c
*/

#include "lifo.h"

// test buffers
ELEMENT_TYPE buffer1[LENGTH];
ELEMENT_TYPE buffer2[LENGTH];

int main(void)
{
    uint8 temp = 0, i;

    // declare LIFO buffers
    LIFO_Buffer_t uart_lifo, I2C_lifo;

    // For static allocation
    LIFO_init(&uart_lifo, buffer1, LENGTH);

    // for dynamic allocation
    ELEMENT_TYPE *buffer2 = (ELEMENT_TYPE *)malloc(LENGTH * sizeof(ELEMENT_TYPE));
    LIFO_init(&I2C_lifo, buffer2, LENGTH);

    // push
    for (i = 0; i < LENGTH; i++)
    {
        // check if LIFO is not FULL and available

        if (LIFO_Push(&uart_lifo, i) == LIFO_OK)
        {
            printf("data added to stack : %d", i);
        }
    }
    
    //pop
    for (i = 0; i < LENGTH; i++)
    {
        // check if LIFO is not empty and available

        if (LIFO_Pop(&uart_lifo, &temp) == LIFO_OK)
        {
            printf("data received from stack : %d", i);
        }
    }
    
    return 0;
}