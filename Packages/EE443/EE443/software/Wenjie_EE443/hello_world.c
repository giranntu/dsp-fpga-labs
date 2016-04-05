/*
 * "Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
 * device in your system's hardware.
 * The memory footprint of this hosted application is ~69 kbytes by default
 * using the standard reference design.
 *
 * For a reduced footprint version of this template, and an explanation of how
 * to reduce the memory footprint for a given application, see the
 * "small_hello_world" template.
 *
 */

#include <stdio.h>
#include <unistd.h>
#include <stdio.h>

#include "system.h"
#include "aic23.h"
#include "spi_control.h"
#include "i2s_control.h"
#include "delay.h"

#include "altera_avalon_pio_regs.h"
#include "altera_avalon_uart_regs.h"
#include "altera_avalon_pio_regs.h"

#include "sys/alt_irq.h"
#include "priv/alt_legacy_irq.h"
#include "os/alt_hooks.h"
#include "alt_types.h"
#include "sys/alt_irq_entry.h"
#include "priv/alt_irq_table.h"
#include "sys/alt_irq.h"


#define WORDLENGTH 16

alt_u32 switch0_id = SWITCH0_IRQ;
alt_u32 switch1_id = SWITCH1_IRQ;
alt_u32 key0_id = KEY0_IRQ;
alt_u32 key1_id = KEY1_IRQ;
alt_u32 key2_id = KEY2_IRQ;
alt_u32 key3_id = KEY3_IRQ;
alt_u32 lrcout_id = LRCOUT_IRQ;
alt_u32 lrcin_id = LRCIN_IRQ;
alt_u32 bclk_id = BCLK_OUT_IRQ;

int bclk_count = 0;
int channelFlag = 0;
int leftChannel = 0;
int rightChannel = 0;
int leftTemp = 0;
int rightTemp = 0;
int leftDataReady = 0;
int rightDataReady = 0;

int testCount = 0;
int globalCount = 0;


static void handle_switch0_interrupt(void* context, alt_u32 id) {
	 volatile int* switch0ptr = (volatile int *)context;
	 *switch0ptr = IORD_ALTERA_AVALON_PIO_EDGE_CAP(SWITCH0_BASE);

	 /* Write to the edge capture register to reset it. */
	 IOWR_ALTERA_AVALON_PIO_EDGE_CAP(SWITCH0_BASE, 0);

	 //IOWR_ALTERA_AVALON_PIO_IRQ_MASK(SWITCH0_BASE, 0);

	 //alt_irq_enable(bclk_id);
}

static void handle_switch1_interrupt(void* context, alt_u32 id) {
	 volatile int* switch1ptr = (volatile int *)context;
	 *switch1ptr = IORD_ALTERA_AVALON_PIO_EDGE_CAP(SWITCH1_BASE);

	 /* Write to the edge capture register to reset it. */
	 IOWR_ALTERA_AVALON_PIO_EDGE_CAP(SWITCH1_BASE, 0);

	 //IOWR_ALTERA_AVALON_PIO_IRQ_MASK(SWITCH1_BASE, 0x01);

	 IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 0xF0);

}

static void handle_key0_interrupt(void* context, alt_u32 id) {
	 volatile int* key0ptr = (volatile int *)context;
	 *key0ptr = IORD_ALTERA_AVALON_PIO_EDGE_CAP(KEY0_BASE);

	 /* Write to the edge capture register to reset it. */
	 IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEY0_BASE, 0);

	 //IOWR_ALTERA_AVALON_PIO_IRQ_MASK(SWITCH1_BASE, 0x01);

	 IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 0x80);
}


static void handle_key1_interrupt(void* context, alt_u32 id) {
	 volatile int* key1ptr = (volatile int *)context;
	 *key1ptr = IORD_ALTERA_AVALON_PIO_EDGE_CAP(KEY0_BASE);

	 /* Write to the edge capture register to reset it. */
	 IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEY1_BASE, 0);

	 //IOWR_ALTERA_AVALON_PIO_IRQ_MASK(SWITCH1_BASE, 0x01);

	 IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 0x40);
}

static void handle_key2_interrupt(void* context, alt_u32 id) {
	 volatile int* key2ptr = (volatile int *)context;
	 *key2ptr = IORD_ALTERA_AVALON_PIO_EDGE_CAP(KEY2_BASE);

	 /* Write to the edge capture register to reset it. */
	 IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEY2_BASE, 0);

	 //IOWR_ALTERA_AVALON_PIO_IRQ_MASK(SWITCH1_BASE, 0x01);

	 IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 0x20);
}

