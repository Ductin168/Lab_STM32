/*
 * ex3.c
 *
 *  Created on: Sep 16, 2024
 *      Author: DUC TIN
 */

#include "ex3.h"

int count1 = 10;
void init_ex3(){
	HAL_GPIO_WritePin(GPIOB, LED_1_Pin|LED_2_Pin| LED_3_Pin| LED_4_Pin| LED_5_Pin|
			LED_6_Pin| LED_7_Pin| LED_8_Pin| LED_9_Pin| LED_10_Pin| LED_11_Pin|LED_12_Pin ,LED_OFF);
}

void ex3_run(){
	switch(count1){
	case 10:
		HAL_GPIO_WritePin(GPIOB, LED_11_Pin|LED_5_Pin|LED_3_Pin|LED_9_Pin ,LED_ON);
		HAL_GPIO_WritePin(GPIOB ,LED_1_Pin|LED_2_Pin|LED_4_Pin|
				LED_6_Pin| LED_7_Pin| LED_8_Pin| LED_10_Pin| LED_12_Pin, LED_OFF);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOB, LED_11_Pin|LED_5_Pin|LED_4_Pin|LED_10_Pin ,LED_ON);
		HAL_GPIO_WritePin(GPIOB ,LED_1_Pin|LED_2_Pin|  LED_3_Pin|
				LED_6_Pin| LED_7_Pin| LED_8_Pin| LED_9_Pin| LED_12_Pin, LED_OFF);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOB, LED_12_Pin|LED_6_Pin|LED_2_Pin|LED_8_Pin ,LED_ON);
		HAL_GPIO_WritePin(GPIOB ,LED_1_Pin|LED_3_Pin|LED_4_Pin|
				LED_5_Pin| LED_7_Pin|LED_9_Pin| LED_10_Pin| LED_11_Pin, LED_OFF);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, LED_1_Pin|LED_7_Pin|LED_2_Pin|LED_8_Pin ,LED_ON);
		HAL_GPIO_WritePin(GPIOB ,LED_3_Pin|LED_5_Pin|  LED_4_Pin|
				LED_6_Pin| LED_9_Pin| LED_11_Pin| LED_10_Pin| LED_12_Pin, LED_OFF);
		break;
	}
	count1--;
	if( count1<=0){
		count1=10;
	}
}
