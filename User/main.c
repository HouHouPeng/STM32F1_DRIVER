#include "menu.h"

int main()
{
	u16 t;  
	u16 len;	
	u16 times=0;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 
	delay_init();  //延时初始化
	LED_Init();    //LED初始化
	BEEP_Init();   //蜂鸣器初始化
	USART1_Init(9600);  //窗口初始化
	
	
	while(1)
	{
		if(USART1_RX_FLAG==1)
		{					   
			u1_printf("\r\n您发送的消息为:\r\n\r\n");
			u1_printf("%s\r\n",USART1_RXBUFF);
			u1_printf("\r\n\r\n");//插入换行
			USART1_RX_FLAG=0;
		}
	}
}	
	


