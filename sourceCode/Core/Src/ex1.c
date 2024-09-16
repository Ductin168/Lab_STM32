/*
 * ex1.c
 *
 *  Created on: Sep 16, 2024
 *      Author: DUC TIN
 */
#include "ex1.h"
int LED_STT= LED_ON;
int count = 2;

void init_ex1(){
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
}

void ex1_run(){
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, LED_STT);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, 1-LED_STT);
	if( count >0){
		count--;
	}
	if( count <= 0){
		LED_STT=1-LED_STT;
		count=2;
	}
}

