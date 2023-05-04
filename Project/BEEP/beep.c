#include "beep.h"
/****************************************************************************
函数名称：void BEEP_Init(void)
函数参数：无
函数返回值：无
描述：外界蜂鸣器3.3V供电  //PG15---低响
****************************************************************************/ 
void BEEP_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOG, ENABLE);

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;				     //IO端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOG, &GPIO_InitStructure);		             //使能 			 
}
