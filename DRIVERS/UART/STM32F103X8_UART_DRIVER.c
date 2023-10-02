/******************************************************************************
 *
 * Module: UART
 *
 * Project: E-Bike - Dashboard
 *
 * File Name: STM32F103X8_UART_DRIVER.h
 *
 * Description: Header file - UART Driver
 *
 * Author: Ziad Hisham
 ******************************************************************************/

/******************************************************************************
 *
 * Includes
 *
 ******************************************************************************/
#include "STM32F103X8_UART_DRIVER.h"

/******************************************************************************
 *
 * GLobal variables
 *
 ******************************************************************************/
USART_CONFIG *g_USART_CFG = NULL; // usart configuration initialization

/******************************************************************************
 *
 * APIs
 *
 ******************************************************************************/

/**================================================================
 * @Fn-             MCAL_USART_Init
 * @brief -         Initializes USART instance
 * @param [in] -    USARTx where x is 1,2,3 (instance)
 * @param [in] -    USART_cfg , configuration strcture
 * @retval -        void
 * Note- none
 */
void MCAL_USART_Init(USART_TypeDef *USARTx, USART_CONFIG *USART_cfg)
{

    // define global configuration to be used in all apis
    g_USART_CFG = USART_cfg;

    Std_ReturnType PCLCK, BRR; // for baud rate calculation

    // check which usart instance is used
    // enable peripheral clock
    // enable usart module

    if (USARTx == USART1)
    {
        RCC_USART1_CLK_EN();
    }
    else if (USARTx == USART2)
    {
        RCC_USART2_CLK_EN();
    }
    else
    {
        RCC_USART3_CLK_EN();
    }

    SET_BIT(USARTx->CR1, 13); // USART Enable

    // choose mode
    USARTx->CR1 |= USART_cfg->USART_MODE;

    // set payload length
    USARTx->CR1 |= USART_cfg->Payload_Length;

    // parity
    USARTx->CR1 |= USART_cfg->Parity;

    // Stop Bits
    USARTx->CR2 |= USART_cfg->Stop_Bits;

    // Flow Control
    USARTx->CR3 |= USART_cfg->HwFlowCtl;

    /* Configuration for Baud Rate
        NOTE:
            PCLCK1 for USART 2,3
            PCLCK2 for USART 1 --->
    */
    if (USARTx == USART1)
    {
        PCLCK = MCAL_RCC_Get_PCLCK2_Freq();
    }
    else
    {
        PCLCK = MCAL_RCC_Get_PCLCK1_Freq();
    }

    // set baud rate register
    BRR = USART_BRR_Register_Set(PCLCK, USART_cfg->Baud_Rate);
    USARTx->BRR = BRR;

    // enable / disable interrupts
    if (USART_cfg->IRQ_Enable != USART_IRQ_Enable_NONE)
    {
        // if enabled
        USARTx->CR1 |= USART_cfg->IRQ_Enable;

        // enable NVIC for UART IRQ
        if (USARTx == USART1)
        {
            NVIC_IRQ37_USART1_Enable;
        }
        else if (USARTx == USART2)
        {
            NVIC_IRQ38_USART2_Enable;
        }
        else
        {
            NVIC_IRQ39_USART3_Enable;
        }
    }
    else
    {

        USARTx->CR1 &= ~(USART_cfg->IRQ_Enable);
        NVIC_IRQ37_USART1_Disable;
        NVIC_IRQ38_USART2_Disable;
        NVIC_IRQ39_USART3_Disable;
    }
}

/**================================================================
 * @Fn-             MCAL_USART_DeInit
 * @brief -         De-initializes USART instance
 * @param [in] -    USARTx where x is 1,2,3 (instance)
 * @retval -        void
 * Note- none
 */
void MCAL_USART_DeInit(USART_TypeDef *USARTx)
{
    if (USARTx == USART1)
    {
        RCC_USART1_CLK_Reset();
        NVIC_IRQ37_USART1_Disable;
    }
    else if (USARTx == USART2)
    {
        RCC_USART2_CLK_Reset();
        NVIC_IRQ38_USART2_Disable;
    }
    else
    {
        RCC_USART3_CLK_Reset();
        NVIC_IRQ39_USART3_Disable;
    }
}

/**================================================================
 * @Fn-             MCAL_USART_GPIO_Set_Pins
 * @brief -         set gpio alternate functions
 * @param [in] -    USARTx where x is 1,2,3 (instance)
 * @retval -        void
 * Note- none
 */
