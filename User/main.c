#include "stm32f10x.h"
#include "sys.h"
#include "delay.h"
#include "led.h"

int main()
{
	
	delay_init();  //��ʱ��ʼ��
	LED_Init();    //LED��ʼ��
	
	while(1)
	{
		LED2_ON;
		LED4_ON;
		delay_ms(1000);  //��ʱ1s
		LED2_OFF;
		LED4_OFF;
		delay_ms(1000);  //��ʱ1s
	}	
	
}


