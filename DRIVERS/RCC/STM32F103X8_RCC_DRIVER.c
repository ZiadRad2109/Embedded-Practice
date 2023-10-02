/******************************************************************************
 *
 * Module: RCC
 *
 * Project: E-Bike - Dashboard
 *
 * File Name: STM32F103X8_RCC_DRIVER.c
 *
 * Description: Source File - RCC Driver
 *
 * Author: Ziad Hisham
 ******************************************************************************/
/******************************************************************************
 *
 * Includes
 *
 ******************************************************************************/
#include "STM32F103X8_RCC_DRIVER.h"
#include "STM32F103X8.h"

/******************************************************************************
 *
 * Global Variables
 *
 ******************************************************************************/

/*NOTE:
        PPRE1 APB prescaler
        000 HCLK not divided
        100 HCLK divided by 2
        101 HCLK divided by 4
        110 HCLK divided by 8
        111 HCLK divided by 16

        HPRE AHB prescaler
        0xxx: SYSCLK not divided
        1000: SYSCLK divided by 2
        1001: SYSCLK divided by 4
        1010: SYSCLK divided by 8
        1011: SYSCLK divided by 16
        1100: SYSCLK divided by 64
        1101: SYSCLK divided by 128
        1110: SYSCLK divided by 256
        1111: SYSCLK divided by 512
*/
const uint8 APB_Prescale_Table[8u] = {0, 0, 0, 0, 1, 2, 3, 4};
const uint8 AHB_Prescale_Table[16u] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7,8};

/******************************************************************************
 *
 * RCC APIs
 *
 ******************************************************************************/

/**================================================================
 * @Fn-             MCAL_RCC_Get_SYSCLK_Freq
 * @brief -         Function to get system clock frequency -> depends on HSI and PLL
 * @param [in] -    void
 * @param [out] -   void
 * @retval -        uint32
 * Note- none
 */
Std_ReturnType MCAL_RCC_Get_SYSCLK_Freq(void)
{

    // check clock source
    switch ((RCC->CFGR >> 2) & 0b11) //->check SWS bits in CFGR register
    {
    case 0:
        return HSI_RC_CLOCK;
        break;

    case 1:
        return HSE_CLOCK;
        break;
    }
}

/**================================================================
 * @Fn-             MCAL_RCC_Get_PCLCK1_Freq
 * @brief -         peripheral clock for APB1
 * @param [in] -    void
 * @param [out] -   void
 * @retval -        uint32
 * Note- none
 */
Std_ReturnType MCAL_RCC_Get_PCLCK1_Freq(void)
{
    // prescale table contains the value to be shifted to divide the HCLCK
    return MCAL_RCC_Get_HCLCK_Freq() >> APB_Prescale_Table[(RCC->CFGR >> 8) & 0b111];
}

/**================================================================
 * @Fn-             MCAL_RCC_Get_PCLCK2_Freq
 * @brief -         peripheral clock for APB2
 * @param [in] -    void
 * @param [out] -   void
 * @retval -        uint32
 * Note- none
 */
Std_ReturnType MCAL_RCC_Get_PCLCK2_Freq(void)
{
    // PPRE2
    return MCAL_RCC_Get_HCLCK_Freq() >> APB_Prescale_Table[(RCC->CFGR >> 11) & 0b111];
}

/**================================================================
 * @Fn-             MCAL_RCC_Get_HCLCK_Freq
 * @brief -         clock for AHB ->depends on SYSCLCK
 * @param [in] -    void
 * @param [out] -   void
 * @retval -        uint32
 * Note- none
 */
Std_ReturnType MCAL_RCC_Get_HCLCK_Freq(void)
{

    // AHB prescaler bits 4 -> 7 to divide system clock HPRE
    return MCAL_RCC_Get_SYSCLK_Freq() >> AHB_Prescale_Table[(RCC->CFGR >> 4) & 0xf];
}