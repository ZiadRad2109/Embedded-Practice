/******************************************************************************
 *
 * Module: GPIO
 *
 * Project: E-Bike - Dashboard
 *
 * File Name: STM32F103X8_GPIO_DRIVER.h
 *
 * Description: Header file - GPIO Driver
 *
 * Author: Ziad Hisham
 ******************************************************************************/

#ifndef STM32F103X8_GPIO_DRIVER_H
#define STM32F103X8_GPIO_DRIVER_H
/******************************************************************************
 *
 * Includes
 *
 ******************************************************************************/
#include "STM32F103X8.h"
#include "Platform_Types.h"

/******************************************************************************
 *
 * User type definitions
 *
 ******************************************************************************/
typedef struct
{
    uint8 GPIO_PinNumber; // specifies the gpio pin to be configured
                          // this parameter is defined @ref GPIO_PINS_define

    uint8 GPIO_MODE; // specifies the opertating mode of the pin
                     // this parameter is defined @ref GPIO_MODE_define

    uint8 GPIO_Output_Speed; // specifies the speed of the pin
                             // this parameter is defined @ref GPIO_SPEED_define

} GPIO_PinConfig_TypeDef;

/******************************************************************************
 *
 * MACROS for Configuration
 *
 ******************************************************************************/
/*
    @ref GPIO_MODE_define
    0:  Analog
    1:  Floating
    2:  Pull-up input
    3:  pull-down input
    4:  push-pull output
    5:  open-drain output
    6:  AF push-pull output
    7:  AF open-drain output
    8:  AF input

*/
#define GPIO_MODE_ANALOG 0x00000000u
#define GPIO_MODE_INPUT_FLO 0x00000001u
#define GPIO_MODE_INPUT_PU 0x00000002u
#define GPIO_MODE_INPUT_PD 0x00000003u
#define GPIO_MODE_OUTPUT_PP 0x00000004u
#define GPIO_MODE_OUTPUT_OD 0x00000005u
#define GPIO_MODE_AF_PP 0x00000006u
#define GPIO_MODE_AF_OD 0x00000007u
#define GPIO_MODE_AF_INPUT 0x00000008u

//@ref GPIO_PINS_define
#define GPIO_PIN_0 ((uint16)0x0001u)
#define GPIO_PIN_1 ((uint16)0x0002u)
#define GPIO_PIN_2 ((uint16)0x0004u)
#define GPIO_PIN_3 ((uint16)0x0008u)
#define GPIO_PIN_4 ((uint16)0x0010u)
#define GPIO_PIN_5 ((uint16)0x0020u)
#define GPIO_PIN_6 ((uint16)0x0040u)
#define GPIO_PIN_7 ((uint16)0x0080u)
#define GPIO_PIN_8 ((uint16)0x0100u)
#define GPIO_PIN_9 ((uint16)0x0200u)
#define GPIO_PIN_10 ((uint16)0x0400u)
#define GPIO_PIN_11 ((uint16)0x0800u)
#define GPIO_PIN_12 ((uint16)0x1000u)
#define GPIO_PIN_13 ((uint16)0x2000u)
#define GPIO_PIN_14 ((uint16)0x4000u)
#define GPIO_PIN_15 ((uint16)0x8000u)
#define GPIO_PIN_ALL ((uint16)0xffffu)

#define GPIO_PIN_MASK ((uint16)0x0000ffffu) // for assert test

/*
    @ref GPIO_SPEED_define
    1: 10MHz
    2: 2MHz
    3: 50MHz
*/
#define GPIO_SPEED_10MHZ 0x00000001u
#define GPIO_SPEED_02MHz 0x00000002u
#define GPIO_SPEED_50MHz 0x00000003u

//@ref GPIO_PIN_LEVEL
#define GPIO_PIN_SET 0x00000001u
#define GPIO_PIN_RESET 0x00000000u

//@ref GPIO_IS_LOCK
#define GPIO_LOCK_OK 0x00000001u
#define GPIO_LOCK_ERROR 0x00000000u

//@ref GPIO_RETURN_TYPE
typedef uint8 PinRange_Position_t;
typedef uint16 GPIO_PortValue_t;
typedef uint8 GPIO_Level;

//@ref USART_BUFFER_TYPE
typedef uint16* USART_Buffer_t;

/******************************************************************************
 *
 * APIs
 *
 ******************************************************************************/
/* FUnction to get range of bits needed for pin configuration @ref GPIO_RETURN_TYPE*/
PinRange_Position_t Get_CRLH_Range_Position(uint16 PinNumber);

void MCAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_TypeDef *PinConfig);

void MCAL_GPIO_DeInit(GPIO_TypeDef *GPIOx);

GPIO_Level MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16 PinNumber);

GPIO_PortValue_t MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx);

void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16 PinNumber, uint8 Level);

void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx, uint16 Value);

void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16 PinNumber);

GPIO_Level MCAL_GPIO_LOCKPin(GPIO_TypeDef *GPIOx, uint16 PinNumber);

#endif // !STM32F103X8_GPIO_DRIVER_H
