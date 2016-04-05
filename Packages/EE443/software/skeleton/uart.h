/*
 * uart.h
 *
 *  Created on: Jan 27, 2014
 *      Author: zhwj814
 */

#ifndef UART_H_
#define UART_H_
#endif /* UART_H_ */




void uart_sendByte(char data);
void uart_sendInt16(int data);
void uart_sendFloat(float data);
void uart_byteRecv(void);
void uart_SendLeftBuff(void);
void uart_SendTestBuff(void);
void uart_SendConvBuff(void);
