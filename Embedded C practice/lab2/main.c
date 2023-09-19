/*Author Ziad Hisham - learn in depth*/
#include <stdint.h>
#include "main.h"

/*NEEDED REGISTERS*/
#define RCC_BASE    0x40021000
#define GPIOA_BASE  0x40010800
#define RCC_APB2ENR *(volatile uint32 *)(RCC_BASE   +   0x18)
#define GPIOA_CRH   *(volatile uint32 *)(GPIOA_BASE +   0x04)
#define GPIOA_ODR   *(volatile uint32 *)(GPIOA_BASE +   0x0C)

/*BIT FIELDS*/
#define RCC_IOPAEN  (1<<2)
#define GPIOA13     (1UL<<13)

typedef union {
        vuint32_t   all_fields;
        struct main
        {
            vuint32_t   reserved:13;
            vuint32_t   P_13:1;
        }Pin;
        
}R_ODR_t;

volatile R_ODR_t*   R_ODR = (volatile R_ODR_t*)(GPIOA_BASE  +   0x0C);

int main(void){
    RCC_APB2ENR |= RCC_IOPAEN; //ENABLE ADVANCED PERIPHERAL BUS
    GPIOA_CRH   &= 0xFF0FFFFF; /*COMMIT REGISTER*/
    GPIOA_CRH   |= 0x00200000; /*SET COMMIT*/

    while(1){
        R_ODR->Pin.P_13 =   1;/*SET OUTPUT DATA REGISTER PIN 13 IN PORT A*/
        for(int i = 0; i<5000;i++); /*delay*/
        R_ODR->Pin.P_13 =   0;/*RESET OUTPUT DATA REGISTER PIN 13 IN PORT A*/
        for(int i = 0; i<5000;i++); /*delay*/

    }
    return 0;
}