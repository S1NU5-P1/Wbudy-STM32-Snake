#include <stdio.h>
#include <stdlib.h>
#include "stm32f1xx_hal.h"
#include "ST7735.h"
#include "ST7735_buffer.h"
#include "DS18B20.h"
#include "ftoa.h"
#include "system_init.h"
#include "interrupts_handlers.h"
#include "game_engine.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"

SPI_HandleTypeDef spi;
DMA_HandleTypeDef dma1;
DMA_HandleTypeDef dma3;
TIM_HandleTypeDef tim1;
TIM_HandleTypeDef tim2;
TIM_HandleTypeDef tim3;

void GameLoop();

int main(void) {
#ifdef clock128
    SystemClock_Config128();
#else
    SystemClock_Config72();
#endif
    HAL_Init();

    DMA_Init();
    MX_DMA_Init();
    GPIO_INIT();
    SPI_INIT();
    TIM_INIT();
    HAL_SPI_MspInit(&spi);

    if (HAL_SPI_Init(&spi) != HAL_OK) {
    }

    ST7735_Init();
    ST7735_FillScreen(ST7735_BLUE);

    tim1.Instance = TIM1;
    tim1.Init.Period = 999;
    tim1.Init.Prescaler = 127;
    tim1.Init.ClockDivision = 0;
    tim1.Init.CounterMode = TIM_COUNTERMODE_UP;
    tim1.Init.RepetitionCounter = 0;
    tim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;

    __HAL_RCC_TIM1_CLK_ENABLE();


    HAL_TIM_PWM_Start(&tim1, TIM_CHANNEL_1);

    __HAL_TIM_SET_COMPARE(&tim1, TIM_CHANNEL_1, 1000);

    __HAL_TIM_SET_COUNTER(&tim1, 0);

    DS18B20_Init();
    char tempText[10];
    double testTemp = ReadTemp() * 0.0625;
    ftoa(testTemp, tempText, 4);
    HAL_TIM_Base_Start(&tim2);
    __HAL_TIM_SET_COUNTER(&tim2, 0);

    GameEngineLoop();

}
