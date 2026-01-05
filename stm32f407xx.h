/*
 * stm32f407xx.h
 *
 *  Created on: Jan 2, 2026
 *      Author: Vaibhav
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_


#include <stdint.h>

/* shortcut */
#define _vo volatile

/************************ MCU MEMORY BASE ADDRESSES ************************/
#define FLASH_BASEADDR     0x08000000U   // internal flash
#define SRAM1_BASEADDR     0x20000000U   // SRAM1
#define SRAM2_BASEADDR     0x2001C000U   // SRAM2
#define ROM_BASEADDR       0x1FFF0000U   // system memory

/************************ BUS BASE ADDRESSES ************************/
#define AHB1_BASEADDR      0x40020000U
#define AHB2_BASEADDR      0x50000000U
#define APB1_BASEADDR      0x40000000U
#define APB2_BASEADDR      0x40010000U

/************************ GPIO BASE ADDRESSES ************************/
#define GPIOA_BASEADDR     (AHB1_BASEADDR + 0x0000)
#define GPIOB_BASEADDR     (AHB1_BASEADDR + 0x0400)
#define GPIOC_BASEADDR     (AHB1_BASEADDR + 0x0800)

/************************ RCC BASE ADDRESS ************************/
#define RCC_BASEADDR       (AHB1_BASEADDR + 0x3800)

/************************ GPIO REGISTER DEFINITION ************************/
typedef struct
{
    _vo uint32_t MODER;     // mode register
    _vo uint32_t OTYPER;    // output type
    _vo uint32_t OSPEEDR;  // speed
    _vo uint32_t PUPDR;    // pull-up pull-down
    _vo uint32_t IDR;      // input data
    _vo uint32_t ODR;      // output data
    _vo uint32_t BSRR;     // bit set reset
    _vo uint32_t LCKR;     // lock
    _vo uint32_t AFR[2];   // alternate function
}GPIO_RegDef_t;

/************************ RCC REGISTER DEFINITION ************************/
typedef struct
{
    _vo uint32_t CR;
    _vo uint32_t PLLCFGR;
    _vo uint32_t CFGR;
    _vo uint32_t CIR;
    _vo uint32_t AHB1RSTR;
    _vo uint32_t AHB2RSTR;
    uint32_t RESERVED[2];
    _vo uint32_t APB1RSTR;
    _vo uint32_t APB2RSTR;
    uint32_t RESERVED1[2];
    _vo uint32_t AHB1ENR;   // enable GPIO clocks
    _vo uint32_t AHB2ENR;
    uint32_t RESERVED2[2];
    _vo uint32_t APB1ENR;
    _vo uint32_t APB2ENR;
}RCC_RegDef_t;

/************************ PERIPHERAL DEFINITIONS ************************/
#define GPIOA   ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB   ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC   ((GPIO_RegDef_t*)GPIOC_BASEADDR)

#define RCC     ((RCC_RegDef_t*)RCC_BASEADDR)

/************************ CLOCK ENABLE MACROS ************************/
#define GPIOA_PCLK_EN()   (RCC->AHB1ENR |= (1<<0))
#define GPIOB_PCLK_EN()   (RCC->AHB1ENR |= (1<<1))
#define GPIOC_PCLK_EN()   (RCC->AHB1ENR |= (1<<2))

/************************ CLOCK DISABLE MACROS ************************/
#define GPIOA_PCLK_DEN()   (RCC->AHB1ENR &= ~(1<<0))
#define GPIOB_PCLK_DEN()   (RCC->AHB1ENR &= ~(1<<1))
#define GPIOC_PCLK_DEN()   (RCC->AHB1ENR &= ~(1<<2))

/************************ COMMON MACROS ************************/
#define ENABLE   1
#define DISABLE  0
#define SET      ENABLE
#define RESET    DISABLE
#define GPIO_PIN_SET    SET
#define GPIO_PIN_RESET    RESET





#endif /* INC_STM32F407XX_H_ */
