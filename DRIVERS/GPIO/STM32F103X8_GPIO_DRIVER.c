/******************************************************************************
 *
 * Module: GPIO
 *
 * Project: E-Bike - Dashboard
 *
 * File Name: STM32F103X8_GPIO_DRIVER.c
 *
 * Description: Source file   - Dio Driver
 *
 * Author: Ziad Hisham
 ******************************************************************************/

/******************************************************************************
 *
 * Includes
 *
 ******************************************************************************/
#include "STM32F103X8_GPIO_DRIVER.h"
#include "Common_Macros.h"

/**================================================================
 * @Fn-              MCAL_GPIO_Init
 * @brief -          Initializes the GPIOx PINy according to the specified parameters in the PinConfig
 * @param [in] -     GPIOx: where x is from A -> E depending on the device to select the gpio peripheral
 * @param [in] -     PinConfig pointer to a GPIO_PinConfig)T struct that contains the configuration information for a specified pin
 * @retval -         void
 * Note-             stm32f103C6 MCU has GPIO A ->E but LQFP48 Package has only A and B and part of C and D exported as external pins from the MCU
 */

/* FUnction to get range of bits needed for pin configuration @ref GPIO_RETURN_TYPE*/
PinRange_Position_t Get_CRLH_Range_Position(uint16 PinNumber)
{
    switch (PinNumber)
    {
    case GPIO_PIN_0:
        return 0;
        break;

    case GPIO_PIN_1:
        return 4;
        break;
    case GPIO_PIN_2:
        return 8;
        break;
    case GPIO_PIN_3:
        return 12;
        break;
    case GPIO_PIN_4:
        return 16;
        break;
    case GPIO_PIN_5:
        return 20;
        break;
    case GPIO_PIN_6:
        return 24;
        break;
    case GPIO_PIN_7:
        return 28;
        break;
    case GPIO_PIN_8:
        return 0;
        break;

    case GPIO_PIN_9:
        return 4;
        break;
    case GPIO_PIN_10:
        return 8;
        break;
    case GPIO_PIN_11:
        return 12;
        break;
    case GPIO_PIN_12:
        return 16;
        break;
    case GPIO_PIN_13:
        return 20;
        break;
    case GPIO_PIN_14:
        return 24;
        break;
    case GPIO_PIN_15:
        return 28;
        break;
    default:
        return 0;
    }
}

void MCAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_TypeDef *PinConfig)
{
    // CRL & CRH write
    // CRL (Port configuration Low) configures pins 0 -> 7 (GPIOx_CRL)
    // CRH 8->15
    vuint32 *ConfigReg = NULL;
    uint8 PIN_CFG = 0;

    // choose crl or crh according to pin number
    ConfigReg = (PinConfig->GPIO_PinNumber < GPIO_PIN_8) ? &GPIOx->CRL : &GPIOx->CRH;

    // each bit has 2 bits for direction(MODEy) and 2 bits for configuration (CNFy)
    // so we need to find the position for each bit (1 =  0,1,2,3 & 2 = 4,5,6,7)
    // use function (get position function defined previously)

    // clear MODE & CNF bits
    (*ConfigReg) &= ~(0x0f << Get_CRLH_Range_Position(PinConfig->GPIO_PinNumber));

    // check direction
    /* if pin is output */
    if ((PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP) || (PinConfig->GPIO_MODE == GPIO_MODE_AF_OD) || (PinConfig->GPIO_MODE == GPIO_MODE_AF_PP))
    {
        // set CNF values
        // we defined macros that need to be decremented by 4 to align with the datasheet
        // this number is then leftshifted by 2 to bypass the MODEy bits
        // ored with the corresponding speed
        // then anded with 0x0f because we only need the first 4 bits of that number
        PIN_CFG = ((((PinConfig->GPIO_MODE - 4) << 2) | (PinConfig->GPIO_Output_Speed)) & 0x0f);
    }
    else // if input
    {
        // if floating or analog
        if ((PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLO) || (PinConfig->GPIO_MODE == GPIO_MODE_ANALOG))
        {
            PIN_CFG = ((((PinConfig->GPIO_MODE) << 2) | 0x0) & 0x0f);
        }
        else if (PinConfig->GPIO_MODE == GPIO_MODE_AF_INPUT) // consider input as floating
        {
            PIN_CFG = ((((GPIO_MODE_INPUT_FLO) << 2) | 0x0) & 0x0f);
        }
        else
        {
            // pull up or down
            PIN_CFG = ((((GPIO_MODE_INPUT_PU) << 2) | 0x0) & 0x0f); // init
            if (PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU)         // if pull up
            {
                // PxODR 1 port bit configuration table
                GPIOx->ODR |= PinConfig->GPIO_PinNumber;
            }
            else // pull down
            {
                GPIOx->ODR &=~(PinConfig->GPIO_PinNumber);
            }
        }
    }
    (*ConfigReg) |= (PIN_CFG << Get_CRLH_Range_Position(PinConfig->GPIO_PinNumber));
}

/**================================================================
 * @Fn-             MCAL_GPIO_DeInit
 * @brief -         Reset all GPIO Registers
 * @param [in] -    GPIOx: where x is from A -> E depending on the device to select the gpio peripheral
 * @param [out] -   void
 * @retval -        void
 * Note- none
 */