void MCAL_USART_GPIO_Set_Pins(USART_TypeDef *USARTx)
{
    // check recommended settings in page 167 (alternate functions)
    //  TX --> AF_PP
    // gpio pin configuration
    GPIO_PinConfig_TypeDef PinCfg;
    /* AFIO_MAPR remap register*/
    if (USARTx == USART1)
    {
        // PA9 Tx
        // PA10 Rx

        PinCfg.GPIO_PinNumber = GPIO_PIN_9;
        PinCfg.GPIO_MODE = GPIO_MODE_AF_PP;
        PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
        MCAL_GPIO_Init(GPIOA, &PinCfg);

        PinCfg.GPIO_PinNumber = GPIO_PIN_10;
        PinCfg.GPIO_MODE = GPIO_MODE_AF_INPUT;
        MCAL_GPIO_Init(GPIOA, &PinCfg);
    }
    else if (USARTx == USART2)
    {
        // PA2 TX
        // PA3 Rx
        // PA1 RTS
        // PA0 CTS
        PinCfg.GPIO_PinNumber = GPIO_PIN_2;
        PinCfg.GPIO_MODE = GPIO_MODE_AF_PP;
        PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
        MCAL_GPIO_Init(GPIOA, &PinCfg);

        PinCfg.GPIO_PinNumber = GPIO_PIN_3;
        PinCfg.GPIO_MODE = GPIO_MODE_AF_INPUT;
        MCAL_GPIO_Init(GPIOA, &PinCfg);

        PinCfg.GPIO_PinNumber = GPIO_PIN_1;
        PinCfg.GPIO_MODE = GPIO_MODE_AF_PP;
        PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
        MCAL_GPIO_Init(GPIOA, &PinCfg);

        PinCfg.GPIO_PinNumber = GPIO_PIN_0;
        PinCfg.GPIO_MODE = GPIO_MODE_AF_INPUT;
        MCAL_GPIO_Init(GPIOA, &PinCfg);
    }
    else
    {
        // PB10 TX
        // PB11 Rx
        // PB14 RTS
        // PB13 CTS
        PinCfg.GPIO_PinNumber = GPIO_PIN_10;
        PinCfg.GPIO_MODE = GPIO_MODE_AF_PP;
        PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
        MCAL_GPIO_Init(GPIOB, &PinCfg);

        PinCfg.GPIO_PinNumber = GPIO_PIN_11;
        PinCfg.GPIO_MODE = GPIO_MODE_AF_INPUT;
        MCAL_GPIO_Init(GPIOB, &PinCfg);

        PinCfg.GPIO_PinNumber = GPIO_PIN_14;
        PinCfg.GPIO_MODE = GPIO_MODE_AF_PP;
        PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
        MCAL_GPIO_Init(GPIOB, &PinCfg);

        PinCfg.GPIO_PinNumber = GPIO_PIN_13;
        PinCfg.GPIO_MODE = GPIO_MODE_AF_INPUT;
        MCAL_GPIO_Init(GPIOB, &PinCfg);
    }
}

/**================================================================
 * @Fn-             MCAL_USART_SendData
 * @brief -         Send data packet and polls on data sent (if enabled) to check data register
 * @param [in] -    USARTx where x is 1,2,3 (instance)
 * @param [in] -    pTx_Buffer , sending buffer
 * @retval -        void
 * Note- none
 */
void MCAL_USART_SendData(USART_TypeDef *USARTx, USART_Buffer_t pTx_Buffer, enum POLLING_ENABLE Poll_EN)
{
    // check for polling
    if (Poll_EN == Enable)
    {
        // wait for TXE is set in the status register SR
        while (!(USARTx->SR & 1 << 7))
            ;
    }

    // check bits 8 or 9 depending on payload length
    // parity is put in MSB (9 if m=1) (8 if m = 0)
    if (g_USART_CFG->Payload_Length == USART_PAYLOAD_8B)
    {
        USARTx->DR = (*pTx_Buffer & (uint16)0x00ff);
    }
    else
    {
        USARTx->DR = (*pTx_Buffer & (uint16)0x01ff);
    }
}

/**================================================================
 * @Fn-             MCAL_USART_ReceiveData
 * @brief -         Receives data packet and polls on data received (if enabled) to check data register
 * @param [in] -    USARTx where x is 1,2,3 (instance)
 * @param [in] -    pRx_Buffer , Receiving buffer
 * @retval -        void
 * Note- none
 */
void MCAL_USART_ReceiveData(USART_TypeDef *USARTx, USART_Buffer_t pRx_Buffer, enum POLLING_ENABLE Poll_EN)
{
    // wait for RXNE flag if polling is enabled
    if (Poll_EN == Enable)
    {
        while (!(USARTx->SR & (1 << 5)))
            ;
    }
    if (g_USART_CFG->Payload_Length == USART_PAYLOAD_8B)
    {
        if (g_USART_CFG->Parity == USART_PARITY_NONE)
        {
            // all 8 bits are data
            *((uint16 *)pRx_Buffer) = USARTx->DR & ((uint8)0x0ff);
        }
        else
        {
            // only 7 bits are data
            *((uint16 *)pRx_Buffer) = USARTx->DR & ((uint8)0x07f);
        }
    }
    else
    {
        // if 9 bits
        if (g_USART_CFG->Parity == USART_PARITY_NONE)
        {
            // all 9 bits are data
            *((uint16 *)pRx_Buffer) = USARTx->DR ;
        }
        else
        {
            // only 8 bits are data
            *((uint16 *)pRx_Buffer) = USARTx->DR & ((uint8)0x0ff);
        }
    }
}

/**================================================================
 * @Fn-             MCAL_USART_WAIT_TC
 * @brief -         waits until transmission completion
 * @param [in] -    USARTx where x is 1,2,3 (instance)
 * @retval -        void
 * Note- none
 */
void MCAL_USART_WAIT_TC(USART_TypeDef *USARTx)
{
    while (!(USARTx->SR & 1 << 6))
        ; // TC bit
}

/* ISR */
static void USART1_IRQHandler(void)
{
    g_USART_CFG->p_IRQ_Callback();
}