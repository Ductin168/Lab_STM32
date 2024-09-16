/*
 * ex7.c
 *
 *  Created on: Sep 16, 2024
 *      Author: DUC TIN
 */

#include "ex7.h"

void clearAllClock(){
	HAL_GPIO_WritePin(GPIOB, LED_12_Pin|LED_1_Pin| LED_2_Pin| LED_3_Pin| LED_4_Pin| LED_5_Pin|
			LED_6_Pin| LED_7_Pin| LED_8_Pin| LED_9_Pin| LED_10_Pin| LED_11_Pin, RESET);
}
