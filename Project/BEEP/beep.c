#include "beep.h"
/****************************************************************************
�������ƣ�void BEEP_Init(void)
������������
��������ֵ����
��������������3.3V����  //PG15---����
****************************************************************************/ 
void BEEP_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOG, ENABLE);

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;				     //IO�˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOG, &GPIO_InitStructure);		             //ʹ�� 			 
}
