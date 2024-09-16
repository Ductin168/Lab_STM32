/*
 * ex5.c
 *
 *  Created on: Sep 16, 2024
 *      Author: DUC TIN
 */
#include "ex5.h"
void init_ex5(){
	HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin|SEG_1_Pin|SEG_2_Pin|SEG_3_Pin
				|SEG_4_Pin|SEG_5_Pin|SEG_6_Pin, 1);
}
void display7SEG_copy(int num) {
    uint8_t segmentMap[10] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
    uint8_t segments = segmentMap[num];
    HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, (segments & 0x01) ? SET : RESET);
    HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, (segments & 0x02) ? SET : RESET);
    HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, (segments & 0x04) ? SET : RESET);
    HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, (segments & 0x08) ? SET : RESET);
    HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, (segments & 0x10) ? SET : RESET);
    HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, (segments & 0x20) ? SET : RESET);
    HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, (segments & 0x40) ? SET : RESET);
}
int countRed=5;
int countYellow=2;
int countGreen=3;
int count3=10;
void countRED(){
	if( countRed <=0) countRed = 5;
	display7SEG_copy(countRed--);
}
void countYELLOW(){
	if( countYellow <=0) countYellow = 2;
	display7SEG_copy(countYellow--);
}
void countGREEN(){
	if( countGreen <=0) countGreen = 3;
	display7SEG_copy(countGreen--);
}
int Counter= 10;
void ex5_run(){
	switch(Counter){
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
	if(Counter<=10 && Counter >=6){
		countRED();
	}
	if(Counter<=5 && Counter >=3){
		countGREEN();
	}
	if(Counter<=2 && Counter >=1){
		countYELLOW();
	}
		Counter--;
	if( Counter<=0){
		Counter=10;
	}
}