static void handle_key3_interrupt(void* context, alt_u32 id) {
	 volatile int* key3ptr = (volatile int *)context;
	 *key3ptr = IORD_ALTERA_AVALON_PIO_EDGE_CAP(KEY3_BASE);

	 /* Write to the edge capture register to reset it. */
	 IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEY3_BASE, 0);

	 //IOWR_ALTERA_AVALON_PIO_IRQ_MASK(SWITCH1_BASE, 0x01);

	 IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 0x10);
}


static void handle_lrcin_interrupt(void* context, alt_u32 id) {
	 volatile int* lrcinptr = (volatile int *)context;
	 *lrcinptr = IORD_ALTERA_AVALON_PIO_EDGE_CAP(LRCIN_BASE);

	 /* Write to the edge capture register to reset it. */
	 IOWR_ALTERA_AVALON_PIO_EDGE_CAP(LRCIN_BASE, 0);

	 //IOWR_ALTERA_AVALON_PIO_IRQ_MASK(SWITCH1_BASE, 0x01);

	 IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 0x10);
}


static void handle_lrcout_interrupt(void* context, alt_u32 id) {
	 volatile int* lrcoutptr = (volatile int *)context;
	 *lrcoutptr = IORD_ALTERA_AVALON_PIO_EDGE_CAP(LRCOUT_BASE);
	 IOWR_ALTERA_AVALON_PIO_EDGE_CAP(LRCOUT_BASE, 0);
	 globalCount = 0;

	 for(testCount = 0; testCount <100000000; testCount++){
	 //alt_irq_disable(lrcout_id);
		 globalCount++;
	 }

	 /* Write to the edge capture register to reset it. */


	 //reset bclk counter
	 //bclk_count = 0;

	 //IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 0xF0);
	 //alt_irq_enable(bclk_id);
	 //delay(50);
	 //Enable BCLK interrupt
	 //IOWR_ALTERA_AVALON_PIO_IRQ_MASK(LRCOUT_BASE, 0);
	 //alt_irq_enable(bclk_id);
}

static void handle_bclk_interrupt(void* context, alt_u32 id) {
	 volatile int* bclkptr = (volatile int *)context;
	 *bclkptr = IORD_ALTERA_AVALON_PIO_EDGE_CAP(BCLK_OUT_BASE);
	 /* Write to the edge capture register to reset it. */
	 IOWR_ALTERA_AVALON_PIO_EDGE_CAP(BCLK_OUT_BASE, 0);
	 if(IORD_ALTERA_AVALON_PIO_DATA(LRCOUT_BASE) == 0){
		 if(bclk_count > 1){
			 //collecting left channel data
			 leftTemp |= IORD_ALTERA_AVALON_PIO_DATA(DOUT_BASE);
			 leftTemp <<= 1;
			 if(bclk_count == (WORDLENGTH+1)){
				 //Data is updated: disable bclk interrupt and reset counter
				 leftChannel = leftTemp;
				 IOWR_ALTERA_AVALON_PIO_IRQ_MASK(BCLK_OUT_BASE, 0);
				 bclk_count = 0;
			 }
		 }
	 } else {
		 //collecting right channel data
		 rightTemp |= IORD_ALTERA_AVALON_PIO_DATA(DOUT_BASE);
		 rightTemp <<= 1;
		 if(bclk_count == (WORDLENGTH+1)){
			 //Data is updated: disable bclk interrupt and reset counter
			 rightChannel = rightTemp;
			 IOWR_ALTERA_AVALON_PIO_IRQ_MASK(BCLK_OUT_BASE, 0);
			 bclk_count = 0;
		 }
	 }
	 bclk_count++;
	 //IOWR_ALTERA_AVALON_PIO_IRQ_MASK(SWITCH1_BASE, 0x01);
}

