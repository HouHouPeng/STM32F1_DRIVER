#include "stm32f10x.h"
#include "sys.h"
#include "delay.h"
#include "led.h"

int main()
{
	
	delay_init();  //延时初始化
	LED_Init();    //LED初始化
	
	while(1)
	{
		LED2_ON;
		LED4_ON;
		delay_ms(1000);  //延时1s
		LED2_OFF;
		LED4_OFF;
		delay_ms(1000);  //延时1s
	}	
	
}


