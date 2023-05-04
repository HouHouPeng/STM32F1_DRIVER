#include "menu.h"

int main()
{
	u16 adcx1,adcx2;     //adc�����ֵ
	u16 dacval=0; //dac���ֵ
  float temp1,temp2;   //adc��ѹֵ
	u8 key;	      //����ֵ
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 
	delay_init();  //��ʱ��ʼ��
	LED_Init();    //LED��ʼ��
	KEY_Init();			  //��ʼ����������
	BEEP_Init();   //��������ʼ��
	USART1_Init(9600);  //���ڳ�ʼ��
	Adc_Init();
	Dac1_Init();				//DAC1��ʼ��
	Dac2_Init();				//DAC2��ʼ��
	
	DAC_SetChannel1Data(DAC_Align_12b_R, 0);//��ʼֵΪ0	
	DAC_SetChannel2Data(DAC_Align_12b_R, 0);
	
	while(1)
	{
		key=KEY_Scan(0);			  
		if(key==WKUP_PRES)
		{if(dacval<4000){dacval+=200;}}
		else if(key==KEY1_PRES)	
		{if(dacval>200){dacval-=200;}
		 else {dacval=0;}}
		
		DAC_SetChannel1Data(DAC_Align_12b_R, dacval);//����DACֵ
		DAC_SetChannel2Data(DAC_Align_12b_R, dacval);
		
		adcx1=Get_Adc_Average(ADC_Channel_10,10);
		temp1=(float)adcx1*(3.3/4096);
		adcx2=Get_Adc_Average(ADC_Channel_11,10);
		temp2=(float)adcx2*(3.3/4096);
		u1_printf("%d    %f     %d     %f\r\n\r\n",adcx1,temp1,adcx2,temp2);
		delay_ms(1000);
	}
}	
	


