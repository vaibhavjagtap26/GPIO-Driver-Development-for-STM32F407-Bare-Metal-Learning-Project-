/*
 * GPIO_Source.c
 *
 *  Created on: Jan 2, 2026
 *      Author: Vaibhav
 */
#include "GPIO_driver.h"

/************************ CLOCK CONTROL ************************/
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
    if(EnorDi == ENABLE)
    {
        if(pGPIOx == GPIOA) GPIOA_PCLK_EN();
        else if(pGPIOx == GPIOB) GPIOB_PCLK_EN();
        else if(pGPIOx == GPIOC) GPIOC_PCLK_EN();
    }
    else{
    	if(pGPIOx == GPIOA) GPIOA_PCLK_DEN();
    	        else if(pGPIOx == GPIOB) GPIOB_PCLK_DEN();
    	        else if(pGPIOx == GPIOC) GPIOC_PCLK_DEN();
    }
}

/************************ GPIO INIT ************************/
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
    uint32_t temp = 0;

    // enable clock
    GPIO_PeriClockControl(pGPIOHandle->pGPIOx, ENABLE);

    // mode
    temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <<
           (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->MODER &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); //clearing
    pGPIOHandle->pGPIOx->MODER |= temp;  //setting

    // speed
    temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed <<
           (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->OSPEEDR |= temp;

    // pull up pull down
    temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPd <<
           (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->PUPDR |= temp;

    // output type
    temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType <<
           pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
    pGPIOHandle->pGPIOx->OTYPER |= temp;
}

/************************ READ ************************/
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
    return (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x1);
}

uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
    return (uint16_t)pGPIOx->IDR;
}

/************************ WRITE ************************/
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{
    if(Value == SET)
        pGPIOx->ODR |= (1 << PinNumber);
    else
        pGPIOx->ODR &= ~(1 << PinNumber);
}

void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
    pGPIOx->ODR = Value;
}

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
    pGPIOx->ODR ^= (1 << PinNumber);
}




