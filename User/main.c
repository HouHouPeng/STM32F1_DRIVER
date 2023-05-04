#include "menu.h"

int main()
{
	u16 adcx;
  float temp;  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 
	delay_init();  //��ʱ��ʼ��
	LED_Init();    //LED��ʼ��
	BEEP_Init();   //��������ʼ��
	USART1_Init(9600);  //���ڳ�ʼ��
	Adc_Init();
	while(1)
	{
		adcx=Get_Adc_Average(ADC_Channel_1,10);
		temp=(float)adcx*(3.3/4096);
		u1_printf("%d    %f\r\n",adcx,temp);
		delay_ms(1000);
	}
}	
	


