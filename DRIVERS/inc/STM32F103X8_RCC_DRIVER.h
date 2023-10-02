/******************************************************************************
 *
 * Module: RCC
 *
 * Project: E-Bike - Dashboard
 *
 * File Name: STM32F103X8_RCC_DRIVER.h
 *
 * Description: Header file - RCC Driver
 *
 * Author: Ziad Hisham
 ******************************************************************************/

#ifndef STM32F103X8_RCC_DRIVER_H
#define STM32F103X8_RCC_DRIVER_H
/******************************************************************************
 *
 * Includes
 *
 ******************************************************************************/
#include "STM32F103X8.h"
#include "Platform_Types.h"
#include "STM32F103X8_GPIO_DRIVER.h"


/******************************************************************************
 *
 * MACROS for Configuration
 *
 ******************************************************************************/

#define HSE_CLOCK (uint32)(16000000) // 16MHz external clock
#define HSI_RC_CLOCK (uint32)(8000000) // 8MHz Internal clock


/******************************************************************************
 *
 * RCC APIs
 *
 ******************************************************************************/
Std_ReturnType MCAL_RCC_Get_SYSCLK_Freq(void); // Function to get system clock frequency -> depends on HSI and PLL

Std_ReturnType MCAL_RCC_Get_PCLCK1_Freq(void); // peripheral clock for APB1

Std_ReturnType MCAL_RCC_Get_PCLCK2_Freq(void); // peripheral clock for APB2

Std_ReturnType MCAL_RCC_Get_HCLCK_Freq(void); // clock for AHB ->depends on SYSCLCK







#endif // !STM32F103X8_RCC_DRIVER_H