void MCAL_GPIO_DeInit(GPIO_TypeDef *GPIOx)
{
    // datasheet register reset value (without reset controller)
    // Gpiox ->BRR = 0x00000000;
    // Gpiox ->BSRR = 0x0000000;
    // Gpiox ->CRH = 0x44444444;
    // Gpiox ->CRL = 0x44444444;
    // Gpiox ->LCKR = 0x00000000;
    // Gpiox ->ODR = 0x00000000;

    /*==========================OR=================================*/

    // APB2 reset register
    // set and then reset bits according to peripheral

    if (GPIOx == GPIOA)
    {
        
        SET_BIT(*RCC_APB2RSTR, 2);
        CLEAR_BIT(*RCC_APB2RSTR, 2);
    }

    else if (GPIOx == GPIOB)
    {
        SET_BIT(*RCC_APB2RSTR, 3);
        CLEAR_BIT(*RCC_APB2RSTR, 3);
    }
    else if (GPIOx == GPIOC)
    {
        SET_BIT(*RCC_APB2RSTR, 4);
        CLEAR_BIT(*RCC_APB2RSTR, 4);
    }
    else
    {
        // D
        SET_BIT(*RCC_APB2RSTR, 5);
        CLEAR_BIT(*RCC_APB2RSTR, 5);
    }
}

/**================================================================
 * @Fn-             MCAL_GPIO_ReadPin
 * @brief -         Reads a specific pin Level
 * @param [in] -    GPIOx: where x is from A -> E depending on the device to select the gpio peripheral
 * @param [in] -    Pin Number
 * @retval -        input pin level based on @ref GPIO_RETURN_TYPE
 * Note-    none
 */
GPIO_Level MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16 PinNumber)
{
    uint8 BitLevel = 0;
    if (((GPIOx->IDR) & PinNumber) != STD_LOW)
    {
        BitLevel = STD_HIGH;
    }
    else
    {
        BitLevel = STD_LOW;
    }
    return BitLevel;
}

/**================================================================
 * @Fn-             MCAL_GPIO_ReadPort
 * @brief -         Reads port data
 * @param [in] -    GPIOx: where x is from A -> E depending on the device to select the gpio peripheral
 * @param [out] -   void
 * @retval -        Port data uint16 @ref GPIO_RETURN_TYPE
 * Note- none
 */
GPIO_PortValue_t MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx)
{
    uint16 PortValue = 0;
    PortValue = (GPIO_PortValue_t)(GPIOx->IDR);
    return PortValue;
}

/**================================================================
 * @Fn-             MCAL_GPIO_WritePin
 * @brief -         Write pin level to a specific pin
 * @param [in] -    GPIOx: where x is from A -> E depending on the device to select the gpio peripheral
 * @param [in] -    PinNumber
 * @param [in] -    Level (H or L)
 * @retval - none
 * Note- none
 */
void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16 PinNumber, uint8 Level)
{
    if (Level != (Std_ReturnType)GPIO_PIN_RESET)
    {
        // set High
        // use BSRR register
        GPIOx->BSRR = (Std_ReturnType)PinNumber;
    }
    else
    {
        // BRR reset register
        GPIOx->BRR = (Std_ReturnType)PinNumber;
    }
}

/**================================================================
 * @Fn-             MCAL_GPIO_WritePort
 * @brief -         Writes value to port
 * @param [in] -    GPIOx: where x is from A -> E depending on the device to select the gpio peripheral
 * @param [in] -    Value to be assigned to Port
 * @retval -    void
 * Note-    none
 */
void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx, uint16 Value)
{
    GPIOx->ODR = (Std_ReturnType)Value;
}

/**================================================================
 * @Fn-             MCAL_GPIO_TogglePin
 * @brief -         Toggles a specific pin
 * @param [in] -    GPIOx: where x is from A -> E depending on the device to select the gpio peripheral
 * @param [in] -    Pin Number to be toggled
 * @retval -    void
 * Note-    none
 */
void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16 PinNumber)
{
    TOGGLE_BIT(GPIOx->ODR, (Std_ReturnType)PinNumber);
}

/**================================================================
 * @Fn-             MCAL_GPIO_LOCKPin
 * @brief -         Locks CRL and CRH bits for a specific pin
 * @param [in] -    GPIOx: where x is from A -> E depending on the device to select the gpio peripheral
 * @param [in] -    Pin Number to be toggled
 * @retval -        Level ok or error
 * Note- none
 */
GPIO_Level MCAL_GPIO_LOCKPin(GPIO_TypeDef *GPIOx, uint16 PinNumber)
{
    vuint32 temp = 1 << 16; // LCKK =1
    // set LCKy to be locked

    temp |= PinNumber;
    // write 1
    GPIOx->LCKR = temp;

    // write 0
    GPIOx->LCKR = PinNumber;

    // write 1
    GPIOx->LCKR = temp;

    // read 0
    temp = GPIOx->LCKR;

    // read 1
    if ((Std_ReturnType)(GPIOx->LCKR & 1 << 16))
    {
        return GPIO_LOCK_OK;
    }
    else
    {
        return GPIO_LOCK_ERROR;
    }
}