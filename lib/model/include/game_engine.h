#ifndef WBUDY_STM32_SNAKE_GAME_ENGINE_H
#define WBUDY_STM32_SNAKE_GAME_ENGINE_H

#include "stm32f1xx.h"

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
#define MENU 4

#define TRUE 1
#define FALSE 0

#define BOARD_SIZE 8
#define SEGMENT_SIZE 16
#define TAIL_SIZE 16

#define STARTING_POINT_SNAKE_X 3
#define STARTING_POINT_SNAKE_Y 0
#define STARTING_DIRECTION_SNAKE 2
#define STARTING_TAIL_LENGTH 2

#define MAX_GAME_SPEED 1
#define MIN_GAME_SPEED 90

#define BRIGHTNESS_MIN 100
#define BRIGHTNESS_MAX 1000
#define BRIGHTNESS_STEP 50
#define GET_SCREEN_BRIGHTNESS() __HAL_TIM_GET_COMPARE(&tim1, TIM_CHANNEL_1)
#define CHANGE_SCREEN_BRIGHTNESS(value) __HAL_TIM_SET_COMPARE(&tim1, TIM_CHANNEL_1, GET_SCREEN_BRIGHTNESS() + value);

struct Snake {
    uint8_t x;
    uint8_t y;
    uint8_t direction;
    uint8_t tailLength;
} snake;

struct Apple {
    uint8_t x;
    uint8_t y;
} apple;

uint8_t tail[TAIL_SIZE];

_Noreturn void GameEngineLoop();

void Mode_Menu();

void Mode_Temperature();

void Mode_GameOver();

void Mode_Snake(uint64_t);

uint8_t Snake_Change_Speed();

void Snake_MoveSnake();

void Snake_MoveTail();

void Snake_DrawSnakeHead();

void Snake_RemoveLastPart();

void Snake_DrawSnakeTail();

void Snake_PutAppleOnBoard();

void Snake_DrawApple();

void Snake_CanSnakeEatApple();

uint8_t CheckBit(uint8_t bit, uint8_t byte);

int8_t Snake_GameOver();

int8_t Snake_TailCollision(int8_t, int8_t);

int8_t CheckMovementButtons();

int8_t CheckAllButtons();




#endif //WBUDY_STM32_SNAKE_GAME_ENGINE_H