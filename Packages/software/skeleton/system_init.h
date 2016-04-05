/*
 * System_initialize.h
 *
 *  Created on: Feb 27, 2014
 *      Author: zhwj814
 */

#ifndef SYSTEM_INITIALIZE_H_
#define SYSTEM_INITIALIZE_H_
#endif /* SYSTEM_INITIALIZE_H_ */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


/*Library we made*/
#include "system.h"
#include "aic23.h"
#include "spi_control.h"
#include "i2s_control.h"
#include "delay.h"

/*Library for hardware interface*/
#include "altera_avalon_pio_regs.h"
#include "altera_avalon_uart_regs.h"
#include "altera_avalon_pio_regs.h"

/*Library for interrupt*/
#include "sys/alt_irq.h"
#include "priv/alt_legacy_irq.h"
#include "os/alt_hooks.h"
#include "alt_types.h"
#include "sys/alt_irq_entry.h"
#include "priv/alt_irq_table.h"
#include "sys/alt_irq.h"

/*Use for convolution*/
#define ELEMENT_COUNT(X) (sizeof(X) / sizeof((X)[0]))


/*Define constant values*/
#define WORDLENGTH 16
#define BUFFERSIZE 27
#define MULTIPLIER 10
#define CONVBUFFSIZE 1000
#define RX_BUFFER_SIZE 1024
#define TX_BUFFER_SIZE 1024
#define UART_SEND_DELAY 900
#define INT_SIZE 16
#define CHAR_SIZE 8


