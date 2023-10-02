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

#ifndef STM32F103X8_UART_DRIVER_H
#define STM32F103X8_UART_DRIVER_H
/******************************************************************************
 *
 * Includes
 *
 ******************************************************************************/
#include "STM32F103X8.h"
#include "Platform_Types.h"
#include "STM32F103X8_GPIO_DRIVER.h"
#include "STM32F103X8_RCC_DRIVER.h"
#include "Common_Macros.h"

/******************************************************************************
 *
 * User type definitions
 *
 ******************************************************************************/
typedef struct
{

    /* parameter set based on @ref USART_MODE_Define */
    uint8 USART_MODE; //(TX/RX) (EN/Disable)

    /* parameter set based on @ref USART_BAUDRATE_Define */
    uint32 Baud_Rate; // configures baud rate

    /* parameter set based on @ref USART_PAYLOAD_Define*/
    uint8 Payload_Length; // specifies the number of data bits to be transcieved

    /* parameter set based on @ref USART_PARITY_Define*/
    uint8 Parity; // to enable parity check and type

    /* parameter set based on @ref USART_SBITS_Define*/
    uint8 Stop_Bits; // configures stop bits

    /* parameter set based on @ref USART_FLOWCTL_Define*/
    uint8 HwFlowCtl; // enables Flow control (CTS,RTS)

    /* parameter set based on @ref USART_IRQ_Define*/
    uint8 IRQ_Enable; // enables interrupts on tx and rx

    void (*p_IRQ_Callback)(void); // Callback function that is called at interrupt trigger

} USART_CONFIG;

/* Polling activation */
enum POLLING_ENABLE{
    Enable,
    Disable
};

/******************************************************************************
 *
 * MACROS for Configuration
 *
 ******************************************************************************/

//@ref USART_MODE_Define
#define USART_MODE_RX (uint32)(1 << 2)
#define USART_MODE_TX (uint32)(1 << 3)
#define USART_MODE_TX_RX (uint32)((1 << 2) | (1 << 3))

//@ref USART_BAUDRATE_Define
#define USART_BaudRate_9600 (9600u)
#define USART_BaudRate_115200 (115200u)
#define USARTDIV(_PCLCK_,_BAUD_) (uint32)(_PCLCK_/16*_BAUD_)
#define USARTDIV_MUL100(_PCLCK_,_BAUD_) (uint32)((25*_PCLCK_)/(4*_BAUD_)) //for integer implicit typecasting
#define Mantissa(_PCLCK_,_BAUD_) (uint32)(USARTDIV(_PCLCK_,_BAUD_))
#define Mantissa_MUL100(_PCLCK_,_BAUD_) (uint32)(USARTDIV(_PCLCK_,_BAUD_)*100)
#define DIV_Fraction(_PCLCK_,_BAUD_)  (uint32)((USARTDIV_MUL100(_PCLCK_,_BAUD_))-(Mantissa_MUL100(_PCLCK_,_BAUD_)))
#define USART_BRR_Register_Set(_PCLCK_,_BAUD_) (uint32)((Mantissa(_PCLCK_,_BAUD_)<<4)|(DIV_Fraction(_PCLCK_,_BAUD_)&0xf))

//@ref USART_PAYLOAD_Define
#define USART_PAYLOAD_8B (uint32)(0 << 12) // M bit ins CR1 bit 12
#define USART_PAYLOAD_9B (uint32)(1 << 12) // M bit ins CR1 bit 12

//@ref USART_PARITY_Define
#define USART_PARITY_NONE (uint32)(0 << 10) // parity control enable PCE
#define USART_PARITY_EVEN (uint32)(1 << 10)
#define USART_PARITY_ODD (uint32)((1 << 10) | (1 << 9)) // PS parity selection bit

//@ref USART_SBITS_Define
#define USART_STOP_BITS_ONE (uint32)(0 << 12) // STOP in CR2
#define USART_STOP_BITS_HALF (uint32)(1 << 12)
#define USART_STOP_BITS_ONEHALF (uint32)(3 << 12)
#define USART_STOP_BITS_TWO (uint32)(2 << 12)

//@ref USART_FLOWCTL_Define
#define USART_HwFlowCTL_NONE (uint32)(0)
#define USART_HwFlow_CTL_CTS (uint32)(1 << 9) // CTSE in CR3
#define USART_HwFlow_CTL_RTS (uint32)(1 << 8) // RTSE
#define USART_HwFlow_CTL_CTS_RTS (uint32)((1 << 9) | (1 << 8))

//@ref USART_IRQ_Define
//CR1
#define USART_IRQ_Enable_NONE (uint32)(0)
#define USART_IRQ_Enable_TXE (uint32)(1<<7) //TXEIE transmit data register empty
#define USART_IRQ_Enable_TC (uint32)(1<<6) //transmission complete
#define USART_IRQ_Enable_RXNEIE (uint32)(1<<5) //Received data not empty interrupt enable
#define USART_IRQ_Enable_PE (uint32)(1<<8) //Parity error



/******************************************************************************
 *
 * APIs
 *
 ******************************************************************************/

void MCAL_USART_Init(USART_TypeDef* USARTx, USART_CONFIG* USART_cfg);

void MCAL_USART_DeInit(USART_TypeDef* USARTx);

void MCAL_USART_GPIO_Set_Pins(USART_TypeDef* USARTx);

void MCAL_USART_SendData(USART_TypeDef* USARTx, USART_Buffer_t pTx_Buffer, enum POLLING_ENABLE Poll_EN);

void MCAL_USART_ReceiveData(USART_TypeDef* USARTx, USART_Buffer_t pRx_Buffer, enum POLLING_ENABLE Poll_EN);

void MCAL_USART_WAIT_TC(USART_TypeDef* USARTx);
#endif // !STM32F103X8_UART_DRIVER_H