#include "led.h"
/****************************************************************************
函数名称：void LED_Init(void)
函数参数：无
函数返回值：无
描述：点亮led0  //PB5，PE5---低亮
****************************************************************************/ 
void LED_Init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOE,ENABLE);	
 
 //灯D4	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;				 //IO端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //推挽输出	 
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //IO口速度为50MHz	
 GPIO_Init(GPIOB, &GPIO_InitStructure);						 //使能 

 //灯D2
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;				 
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		
 GPIO_Init(GPIOE, &GPIO_InitStructure);		
}

