#include "menu.h"

int main()
{
	u16 t;  
	u16 len;	
	u16 times=0;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 
	delay_init();  //��ʱ��ʼ��
	LED_Init();    //LED��ʼ��
	BEEP_Init();   //��������ʼ��
	USART1_Init(9600);  //���ڳ�ʼ��
	
	
	while(1)
	{
		if(USART1_RX_FLAG==1)
		{					   
			u1_printf("\r\n�����͵���ϢΪ:\r\n\r\n");
			u1_printf("%s\r\n",USART1_RXBUFF);
			u1_printf("\r\n\r\n");//���뻻��
			USART1_RX_FLAG=0;
		}
	}
}	
	


