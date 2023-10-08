/******************************************************************************
 *
 * Application to test USART module
 *
 * Project: E-Bike - Dashboard
 *
 * File Name: main.c
 *
 * Description: Source file
 *
 * Author: Ziad Hisham
 ******************************************************************************/

/******************************************************************************
 *
 * Inclusions
 *
 ******************************************************************************/
#include <stdio.h>
#include "STM32F103X8.h"
#include "STM32F103X8_RCC_DRIVER.h"
#include "STM32F103X8_GPIO_DRIVER.h"
#include "STM32F103X8_UART_DRIVER.h"

/******************************************************************************
 *
 * User definitions
 *
 ******************************************************************************/
#define F_CPU 10000000U

int main(void)
{
    uint8 test_String[10]={"test"};

    /* enable clock on APB2 peripherals */
    RCC_GPIOA_CLK_EN();
    RCC_AFIO_CLK_EN();

    /* set usart 1 configurations */
    USART_CONFIG USART_1_configuration;
    USART_1_configuration.Baud_Rate = USART_BaudRate_9600;
    USART_1_configuration.HwFlowCtl = USART_HwFlowCTL_NONE;
    USART_1_configuration.IRQ_Enable =USART_IRQ_Enable_NONE;
    USART_1_configuration.p_IRQ_Callback = NULL;
    USART_1_configuration.Parity = USART_PARITY_NONE;
    USART_1_configuration.Payload_Length = USART_PAYLOAD_8B;
    USART_1_configuration.Stop_Bits = USART_STOP_BITS_ONE;
    USART_1_configuration.USART_MODE = USART_MODE_TX;

    MCAL_USART_Init(USART1,&USART_1_configuration);
    MCAL_USART_GPIO_Set_Pins(USART1);

    while (1)
    {
        MCAL_USART_SendData(USART1,test_String,Enable);
        MCAL_USART_WAIT_TC(USART1);
    }
    


    return 0;
}
