/*
 * ex10.c
 *
 *  Created on: Sep 16, 2024
 *      Author: DUC TIN
 */
#include "ex10.h"

void clearAllClock(){
	HAL_GPIO_WritePin(GPIOB, LED_12_Pin|LED_1_Pin| LED_2_Pin| LED_3_Pin| LED_4_Pin| LED_5_Pin|
			LED_6_Pin| LED_7_Pin| LED_8_Pin| LED_9_Pin| LED_10_Pin| LED_11_Pin, RESET);
}
void setNumberOnClock(int num){
	int leds[] = {LED_1_Pin, LED_2_Pin, LED_3_Pin, LED_4_Pin, LED_5_Pin, LED_6_Pin,
			LED_7_Pin, LED_8_Pin, LED_9_Pin, LED_10_Pin, LED_11_Pin,LED_12_Pin};
	    if (num >0 && num < 13) {
	        HAL_GPIO_WritePin(GPIOB, leds[num-1], SET);
	    }
	    if(num==0){
	    	HAL_GPIO_WritePin(GPIOB, leds[11], SET);
	    }
}
void clearNumberOnClock(int num){
	int leds[] = {LED_1_Pin, LED_2_Pin, LED_3_Pin, LED_4_Pin, LED_5_Pin, LED_6_Pin,
			LED_7_Pin, LED_8_Pin, LED_9_Pin, LED_10_Pin, LED_11_Pin,LED_12_Pin};
		    if (num > 0 && num < 13) {
		        HAL_GPIO_WritePin(GPIOB, leds[num-1], RESET);
		    }
		    if( num==0 ){
		    	HAL_GPIO_WritePin(GPIOB, leds[11], RESET);
		    }
}
void init_ex10(){
	clearAllClock();
}
int hour, minute, second;
void settime(int h, int m,int s){
	hour=h;
	minute=m;
	second=s;
	int hourPos = hour % 12;
	int minutePos = minute / 5;
	int secondPos = second / 5;
	setNumberOnClock(hourPos);
	setNumberOnClock(minutePos);
	setNumberOnClock(secondPos);
}
void runclock(){
	    if(second %5 ==0 && (second-5)/5 !=hour % 12 && (second-5)/5 != minute/5 ){
	    	clearNumberOnClock((second-5)/5);
	    }
	    if (second == 60) {
	        second = 0;
	        minute++;
	    }
	    if(minute %5 ==0 && (minute-5)/5 != hour % 12 && (minute-5)/5 != second/5){
	    	clearNumberOnClock((minute-5)/5);
	    }
	    if (minute == 60) {
	        minute = 0;
	        hour++;
	    }
	    if((hour == 12||hour ==24) && minute/5 != 11 && second/5 != 11){
	    	hour = 0;
	    	clearNumberOnClock(11);
	    }
	    settime(hour, minute, second);
    	second++;
}

