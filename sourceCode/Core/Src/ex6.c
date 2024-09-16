/*
 * ex6.c
 *
 *  Created on: Sep 16, 2024
 *      Author: DUC TIN
 */
#include "ex6.h"

void init_ex6(){
	HAL_GPIO_WritePin(GPIOB, LED_12_Pin|LED_1_Pin| LED_2_Pin| LED_3_Pin| LED_4_Pin| LED_5_Pin|
			LED_6_Pin| LED_7_Pin| LED_8_Pin| LED_9_Pin| LED_10_Pin| LED_11_Pin, RESET);
}

int timeCounter = 0;
int leds[] = {LED_12_Pin, LED_1_Pin, LED_2_Pin, LED_3_Pin, LED_4_Pin, LED_5_Pin, LED_6_Pin,
		LED_7_Pin, LED_8_Pin, LED_9_Pin, LED_10_Pin, LED_11_Pin};
int currentLed = 11;
void ex6_run(){
	HAL_GPIO_WritePin(GPIOB, leds[currentLed], RESET);
    currentLed = (currentLed+1)  % 12;
	timeCounter++;
    if (timeCounter >= 1) {
        HAL_GPIO_WritePin(GPIOB, leds[currentLed], SET);
        timeCounter = 0;
    }
}
