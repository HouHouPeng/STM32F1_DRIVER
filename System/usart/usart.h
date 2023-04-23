#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "sys.h" 


#define USART1_RX_ENABLE 			1		//ʹ�ܣ�1��/��ֹ��0������1����

#define USART1_RX_SIZE  256
#define USART1_TX_SIZE  256	

void USART1_Init(u32 bound);
void u1_printf(char *fmt,...);	


extern u16 USART1_RX_FLAG;         		//����״̬���	
extern unsigned int USART1_RX_LENG;   //�����ֽ���
extern char USART1_RXBUFF[USART1_RX_SIZE];

#endif


