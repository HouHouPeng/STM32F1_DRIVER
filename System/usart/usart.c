#include "usart.h"
#include "stdio.h"      //������Ҫ��ͷ�ļ�
#include "stdarg.h"		//������Ҫ��ͷ�ļ� 
#include "string.h"     //������Ҫ��ͷ�ļ�

#if USART1_RX_ENABLE
	
char USART1_RX_FLAG = 0;//������ɱ�־λ
unsigned int USART1_RX_LENG = 0;//�����ֽ���
char USART1_RXBUFF[USART1_RX_SIZE] = {0};

#endif

/****************************************************************************
�������ƣ�void Usart1_Init(u32 bound)
����������u32 bound  ������
��������ֵ����
���������ڳ�ʼ��  PA9:TX   PA10 RX
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
	//NVIC�ж�����
	USART_ClearFlag(USART1,USART_FLAG_RXNE);//�����־λ
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);//��������1�����ж�
	NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStruct);
#endif
	//usart����
	USART_InitStruct.USART_BaudRate = bound;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ��������
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
�������ƣ�void usart1_printf(char *fmt,...)
�����������ɱ䴫��
��������ֵ����
��������ʽ������ַ�������
 
****************************************************************************/
__align(8) char USART1_TXBUFF[USART1_TX_SIZE];

void u1_printf(char *fmt,...)
{
	unsigned int length = 0,i = 0;
	
	va_list ap;  //���������б�
	va_start(ap,fmt);//ʹ�ò���fmt��ʼ��ap�б�
	vsprintf(USART1_TXBUFF,fmt,ap);
	va_end(ap);//����
	
	length = strlen((const char *)USART1_TXBUFF);
	while((USART1->SR & 0x40)== 0);//������ɱ�־λ 0 δ���
	for(i = 0;i < length;i++)
	{
		USART1->DR = USART1_TXBUFF[i];
		while((USART1->SR & 0x40)== 0);
	}
	
}


/*-------------------------------------------------*/
/*������������1�����жϺ���                        */
/*��  ������                                       */
/*����ֵ����                                       */
/*-------------------------------------------------*/
void USART1_IRQHandler(void)   
{                      

} 



