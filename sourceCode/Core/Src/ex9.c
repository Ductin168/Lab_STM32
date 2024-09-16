/*
 * ex9.c
 *
 *  Created on: Sep 16, 2024
 *      Author: DUC TIN
 */
#include "ex9.h"
void clearNumberOnClock(int num){
	int leds[] = {LED_1_Pin, LED_2_Pin, LED_3_Pin, LED_4_Pin, LED_5_Pin, LED_6_Pin,
			LED_7_Pin, LED_8_Pin, LED_9_Pin, LED_10_Pin, LED_11_Pin,LED_12_Pin};
		    if (num > 0 && num < 13) {
		        HAL_GPIO_WritePin(GPIOB, leds[num-1], RESET);
		    }
}

