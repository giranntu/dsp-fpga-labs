/*
 * spi_control.c
 *
 *  Created on: Jan 18, 2014
 *      Author: atching
 *      Organization: University of Washington Electrical Engineering
 *		Notes: Intended for use by EE443 students
 *
 *		SPI control for bit banging
 */

#include "altera_avalon_pio_regs.h"
#include "system.h"
#include "delay.h"

void spi_send(unsigned int address, unsigned int data){
	int i = 0;

	IOWR_ALTERA_AVALON_PIO_DATA(CS_BASE, 0); // Begin
	delay(150);
	for(i = 0; i < 7; i++){
		if((address & 0x40) != 0){
			IOWR_ALTERA_AVALON_PIO_DATA(SDIN_BASE, 1);
			//printf("1");
		}else{
			IOWR_ALTERA_AVALON_PIO_DATA(SDIN_BASE, 0);
			//printf("0");
		}
		delay(1000);
		IOWR_ALTERA_AVALON_PIO_DATA(SCLK_BASE, 1);
		delay(1000);
		IOWR_ALTERA_AVALON_PIO_DATA(SCLK_BASE, 0);
		delay(1000);

		address <<= 1;
	}

	for(i = 0; i < 9; i++){
		if((data & 0x100) != 0){
			IOWR_ALTERA_AVALON_PIO_DATA(SDIN_BASE, 1);
			//printf("1");
		}else{
			IOWR_ALTERA_AVALON_PIO_DATA(SDIN_BASE, 0);
			//printf("0");
		}
		delay(1000);
		IOWR_ALTERA_AVALON_PIO_DATA(SCLK_BASE, 1);
		delay(1000);
		IOWR_ALTERA_AVALON_PIO_DATA(SCLK_BASE, 0);
		delay(1000);

		data <<= 1;
	}

	IOWR_ALTERA_AVALON_PIO_DATA(CS_BASE, 1); // Latches word to AIC
	//IOWR_ALTERA_AVALON_PIO_DATA(SCLK_BASE, 1);
}
