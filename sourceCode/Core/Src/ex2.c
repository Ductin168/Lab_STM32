/*
 * ex2.c
 *
 *  Created on: Sep 16, 2024
 *      Author: DUC TIN
 */
#include "ex2.h"

void init_ex2(){
	HAL_GPIO_WritePin(GPIOB, LED_11_Pin|LED_1_Pin|LED_12_Pin ,LED_OFF);
}

int counttotal = 10;
void ex2_run(){
	switch(counttotal){
	case 10:
		HAL_GPIO_WritePin(GPIOB, LED_11_Pin ,LED_ON);
		HAL_GPIO_WritePin(GPIOB , LED_1_Pin|LED_12_Pin, LED_OFF);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOB, LED_12_Pin ,LED_ON);
		HAL_GPIO_WritePin(GPIOB , LED_1_Pin|LED_11_Pin, LED_OFF);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, LED_1_Pin ,LED_ON);
		HAL_GPIO_WritePin(GPIOB , LED_11_Pin|LED_12_Pin, LED_OFF);
		break;
	}
	counttotal--;
	if( counttotal<=0){
		counttotal=10;
	}
}

