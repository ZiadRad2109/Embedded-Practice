/******************************************************************************
 *
 *
 * Project: E-Bike - Dashboard
 *
 * File Name: STM32F103X8.h
 *
 * Description: Header file for STM32F1 series registers
 *
 * Author: Ziad Hisham
 ******************************************************************************/
#ifndef STM32F103X8_H_
#define STM32F103X8_H_
/******************************************************************************
 *
 * Includes
 *
 ******************************************************************************/
#include "Platform_Types.h"

/******************************************************************************
 *
 * Base addresses for memory
 *
 ******************************************************************************/
#define FLASH_Memory_BASE 0x08000000UL
#define System_Memory_BASE 0x1FFFF000UL
#define SRAM_BASE 0x20000000UL

/******************************************************************************
 *
 * Base addresses for BUS peripherals
 *
 ******************************************************************************/
#define Peripherals_BASE 0x40000000UL
#define Cortex_M3_Internal_Peripherals_BASE 0xE0000000UL

/******************************************************************************
 *
 * Base addresses for Private Peripheral Bus PPB
 *
 ******************************************************************************/
#define NVIC_BASE (0xE000E100UL)
#define NVIC_ISER0 *(vuint32 *)(NVIC_BASE + 0x00)
#define NVIC_ISER1 *(vuint32 *)(NVIC_BASE + 0x04)
#define NVIC_ISER2 *(vuint32 *)(NVIC_BASE + 0x08)
#define NVIC_ICER0 *(vuint32 *)(NVIC_BASE + 0x80)
#define NVIC_ICER1 *(vuint32 *)(NVIC_BASE + 0x84)
#define NVIC_ICER2 *(vuint32 *)(NVIC_BASE + 0x88)

//----------------------------
// Base addresses fro AHB peripherals
//----------------------------
#define RCC_BASE (Peripherals_BASE + 0x00021000UL)

//----------------------------
// Base addresses fro APB1 peripherals (to be updated)
//----------------------------
//  UsART 2 and 3
#define USART2_BASE (Peripherals_BASE + 0x00004400UL)
#define USART3_BASE (Peripherals_BASE + 0x00004800UL)

//----------------------------
// Base addresses fro APB2 peripherals (to be updated)
//----------------------------
//  GPIO
//  PORT A and B Fully included
#define GPIOA_BASE (Peripherals_BASE + 0x00010800UL)
#define GPIOB_BASE (Peripherals_BASE + 0x00010C00UL)

//  PORT C and D partially included
#define GPIOC_BASE (Peripherals_BASE + 0x00011000UL)
#define GPIOD_BASE (Peripherals_BASE + 0x00011400UL)

//  Alternate Function
#define AFIO_BASE (Peripherals_BASE + 0x00010000UL)

//  external Interrupt
#define EXTI_BASE (Peripherals_BASE + 0x00010400UL)

//  UART
//  USART1
#define USART1_BASE (Peripherals_BASE + 0x00013800UL)

/******************************************************************************
 *
 * RCC Peripheral register
 *
 ******************************************************************************/
typedef struct
{
    vuint32 CR;       // clock Control
    vuint32 CFGR;     // Clock configuration Register
    vuint32 CIR;      // clock interrupt register
    vuint32 APB2RSTR; // APB2 peripheral reset
    vuint32 APB1RSTR; // APB1 peripherhal reset
    vuint32 AHBENR;   // AHB peripheral clock enable
    vuint32 APB2ENR;  // APB2 peripheral clock enable
    vuint32 APB1ENR;  // APB1 peripheral clock enable
    vuint32 BDCR;     // backup domain control register
    vuint32 CSR;      // control/status register
    vuint32 AHBRSTR;  // AHB peripheral clock reset register
    vuint32 CFGR2;    // clock configuration register 2

} RCC_TypeDef;
/******************************************************************************
 *
 * GPIO Peripheral register
 *
 ******************************************************************************/
typedef struct
{
    vuint32 CRL;  // configuration Low
    vuint32 CRH;  // configuration High
    vuint32 IDR;  // Data In
    vuint32 ODR;  // Data out
    vuint32 BSRR; // Set/reset
    vuint32 BRR;  // reset
    vuint32 LCKR; // Locking

} GPIO_TypeDef;

/******************************************************************************
 *
 * AFIO Peripheral register
 *
 ******************************************************************************/
typedef struct
{
    vuint32 EVCR;    // event control register
    vuint32 MAPR;    // remap and debug
    vuint32 EXTICR1; // external interrupt controllers
    vuint32 EXTICR2;
    vuint32 EXTICR3;
    vuint32 EXTICR4;
    uint32 RESERVERD;
    vuint32 MAPR2;
} AFIO_TypeDef;

