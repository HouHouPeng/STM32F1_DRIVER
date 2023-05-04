#include "menu.h"

int main()
{
	u16 adcx;
  float temp;  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 
	delay_init();  //延时初始化
	LED_Init();    //LED初始化
	BEEP_Init();   //蜂鸣器初始化
	USART1_Init(9600);  //窗口初始化
	Adc_Init();
	while(1)
	{
		adcx=Get_Adc_Average(ADC_Channel_1,10);
		temp=(float)adcx*(3.3/4096);
		u1_printf("%d    %f\r\n",adcx,temp);
		delay_ms(1000);
	}
}	
	


