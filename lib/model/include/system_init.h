#ifndef WBUDY_STM32_SNAKE_SYSTEM_INIT_H
#define WBUDY_STM32_SNAKE_SYSTEM_INIT_H

#include "stm32f1xx.h"
#include "interrupts_handlers.h"

#define clock128

extern SPI_HandleTypeDef spi;
extern DMA_HandleTypeDef dma1;
extern DMA_HandleTypeDef dma3;
extern TIM_HandleTypeDef tim1;
extern TIM_HandleTypeDef tim2;
extern TIM_HandleTypeDef tim3;
extern ADC_HandleTypeDef adc;


void SystemClock_Config72(void);
void SystemClock_Config128(void);
void MX_DMA_Init(void);
void GPIO_INIT();
void SPI_INIT();
void TIM_INIT();
void DMA_Init(void);
void PWM_INIT(void);
void ADC_INIT(void);

#endif //WBUDY_STM32_SNAKE_SYSTEM_INIT_H
