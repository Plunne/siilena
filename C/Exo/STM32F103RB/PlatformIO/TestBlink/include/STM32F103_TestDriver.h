#ifndef STM32F103_TestDriver_H
#define STM32F103_TestDriver_H

#include <stdint.h>

typedef struct
{
	uint32_t CRL;
	uint32_t CRH;
	uint32_t IDR;
	uint32_t ODR;
	uint32_t BSRR;
} GPIO_TypeDef;

typedef struct
{
	uint32_t APB2ENR;
} RCC_TypeDef;

GPIO_TypeDef GPIOA_;
#define GPIOA  (&GPIOA_)

GPIO_TypeDef GPIOB_;
#define GPIOB (&GPIOB_)

GPIO_TypeDef GPIOC_;
#define GPIOC (&GPIOC_)

GPIO_TypeDef GPIOD_;
#define GPIOD (&GPIOD_)

GPIO_TypeDef GPIOE_;
#define GPIOE (&GPIOE_)

RCC_TypeDef RCC_;
#define RCC (&RCC_)

#define RCC_APB2ENR_IOPAEN 2
#define RCC_APB2ENR_IOPBEN 3
#define RCC_APB2ENR_IOPCEN 4
#define RCC_APB2ENR_IOPDEN 5
#define RCC_APB2ENR_IOPEEN 6

#endif /* STM32F103_TestDriver_H */