/******************************************************************************
 *
 * EXTI Peripheral register
 *
 ******************************************************************************/
typedef struct
{
    vuint32 IMR; // interrupt mask register
    vuint32 EMR;
    vuint32 RTSR;
    vuint32 FTSR;
    vuint32 SWIER;
    vuint32 PR;
} EXTI_TypeDef;

/******************************************************************************
 *
 * USART Peripheral register
 *
 ******************************************************************************/
typedef struct
{

    // increment by 4 bytes
    // 7 registers
    vuint32 SR; // status register

    vuint32 DR; // Data Register

    vuint32 BRR; // BaudRate register

    vuint32 CR1; // control register 1

    vuint32 CR2; // control register 2

    vuint32 CR3; // control register 3

    vuint32 GTPR; // guard time and prescaler register

} USART_TypeDef;

/******************************************************************************
 *
 * Peripheral instances
 *
 ******************************************************************************/
/* GPIO */

GPIO_TypeDef *GPIOA = (GPIO_TypeDef *)GPIOA_BASE; // declare gpio

GPIO_TypeDef *GPIOB = (GPIO_TypeDef *)GPIOB_BASE; // declare gpio

GPIO_TypeDef *GPIOC = (GPIO_TypeDef *)GPIOC_BASE; // declare gpio

GPIO_TypeDef *GPIOD = (GPIO_TypeDef *)GPIOD_BASE; // declare gpio

/* USART */
#define USART1 ((USART_TypeDef *)(USART1_BASE))
#define USART2 ((USART_TypeDef *)(USART2_BASE))
#define USART3 ((USART_TypeDef *)(USART3_BASE))

/* RCC */

RCC_TypeDef *RCC = ((RCC_TypeDef *)(RCC_BASE));
#define RCC_APB2RSTR (uint32 *)(RCC_BASE + 0x00CUL) // peripheral reset register
#define RCC_APB1RSTR (uint32 *)(RCC_BASE + 0x010UL) // peripheral reset register

/******************************************************************************
 *
 * NVIC Vector Table IDs
 *
 ******************************************************************************/
/* USART */
#define USART1_IRQ 37u
#define USART2_IRQ 38u
#define USART3_IRQ 39u

/******************************************************************************
 *
 * Magic Function Macros
 *
 ******************************************************************************/
/* For interrupt enable and disable */
#define NVIC_IRQ37_USART1_Enable (NVIC_ISER1 |= 1 << (USART1_IRQ - 32)) // set enable
#define NVIC_IRQ38_USART2_Enable (NVIC_ICER1 |= 1 << (USART2_IRQ - 32))
#define NVIC_IRQ39_USART3_Enable (NVIC_ISER1 |= 1 << (USART3_IRQ - 32))

#define NVIC_IRQ37_USART1_Disable (NVIC_ICER1 |= 1 << (USART1_IRQ - 32)) // clear enable
#define NVIC_IRQ38_USART2_Disable (NVIC_ICER1 |= 1 << (USART2_IRQ - 32))
#define NVIC_IRQ39_USART3_Disable (NVIC_ICER1 |= 1 << (USART3_IRQ - 32))

/* Clock Enable */
#define RCC_GPIOA_CLK_EN() (RCC->APB2ENR |= 1 << 2)
#define RCC_GPIOB_CLK_EN() (RCC->APB2ENR |= 1 << 3)

#define RCC_AFIO_CLK_EN() (RCC->APB2ENR |= 1 << 0)

#define RCC_USART1_CLK_EN() (RCC->APB2ENR |= 1 << 14)
#define RCC_USART2_CLK_EN() (RCC->APB1ENR |= 1 << 17)
#define RCC_USART3_CLK_EN() (RCC->APB1ENR |= 1 << 18)

/* clock reset */
#define RCC_GPIOA_CLK_Reset() (RCC->APB2RSTR |= 1 << 2)
#define RCC_GPIOB_CLK_Reset() (RCC->APB2RSTR |= 1 << 3)

#define RCC_AFIO_CLK_Reset() (RCC->APB2RSTR |= 1 << 0)

#define RCC_USART1_CLK_Reset() (RCC->APB2RSTR |= 1 << 14)
#define RCC_USART2_CLK_Reset() (RCC->APB2RSTR |= 1 << 17)
#define RCC_USART3_CLK_Reset() (RCC->APB2RSTR |= 1 << 18)

#endif // !STM32F103X8_H_