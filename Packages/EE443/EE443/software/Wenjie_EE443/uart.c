/*
 * uart.c
 *
 *  Created on: Jan 27, 2014
 *      Author: zhwj814
 */
#include "altera_avalon_uart_regs.h"
#include "system.h"
#include "delay.h"


/*-------------------------- Send data---------------------------*/

void uart_sendByte(char data){
	IOWR_ALTERA_AVALON_UART_TXDATA(UART_BASE, data);
	delay(1000); //not sure about delay parameter
	IOWR_ALTERA_AVALON_UART_TXDATA(UART_BASE, '\n');
}


void uart_sendInt(int data){
	char number[10];
	int i = 0;
	snprintf(number, sizeof(number), "%i", data);
	while(i < 10){
		IOWR_ALTERA_AVALON_UART_TXDATA(UART_BASE, number[i]);
		delay(100000); //not sure about delay parameter
		i++;
	}
	IOWR_ALTERA_AVALON_UART_TXDATA(UART_BASE, '\n');
}



void uart_sendFloat(float data){
	char number[10];
	int i = 0;
	snprintf(number, sizeof(number), "%f", data);
	while(i < 10){
		IOWR_ALTERA_AVALON_UART_TXDATA(UART_BASE, number[i]);
		delay(1000); //not sure about delay parameter
		i++;
	}
	IOWR_ALTERA_AVALON_UART_TXDATA(UART_BASE, '\n');

}



/*-------------------------- Receive data---------------------------*/

char uart_byteRecv(){
	char data;
	data = IORD_ALTERA_AVALON_UART_RXDATA(UART_BASE);
	return data;
}
//
//char* uart_charArrayRecv(int length){
//	char dataBuffer[length];
//	int i;
//	for (i = 0; i < length; length++){
//		dataBuffer[i] = IORD_ALTERA_AVALON_UART_RXDATA(UART_BASE);
//	}
//	return &dataBuffer;
//}



