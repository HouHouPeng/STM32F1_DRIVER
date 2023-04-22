#include "usart.h"
#include "stdio.h"      //包含需要的头文件
#include "stdarg.h"		//包含需要的头文件 
#include "string.h"     //包含需要的头文件

#if USART1_RX_ENABLE
	
char USART1_RX_FLAG = 0;//接受完成标志位
unsigned int USART1_RX_LENG = 0;//接收字节数
char USART1_RXBUFF[USART1_RX_SIZE] = {0};

#endif

/****************************************************************************
函数名称：void Usart1_Init(u32 bound)
函数参数：u32 bound  波特率
函数返回值：无
描述：串口初始化  PA9:TX   PA10 RX
****************************************************************************/

void Usart1_Init(u32 bound)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	USART_InitTypeDef USART_InitStruct;
#if USART1_RX_ENABLE
	NVIC_InitTypeDef  NVIC_InitStruct;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
#endif
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	//PA9
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	//PA10
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
#if USART1_RX_ENABL	
	//NVIC中断配置
	USART_ClearFlag(USART1,USART_FLAG_RXNE);//清除标志位
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);//开启串口1接收中断
	NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStruct);
#endif
	//usart配置
	USART_InitStruct.USART_BaudRate = bound;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件流控制
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_Parity  = USART_Parity_No;
#if USART1_RX_ENABLE
	USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
#else
	USART_InitStruct.USART_Mode =USART_Mode_Tx;
#endif
	USART_Init(USART1,&USART_InitStruct);
	USART_Cmd(USART1,ENABLE);
}

/****************************************************************************
函数名称：void usart1_printf(char *fmt,...)
函数参数：可变传参
函数返回值：无
描述：格式化输出字符串参数
 
****************************************************************************/
__align(8) char USART1_TXBUFF[USART1_TX_SIZE];

void u1_printf(char *fmt,...)
{
	unsigned int length = 0,i = 0;
	
	va_list ap;  //构建传参列表
	va_start(ap,fmt);//使用参数fmt初始化ap列表、
	vsprintf(USART1_TXBUFF,fmt,ap);
	va_end(ap);//清理
	
	length = strlen((const char *)USART1_TXBUFF);
	while((USART1->SR & 0x40)== 0);//发送完成标志位 0 未完成
	for(i = 0;i < length;i++)
	{
		USART1->DR = USART1_TXBUFF[i];
		while((USART1->SR & 0x40)== 0);
	}
	
}


/*-------------------------------------------------*/
/*函数名：串口1接收中断函数                        */
/*参  数：无                                       */
/*返回值：无                                       */
/*-------------------------------------------------*/
void USART1_IRQHandler(void)   
{                      

} 