static void handle_bclk_interrupt_test(void* context, alt_u32 id) {
	 //volatile int* bclkptr = (volatile int *)context;
	 //*bclkptr = IORD_ALTERA_AVALON_PIO_EDGE_CAP(BCLK_OUT_BASE);
	 IOWR_ALTERA_AVALON_PIO_EDGE_CAP(BCLK_OUT_BASE, 0);
	 //alt_irq_disable(bclk_id);
	 //alt_irq_enable(lrcout_id);
	 //alt_irq_disable(bclk_id);
	 bclk_count++;
	 /* Write to the edge capture register to reset it. */


	 //delay(50);
	 //IOWR_ALTERA_AVALON_PIO_IRQ_MASK(SWITCH1_BASE, 0x01);
}


int main(void) {
	volatile int switch0 = 0;
	volatile int switch1 = 0;
	volatile int key0 = 0;
	volatile int key1 = 0;
	volatile int key2 = 0;
	volatile int key3 = 0;
	volatile int lrcout = 0;
	volatile int lrcin = 0;
	volatile int bclk = 0;

	 //Interrupt Registration
//	 alt_irq_register(switch0_id, (void *)&switch0, handle_switch0_interrupt);
//	 alt_irq_register(switch1_id, (void *)&switch1, handle_switch1_interrupt);
//	 alt_irq_register(key0_id, (void *)&key0, handle_key0_interrupt);
//	 alt_irq_register(key1_id, (void *)&key1, handle_key1_interrupt);
//	 alt_irq_register(key2_id, (void *)&key2, handle_key2_interrupt);
//	 alt_irq_register(key3_id, (void *)&key3, handle_key3_interrupt);
//	 alt_irq_register(lrcout_id, (void *)&lrcout, handle_lrcout_interrupt);
//	 alt_irq_register(lrcin_id, (void *)&lrcin, handle_lrcin_interrupt);
//	 alt_irq_register(bclk_id, (void *)&bclk, handle_bclk_interrupt_test);
//	 alt_irq_disable(bclk_id);



	 /*Interrupt enable -> mask to enable it*/
	 IOWR_ALTERA_AVALON_PIO_IRQ_MASK(SWITCH0_BASE, 1);
	 IOWR_ALTERA_AVALON_PIO_IRQ_MASK(SWITCH1_BASE, 0);
	 IOWR_ALTERA_AVALON_PIO_IRQ_MASK(KEY0_BASE, 1);
	 IOWR_ALTERA_AVALON_PIO_IRQ_MASK(KEY1_BASE, 1);
	 IOWR_ALTERA_AVALON_PIO_IRQ_MASK(KEY2_BASE, 1);
	 IOWR_ALTERA_AVALON_PIO_IRQ_MASK(KEY3_BASE, 1);
	 IOWR_ALTERA_AVALON_PIO_IRQ_MASK(LRCOUT_BASE, 1);   //Disabled LRCOUT interrupt
	 IOWR_ALTERA_AVALON_PIO_IRQ_MASK(LRCIN_BASE, 0);    //Disabled LRCIN interrupt
	 IOWR_ALTERA_AVALON_PIO_IRQ_MASK(BCLK_OUT_BASE, 1); //Disabled BCLK interrupt


	 IOWR_ALTERA_AVALON_PIO_EDGE_CAP(SWITCH0_BASE, 0);
	 IOWR_ALTERA_AVALON_PIO_EDGE_CAP(SWITCH1_BASE, 0);
	 IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEY0_BASE, 0);
	 IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEY1_BASE, 0);
	 IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEY2_BASE, 0);
	 IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEY3_BASE, 0);
	 IOWR_ALTERA_AVALON_PIO_EDGE_CAP(LRCOUT_BASE, 0);
	 IOWR_ALTERA_AVALON_PIO_EDGE_CAP(LRCIN_BASE, 0);
	 IOWR_ALTERA_AVALON_PIO_EDGE_CAP(BCLK_OUT_BASE, 0);


	 IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 0x00);

	 IOWR_ALTERA_AVALON_PIO_DATA(CS_BASE, 1); // ~CS low
	 IOWR_ALTERA_AVALON_PIO_DATA(SCLK_BASE, 0); // Initialize SCLK to high

	 AIC23_demo();

	 while(1){
//		 if(IORD_ALTERA_AVALON_PIO_DATA(SWITCH0_BASE) == 1){
//			 //enable LRCOUT
//			 alt_irq_enable(bclk_id);
//
//		 } else {
//			 alt_irq_disable(bclk_id);
//		 }

//		 printf("main running...\n");
//		 IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 0x00);
		 //alt_irq_enable(lrcout_id);
	 }
	 return 0;
}
