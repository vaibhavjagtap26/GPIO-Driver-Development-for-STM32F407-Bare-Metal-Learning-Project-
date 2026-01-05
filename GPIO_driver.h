/*
 * GPIO_driver.h
 *
 *  Created on: Jan 2, 2026
 *      Author: Vaibhav
 */

#ifndef INC_GPIO_DRIVER_H_
#define INC_GPIO_DRIVER_H_


#include "stm32f407xx.h"

/************************ GPIO PIN CONFIG STRUCT ************************/
typedef struct
{
    uint32_t GPIO_PinNumber;     // pin number
    uint32_t GPIO_PinMode;       // input/output/alt/analog
    uint32_t GPIO_PinSpeed;      // speed
    uint32_t GPIO_PinPuPd;       // pull-up pull-down
    uint32_t GPIO_PinOPType;     // push pull/open drain
}GPIO_PinConfig_t;

/************************ GPIO HANDLE STRUCT ************************/
typedef struct
{
    GPIO_RegDef_t *pGPIOx;       // GPIO base address
    GPIO_PinConfig_t GPIO_PinConfig;
}GPIO_Handle_t;

/************************ GPIO PIN MODES ************************/
#define GPIO_MODE_IN      0
#define GPIO_MODE_OUT     1
#define GPIO_MODE_ALTFN   2
#define GPIO_MODE_ANALOG  3
#define GPIO_MODE_IT_FT   4   //interrupt at falling edge
#define GPIO_MODE_IT_RT   5   //interrupt at rising edge
#define GPIO_MODE_IT_RFT  6   //interrupt at Rising/falling edge


/************************ GPIO OUTPUT TYPES ************************/
#define GPIO_OP_PP        0
#define GPIO_OP_OD        1

/************************ GPIO SPEED ************************/
#define GPIO_SPEED_LOW    0
#define GPIO_SPEED_MED    1
#define GPIO_SPEED_FAST   2
#define GPIO_SPEED_HIGH   3

/************************ GPIO PULL ************************/
#define GPIO_NO_PUPD     0
#define GPIO_PIN_PU      1
#define GPIO_PIN_PD      2

/************************ GPIO Pin_numbers ************************/

#define GPIO_PIN_NO_0        0
#define GPIO_PIN_NO_1        1
#define GPIO_PIN_NO_2        2
#define GPIO_PIN_NO_3        3
#define GPIO_PIN_NO_4        4
#define GPIO_PIN_NO_5        5
#define GPIO_PIN_NO_6        6
#define GPIO_PIN_NO_7        7
#define GPIO_PIN_NO_8        8
#define GPIO_PIN_NO_9        9
#define GPIO_PIN_NO_10       10
#define GPIO_PIN_NO_11       11
#define GPIO_PIN_NO_12       12
#define GPIO_PIN_NO_13       13
#define GPIO_PIN_NO_14       14
#define GPIO_PIN_NO_15       15

/************************ API PROTOTYPES ************************/
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

/*********************** GPIO IRQ APIS ************************/
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
void GPIO_IRQHandling(uint8_t PinNumber);






#endif /* INC_GPIO_DRIVER_H_ */
