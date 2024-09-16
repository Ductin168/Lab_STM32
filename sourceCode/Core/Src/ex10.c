/*
 * ex10.c
 *
 *  Created on: Sep 16, 2024
 *      Author: DUC TIN
 */
#include "ex10.h"

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
	        settime(hour, minute, second);
	    }
    	settime(hour, minute, second);
    	second++;
}

