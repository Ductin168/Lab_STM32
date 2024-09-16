/*
 * ex5.c
 *
 *  Created on: Sep 16, 2024
 *      Author: DUC TIN
 */
#include "ex5.h"
void init_ex5(){
	HAL_GPIO_WritePin(GPIOA, SEG_0_Pin|SEG_1_Pin|SEG_2_Pin|SEG_3_Pin
				|SEG_4_Pin|SEG_5_Pin|SEG_6_Pin|SEG_7_Pin|SEG_8_Pin|SEG_9_Pin|SEG_10_Pin, 1);
	HAL_GPIO_WritePin(GPIOB, SEG_11_Pin|SEG_12_Pin|SEG_13_Pin, 1 );
}
void display7SEG_1(int num) {
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
void display7SEG_2(int num) {
    uint8_t segmentMap[10] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
    uint8_t segments = segmentMap[num];
    HAL_GPIO_WritePin(SEG_7_GPIO_Port, SEG_7_Pin, (segments & 0x01) ? SET : RESET);
    HAL_GPIO_WritePin(SEG_8_GPIO_Port, SEG_8_Pin, (segments & 0x02) ? SET : RESET);
    HAL_GPIO_WritePin(SEG_9_GPIO_Port, SEG_9_Pin, (segments & 0x04) ? SET : RESET);
    HAL_GPIO_WritePin(SEG_10_GPIO_Port, SEG_10_Pin, (segments & 0x08) ? SET : RESET);
    HAL_GPIO_WritePin(SEG_11_GPIO_Port, SEG_11_Pin, (segments & 0x10) ? SET : RESET);
    HAL_GPIO_WritePin(SEG_12_GPIO_Port, SEG_12_Pin, (segments & 0x20) ? SET : RESET);
    HAL_GPIO_WritePin(SEG_13_GPIO_Port, SEG_13_Pin, (segments & 0x40) ? SET : RESET);
}
int countRed1=5 ,countRed2=5;
int countYellow1=2, countYellow2=2;
int countGreen1=3,countGreen2=3;
int count3=10;
void countRED1(){
	if( countRed1 <=0) countRed1 = 5;
	display7SEG_1(countRed1--);
}
void countYELLOW1(){
	if( countYellow1 <=0) countYellow1 = 2;
	display7SEG_1(countYellow1--);
}
void countGREEN1(){
	if( countGreen1 <=0) countGreen1 = 3;
	display7SEG_1(countGreen1--);
}
void countRED2(){
	if( countRed2 <=0) countRed2 = 5;
	display7SEG_2(countRed2--);
}
void countYELLOW2(){
	if( countYellow2 <=0) countYellow2 = 2;
	display7SEG_2(countYellow2--);
}
void countGREEN2(){
	if( countGreen2 <=0) countGreen2 = 3;
	display7SEG_2(countGreen2--);
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
	if(Counter<=10 && Counter >=8){
		countRED1();
		countGREEN2();
	}
	if(Counter<=7 && Counter >=6){
		countRED1();
		countYELLOW2();
	}
	if(Counter<=5 && Counter >=3){
		countGREEN1();
		countRED2();
	}
	if(Counter<=2 && Counter >=1){
		countYELLOW1();
		countRED2();
	}
		Counter--;
	if( Counter<=0){
		Counter=10;
	}
}

