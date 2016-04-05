/*
 * uart.c
 *
 *  Created on: Jan 27, 2014
 *      Author: zhwj814
 */

#include "system_init.h"

extern int sr;
extern int leftCount;
extern int lefttestCount;
extern int rightCount;
extern int convResultBufferSize;
extern int convIndex;
extern alt_u32 leftready_id;
extern alt_u32 rightready_id;
extern unsigned short RxHead;
extern unsigned char rx_buffer[RX_BUFFER_SIZE];
extern alt_16 leftChannelData[BUFFERSIZE];
extern alt_16 datatest[1000];
extern alt_16 rightChannelData[BUFFERSIZE];
extern float convResultBuffer[CONVBUFFSIZE];
alt_16 DataBufferCopy[BUFFERSIZE];



int counter = 0;

/*-------------------------- Send data---------------------------*/
/*Send integer value through UART*/
void uart_sendByte(char data){
	IOWR_ALTERA_AVALON_UART_TXDATA(UART_BASE, data);
	delay(UART_SEND_DELAY); //not sure about delay parameter
	IOWR_ALTERA_AVALON_UART_TXDATA(UART_BASE, '\n');
}

/*Send integer value through UART  -> Higher 8 bits first */
void uart_sendInt16(alt_16 data){
	IOWR_ALTERA_AVALON_UART_TXDATA(UART_BASE, data & 0xFF);
	delay(UART_SEND_DELAY);
	IOWR_ALTERA_AVALON_UART_TXDATA(UART_BASE, data >> 8);
	delay(UART_SEND_DELAY);

}



void uart_sendFloat(float data){
	char number[10];
	int i = 0;
	snprintf(number, sizeof(number), "%f", data);
	while(i < 10){
		IOWR_ALTERA_AVALON_UART_TXDATA(UART_BASE, number[i]);
		delay(UART_SEND_DELAY); //not sure about delay parameter
		i++;
	}
	IOWR_ALTERA_AVALON_UART_TXDATA(UART_BASE, '\n');

}



/*-------------------------- Receive data---------------------------*/

//void uart_byteRecv(void){
//	sr = IORD_ALTERA_AVALON_UART_STATUS(UART_BASE);
//	if(sr & ALTERA_AVALON_UART_STATUS_RRDY_MSK){
//	    rx_buffer[RxHead] = IORD_ALTERA_AVALON_UART_RXDATA(UART_BASE);
//		IOWR_ALTERA_AVALON_UART_STATUS(UART_BASE, 0);
//		if (++RxHead > (RX_BUFFER_SIZE-1)) RxHead = 0;
//	}
//}

/*Send the whole buffer to the PC through UART*/
void uart_SendLeftBuff(void){
	int temp;
	temp = leftCount;
	for (counter = temp; counter < (BUFFERSIZE + temp); counter++){
		uart_sendInt16(leftChannelData[(counter % BUFFERSIZE)]);
	}
}

/*Send the whole testing 1000 data buffer to the PC through UART*/
void uart_SendTestBuff(void){
	int temp;
	temp = lefttestCount;
	for (counter = temp; counter < (256 + temp); counter++){
		uart_sendInt16(datatest[counter % 256]);
	}
}

/*Send the whole buffer to the PC through UART*/
void uart_SendConvBuff(void){
	int temp;
	temp = convIndex;
	for (counter = temp; counter < (CONVBUFFSIZE + temp); counter++){
		uart_sendInt16((alt_16)convResultBuffer[counter % (CONVBUFFSIZE)]);
	}
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



