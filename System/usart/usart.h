#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "sys.h" 


#define USART1_RX_ENABLE 			1		//使能（1）/禁止（0）串口1接收

#define USART1_RX_SIZE  256
#define USART1_TX_SIZE  256	

void USART1_Init(u32 bound);
void u1_printf(char *fmt,...);	


extern u16 USART1_RX_FLAG;         		//接收状态标记	
extern unsigned int USART1_RX_LENG;   //接收字节数
extern char USART1_RXBUFF[USART1_RX_SIZE];

#endif


