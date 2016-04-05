/*
 * i2s_control.c
 *
 *  Created on: Jan 18, 2014
 *      Author: atching
 *      Organization: University of Washington Electrical Engineering
 *		Notes: Intended for use by EE443 students
 *
 *		SPI control for bit banging
 */


#include <stdio.h>
#include "altera_avalon_pio_regs.h"
#include "system.h"
#include "delay.h"

int I2S_collect_left(){
	int k = 0;
	int leftChannel = 0;

	//Left channel LRCOUT = 0
	IOWR_ALTERA_AVALON_PIO_DATA(LRCOUT_BASE, 0);
    delay(3);
    IOWR_ALTERA_AVALON_PIO_DATA(BCLK_OUT_BASE, 0);
	delay(3);
	IOWR_ALTERA_AVALON_PIO_DATA(BCLK_OUT_BASE, 1);
	delay(3);
	for(k = 0; k < 16; k++){
		IOWR_ALTERA_AVALON_PIO_DATA(BCLK_OUT_BASE, 0);
		delay(3);
		IOWR_ALTERA_AVALON_PIO_DATA(BCLK_OUT_BASE, 1);
		delay(3);
		//printf("%i", IORD_ALTERA_AVALON_PIO_DATA(DOUT_BASE));
		leftChannel |= IORD_ALTERA_AVALON_PIO_DATA(DOUT_BASE);
		if(k < 15)
			leftChannel <<= 1;

	}
	return leftChannel;
}

int I2S_collect_right(){
	int l = 0;
	int rightChannel = 0;
	//right channel LRCOUT = 1
	IOWR_ALTERA_AVALON_PIO_DATA(LRCOUT_BASE, 1);
    delay(3);
    IOWR_ALTERA_AVALON_PIO_DATA(BCLK_OUT_BASE, 0);
	delay(3);
	IOWR_ALTERA_AVALON_PIO_DATA(BCLK_OUT_BASE, 1);
	for(l = 0; l < 16; l++){
		IOWR_ALTERA_AVALON_PIO_DATA(BCLK_OUT_BASE, 0);
		delay(3);
		IOWR_ALTERA_AVALON_PIO_DATA(BCLK_OUT_BASE, 1);
		delay(3);
		rightChannel |= IORD_ALTERA_AVALON_PIO_DATA(DOUT_BASE);
		if(l < 15)
			rightChannel <<= 1;
	}

	return rightChannel;

}


void I2S_send_left(int leftdata){
	int temp = 0;

	//Toggle LRCIN to 0
	IOWR_ALTERA_AVALON_PIO_DATA(LRCIN_BASE, 0);
	delay(3);

	//first Bclk cycle
	IOWR_ALTERA_AVALON_PIO_DATA(BCLK_OUT_BASE, 0);
	delay(3);
	IOWR_ALTERA_AVALON_PIO_DATA(BCLK_OUT_BASE, 1);

	//Clock in the data
	for(temp = 0; temp < 16; temp++){
		//Insert the data to DIN_BASE
		IOWR_ALTERA_AVALON_PIO_DATA(DIN_BASE, !!(leftdata&0x1000));
		IOWR_ALTERA_AVALON_PIO_DATA(BCLK_OUT_BASE, 0);
		delay(3);
		IOWR_ALTERA_AVALON_PIO_DATA(BCLK_OUT_BASE, 1);
		delay(3);
		leftdata <<= 1;
	}
}


void I2S_send_right(int rightdata){
	int temp = 0;
	//Toggle LRCIN to 0
	IOWR_ALTERA_AVALON_PIO_DATA(0x81060, 1);
	delay(3);

	//first Bclk cycle
	IOWR_ALTERA_AVALON_PIO_DATA(BCLK_OUT_BASE, 0);
	delay(3);
	IOWR_ALTERA_AVALON_PIO_DATA(BCLK_OUT_BASE, 1);

	//Clock in the data
	for(temp = 0; temp < 16; temp++){
		//Insert the data to DIN_BASE
		IOWR_ALTERA_AVALON_PIO_DATA(DIN_BASE, !!(rightdata&0x1000));

		IOWR_ALTERA_AVALON_PIO_DATA(BCLK_OUT_BASE, 0);
		delay(3);
		IOWR_ALTERA_AVALON_PIO_DATA(BCLK_OUT_BASE, 1);
		delay(3);
		rightdata <<= 1;
	}
}


void I2S_send_lr(int left, int right){
	I2S_send_left(left);
	I2S_send_right(right);
}



