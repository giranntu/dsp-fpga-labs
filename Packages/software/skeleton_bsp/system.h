/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2_qsys' in SOPC Builder design 'de2i_150'
 * SOPC Builder design path: C:/Users/Jake/Desktop/443/Packages/de2i_150.sopcinfo
 *
 * Generated: Tue Apr 05 12:25:02 PDT 2016
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_qsys"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x80820
#define ALT_CPU_CPU_FREQ 160000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "fast"
#define ALT_CPU_DATA_ADDR_WIDTH 0x14
#define ALT_CPU_DCACHE_LINE_SIZE 32
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_DCACHE_SIZE 2048
#define ALT_CPU_EXCEPTION_ADDR 0x40020
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 160000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 1
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 32
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_ICACHE_SIZE 4096
#define ALT_CPU_INITDA_SUPPORTED
#define ALT_CPU_INST_ADDR_WIDTH 0x14
#define ALT_CPU_NAME "nios2_qsys"
#define ALT_CPU_NUM_OF_SHADOW_REG_SETS 0
#define ALT_CPU_RESET_ADDR 0x40000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x80820
#define NIOS2_CPU_FREQ 160000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "fast"
#define NIOS2_DATA_ADDR_WIDTH 0x14
#define NIOS2_DCACHE_LINE_SIZE 32
#define NIOS2_DCACHE_LINE_SIZE_LOG2 5
#define NIOS2_DCACHE_SIZE 2048
#define NIOS2_EXCEPTION_ADDR 0x40020
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 1
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_ICACHE_LINE_SIZE_LOG2 5
#define NIOS2_ICACHE_SIZE 4096
#define NIOS2_INITDA_SUPPORTED
#define NIOS2_INST_ADDR_WIDTH 0x14
#define NIOS2_NUM_OF_SHADOW_REG_SETS 0
#define NIOS2_RESET_ADDR 0x40000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_AVALON_UART
#define __ALTERA_NIOS2_QSYS
#define __ALTPLL


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone IV GX"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart"
#define ALT_STDERR_BASE 0x81228
#define ALT_STDERR_DEV jtag_uart
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart"
#define ALT_STDIN_BASE 0x81228
#define ALT_STDIN_DEV jtag_uart
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart"
#define ALT_STDOUT_BASE 0x81228
#define ALT_STDOUT_DEV jtag_uart
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "de2i_150"


/*
 * adc configuration
 *
 */

#define ADC_BASE 0x811e0
#define ADC_BIT_CLEARING_EDGE_REGISTER 0
#define ADC_BIT_MODIFYING_OUTPUT_REGISTER 0
#define ADC_CAPTURE 0
#define ADC_DATA_WIDTH 14
#define ADC_DO_TEST_BENCH_WIRING 0
#define ADC_DRIVEN_SIM_VALUE 0
#define ADC_EDGE_TYPE "NONE"
#define ADC_FREQ 160000000
#define ADC_HAS_IN 1
#define ADC_HAS_OUT 0
#define ADC_HAS_TRI 0
#define ADC_IRQ -1
#define ADC_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ADC_IRQ_TYPE "NONE"
#define ADC_NAME "/dev/adc"
#define ADC_RESET_VALUE 0
#define ADC_SPAN 16
#define ADC_TYPE "altera_avalon_pio"
#define ALT_MODULE_CLASS_adc altera_avalon_pio


/*
 * altpll_0 configuration
 *
 */

#define ALTPLL_0_BASE 0x810d0
#define ALTPLL_0_IRQ -1
#define ALTPLL_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ALTPLL_0_NAME "/dev/altpll_0"
#define ALTPLL_0_SPAN 16
#define ALTPLL_0_TYPE "altpll"
#define ALT_MODULE_CLASS_altpll_0 altpll


/*
 * bclk_in configuration
 *
 */

#define ALT_MODULE_CLASS_bclk_in altera_avalon_pio
#define BCLK_IN_BASE 0x81190
#define BCLK_IN_BIT_CLEARING_EDGE_REGISTER 0
#define BCLK_IN_BIT_MODIFYING_OUTPUT_REGISTER 0
#define BCLK_IN_CAPTURE 1
#define BCLK_IN_DATA_WIDTH 1
#define BCLK_IN_DO_TEST_BENCH_WIRING 0
#define BCLK_IN_DRIVEN_SIM_VALUE 0
#define BCLK_IN_EDGE_TYPE "RISING"
#define BCLK_IN_FREQ 160000000
#define BCLK_IN_HAS_IN 1
#define BCLK_IN_HAS_OUT 0
#define BCLK_IN_HAS_TRI 0
#define BCLK_IN_IRQ 15
#define BCLK_IN_IRQ_INTERRUPT_CONTROLLER_ID 0
#define BCLK_IN_IRQ_TYPE "EDGE"
#define BCLK_IN_NAME "/dev/bclk_in"
#define BCLK_IN_RESET_VALUE 0
#define BCLK_IN_SPAN 16
#define BCLK_IN_TYPE "altera_avalon_pio"


/*
 * bclk_out configuration
 *
 */

#define ALT_MODULE_CLASS_bclk_out altera_avalon_pio
#define BCLK_OUT_BASE 0x81160
#define BCLK_OUT_BIT_CLEARING_EDGE_REGISTER 0
#define BCLK_OUT_BIT_MODIFYING_OUTPUT_REGISTER 0
#define BCLK_OUT_CAPTURE 1
#define BCLK_OUT_DATA_WIDTH 1
#define BCLK_OUT_DO_TEST_BENCH_WIRING 0
#define BCLK_OUT_DRIVEN_SIM_VALUE 0
#define BCLK_OUT_EDGE_TYPE "RISING"
#define BCLK_OUT_FREQ 160000000
#define BCLK_OUT_HAS_IN 1
#define BCLK_OUT_HAS_OUT 0
#define BCLK_OUT_HAS_TRI 0
#define BCLK_OUT_IRQ 2
#define BCLK_OUT_IRQ_INTERRUPT_CONTROLLER_ID 0
#define BCLK_OUT_IRQ_TYPE "EDGE"
#define BCLK_OUT_NAME "/dev/bclk_out"
#define BCLK_OUT_RESET_VALUE 0
#define BCLK_OUT_SPAN 16
#define BCLK_OUT_TYPE "altera_avalon_pio"


/*
 * clk_12mhz configuration
 *
 */

#define ALT_MODULE_CLASS_clk_12mhz altpll
#define CLK_12MHZ_BASE 0x81060
#define CLK_12MHZ_IRQ -1
#define CLK_12MHZ_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CLK_12MHZ_NAME "/dev/clk_12mhz"
#define CLK_12MHZ_SPAN 16
#define CLK_12MHZ_TYPE "altpll"


/*
 * cs configuration
 *
 */

#define ALT_MODULE_CLASS_cs altera_avalon_pio
#define CS_BASE 0x811d0
#define CS_BIT_CLEARING_EDGE_REGISTER 0
#define CS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define CS_CAPTURE 0
#define CS_DATA_WIDTH 1
#define CS_DO_TEST_BENCH_WIRING 0
#define CS_DRIVEN_SIM_VALUE 0
#define CS_EDGE_TYPE "NONE"
#define CS_FREQ 160000000
#define CS_HAS_IN 0
#define CS_HAS_OUT 1
#define CS_HAS_TRI 0
#define CS_IRQ -1
#define CS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CS_IRQ_TYPE "NONE"
#define CS_NAME "/dev/cs"
#define CS_RESET_VALUE 0
#define CS_SPAN 16
#define CS_TYPE "altera_avalon_pio"


/*
 * din configuration
 *
 */

#define ALT_MODULE_CLASS_din altera_avalon_pio
#define DIN_BASE 0x811a0
#define DIN_BIT_CLEARING_EDGE_REGISTER 0
#define DIN_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DIN_CAPTURE 0
#define DIN_DATA_WIDTH 1
#define DIN_DO_TEST_BENCH_WIRING 0
#define DIN_DRIVEN_SIM_VALUE 0
#define DIN_EDGE_TYPE "NONE"
#define DIN_FREQ 160000000
#define DIN_HAS_IN 0
#define DIN_HAS_OUT 1
#define DIN_HAS_TRI 0
#define DIN_IRQ -1
#define DIN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DIN_IRQ_TYPE "NONE"
#define DIN_NAME "/dev/din"
#define DIN_RESET_VALUE 0
#define DIN_SPAN 16
#define DIN_TYPE "altera_avalon_pio"


/*
 * dout configuration
 *
 */

#define ALT_MODULE_CLASS_dout altera_avalon_pio
#define DOUT_BASE 0x81170
#define DOUT_BIT_CLEARING_EDGE_REGISTER 0
#define DOUT_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DOUT_CAPTURE 0
#define DOUT_DATA_WIDTH 1
#define DOUT_DO_TEST_BENCH_WIRING 0
#define DOUT_DRIVEN_SIM_VALUE 0
#define DOUT_EDGE_TYPE "NONE"
#define DOUT_FREQ 160000000
#define DOUT_HAS_IN 1
#define DOUT_HAS_OUT 0
#define DOUT_HAS_TRI 0
#define DOUT_IRQ -1
#define DOUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DOUT_IRQ_TYPE "NONE"
#define DOUT_NAME "/dev/dout"
#define DOUT_RESET_VALUE 0
#define DOUT_SPAN 16
#define DOUT_TYPE "altera_avalon_pio"


/*
 * hal configuration
 *
 */

#define ALT_MAX_FD 32
#define ALT_SYS_CLK none
#define ALT_TIMESTAMP_CLK none


/*
 * jtag_uart configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart altera_avalon_jtag_uart
#define JTAG_UART_BASE 0x81228
#define JTAG_UART_IRQ 0
#define JTAG_UART_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_NAME "/dev/jtag_uart"
#define JTAG_UART_READ_DEPTH 64
#define JTAG_UART_READ_THRESHOLD 8
#define JTAG_UART_SPAN 8
#define JTAG_UART_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_WRITE_DEPTH 64
#define JTAG_UART_WRITE_THRESHOLD 8


/*
 * key0 configuration
 *
 */

#define ALT_MODULE_CLASS_key0 altera_avalon_pio
#define KEY0_BASE 0x811f0
#define KEY0_BIT_CLEARING_EDGE_REGISTER 0
#define KEY0_BIT_MODIFYING_OUTPUT_REGISTER 0
#define KEY0_CAPTURE 1
#define KEY0_DATA_WIDTH 1
#define KEY0_DO_TEST_BENCH_WIRING 0
#define KEY0_DRIVEN_SIM_VALUE 0
#define KEY0_EDGE_TYPE "RISING"
#define KEY0_FREQ 160000000
#define KEY0_HAS_IN 1
#define KEY0_HAS_OUT 0
#define KEY0_HAS_TRI 0
#define KEY0_IRQ 8
#define KEY0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define KEY0_IRQ_TYPE "EDGE"
#define KEY0_NAME "/dev/key0"
#define KEY0_RESET_VALUE 0
#define KEY0_SPAN 16
#define KEY0_TYPE "altera_avalon_pio"


/*
 * key1 configuration
 *
 */

#define ALT_MODULE_CLASS_key1 altera_avalon_pio
#define KEY1_BASE 0x81140
#define KEY1_BIT_CLEARING_EDGE_REGISTER 0
#define KEY1_BIT_MODIFYING_OUTPUT_REGISTER 0
#define KEY1_CAPTURE 1
#define KEY1_DATA_WIDTH 1
#define KEY1_DO_TEST_BENCH_WIRING 0
#define KEY1_DRIVEN_SIM_VALUE 0
#define KEY1_EDGE_TYPE "RISING"
#define KEY1_FREQ 160000000
#define KEY1_HAS_IN 1
#define KEY1_HAS_OUT 0
#define KEY1_HAS_TRI 0
#define KEY1_IRQ 4
#define KEY1_IRQ_INTERRUPT_CONTROLLER_ID 0
#define KEY1_IRQ_TYPE "EDGE"
#define KEY1_NAME "/dev/key1"
#define KEY1_RESET_VALUE 0
#define KEY1_SPAN 16
#define KEY1_TYPE "altera_avalon_pio"


/*
 * key2 configuration
 *
 */

#define ALT_MODULE_CLASS_key2 altera_avalon_pio
#define KEY2_BASE 0x81130
#define KEY2_BIT_CLEARING_EDGE_REGISTER 0
#define KEY2_BIT_MODIFYING_OUTPUT_REGISTER 0
#define KEY2_CAPTURE 1
#define KEY2_DATA_WIDTH 1
#define KEY2_DO_TEST_BENCH_WIRING 0
#define KEY2_DRIVEN_SIM_VALUE 0
#define KEY2_EDGE_TYPE "RISING"
#define KEY2_FREQ 160000000
#define KEY2_HAS_IN 1
#define KEY2_HAS_OUT 0
#define KEY2_HAS_TRI 0
#define KEY2_IRQ 5
#define KEY2_IRQ_INTERRUPT_CONTROLLER_ID 0
#define KEY2_IRQ_TYPE "EDGE"
#define KEY2_NAME "/dev/key2"
#define KEY2_RESET_VALUE 0
#define KEY2_SPAN 16
#define KEY2_TYPE "altera_avalon_pio"


/*
 * key3 configuration
 *
 */

#define ALT_MODULE_CLASS_key3 altera_avalon_pio
#define KEY3_BASE 0x81120
#define KEY3_BIT_CLEARING_EDGE_REGISTER 0
#define KEY3_BIT_MODIFYING_OUTPUT_REGISTER 0
#define KEY3_CAPTURE 1
#define KEY3_DATA_WIDTH 1
#define KEY3_DO_TEST_BENCH_WIRING 0
#define KEY3_DRIVEN_SIM_VALUE 0
#define KEY3_EDGE_TYPE "RISING"
#define KEY3_FREQ 160000000
#define KEY3_HAS_IN 1
#define KEY3_HAS_OUT 0
#define KEY3_HAS_TRI 0
#define KEY3_IRQ 6
#define KEY3_IRQ_INTERRUPT_CONTROLLER_ID 0
#define KEY3_IRQ_TYPE "EDGE"
#define KEY3_NAME "/dev/key3"
#define KEY3_RESET_VALUE 0
#define KEY3_SPAN 16
#define KEY3_TYPE "altera_avalon_pio"


/*
 * led configuration
 *
 */

#define ALT_MODULE_CLASS_led altera_avalon_pio
#define LED_BASE 0x81210
#define LED_BIT_CLEARING_EDGE_REGISTER 0
#define LED_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LED_CAPTURE 0
#define LED_DATA_WIDTH 8
#define LED_DO_TEST_BENCH_WIRING 0
#define LED_DRIVEN_SIM_VALUE 0
#define LED_EDGE_TYPE "NONE"
#define LED_FREQ 160000000
#define LED_HAS_IN 0
#define LED_HAS_OUT 1
#define LED_HAS_TRI 0
#define LED_IRQ -1
#define LED_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LED_IRQ_TYPE "NONE"
#define LED_NAME "/dev/led"
#define LED_RESET_VALUE 0
#define LED_SPAN 16
#define LED_TYPE "altera_avalon_pio"


/*
 * leftdata configuration
 *
 */

#define ALT_MODULE_CLASS_leftdata altera_avalon_pio
#define LEFTDATA_BASE 0x810c0
#define LEFTDATA_BIT_CLEARING_EDGE_REGISTER 0
#define LEFTDATA_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LEFTDATA_CAPTURE 0
#define LEFTDATA_DATA_WIDTH 16
#define LEFTDATA_DO_TEST_BENCH_WIRING 0
#define LEFTDATA_DRIVEN_SIM_VALUE 0
#define LEFTDATA_EDGE_TYPE "NONE"
#define LEFTDATA_FREQ 160000000
#define LEFTDATA_HAS_IN 1
#define LEFTDATA_HAS_OUT 0
#define LEFTDATA_HAS_TRI 0
#define LEFTDATA_IRQ -1
#define LEFTDATA_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LEFTDATA_IRQ_TYPE "NONE"
#define LEFTDATA_NAME "/dev/leftdata"
#define LEFTDATA_RESET_VALUE 0
#define LEFTDATA_SPAN 16
#define LEFTDATA_TYPE "altera_avalon_pio"


/*
 * leftready configuration
 *
 */

#define ALT_MODULE_CLASS_leftready altera_avalon_pio
#define LEFTREADY_BASE 0x810a0
#define LEFTREADY_BIT_CLEARING_EDGE_REGISTER 0
#define LEFTREADY_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LEFTREADY_CAPTURE 1
#define LEFTREADY_DATA_WIDTH 1
#define LEFTREADY_DO_TEST_BENCH_WIRING 0
#define LEFTREADY_DRIVEN_SIM_VALUE 0
#define LEFTREADY_EDGE_TYPE "RISING"
#define LEFTREADY_FREQ 160000000
#define LEFTREADY_HAS_IN 1
#define LEFTREADY_HAS_OUT 0
#define LEFTREADY_HAS_TRI 0
#define LEFTREADY_IRQ 13
#define LEFTREADY_IRQ_INTERRUPT_CONTROLLER_ID 0
#define LEFTREADY_IRQ_TYPE "EDGE"
#define LEFTREADY_NAME "/dev/leftready"
#define LEFTREADY_RESET_VALUE 0
#define LEFTREADY_SPAN 16
#define LEFTREADY_TYPE "altera_avalon_pio"


/*
 * leftsenddata configuration
 *
 */

#define ALT_MODULE_CLASS_leftsenddata altera_avalon_pio
#define LEFTSENDDATA_BASE 0x81080
#define LEFTSENDDATA_BIT_CLEARING_EDGE_REGISTER 0
#define LEFTSENDDATA_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LEFTSENDDATA_CAPTURE 0
#define LEFTSENDDATA_DATA_WIDTH 16
#define LEFTSENDDATA_DO_TEST_BENCH_WIRING 0
#define LEFTSENDDATA_DRIVEN_SIM_VALUE 0
#define LEFTSENDDATA_EDGE_TYPE "NONE"
#define LEFTSENDDATA_FREQ 160000000
#define LEFTSENDDATA_HAS_IN 0
#define LEFTSENDDATA_HAS_OUT 1
#define LEFTSENDDATA_HAS_TRI 0
#define LEFTSENDDATA_IRQ -1
#define LEFTSENDDATA_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LEFTSENDDATA_IRQ_TYPE "NONE"
#define LEFTSENDDATA_NAME "/dev/leftsenddata"
#define LEFTSENDDATA_RESET_VALUE 0
#define LEFTSENDDATA_SPAN 16
#define LEFTSENDDATA_TYPE "altera_avalon_pio"


/*
 * lrcin configuration
 *
 */

#define ALT_MODULE_CLASS_lrcin altera_avalon_pio
#define LRCIN_BASE 0x81150
#define LRCIN_BIT_CLEARING_EDGE_REGISTER 0
#define LRCIN_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LRCIN_CAPTURE 1
#define LRCIN_DATA_WIDTH 1
#define LRCIN_DO_TEST_BENCH_WIRING 0
#define LRCIN_DRIVEN_SIM_VALUE 0
#define LRCIN_EDGE_TYPE "ANY"
#define LRCIN_FREQ 160000000
#define LRCIN_HAS_IN 1
#define LRCIN_HAS_OUT 0
#define LRCIN_HAS_TRI 0
#define LRCIN_IRQ 3
#define LRCIN_IRQ_INTERRUPT_CONTROLLER_ID 0
#define LRCIN_IRQ_TYPE "EDGE"
#define LRCIN_NAME "/dev/lrcin"
#define LRCIN_RESET_VALUE 0
#define LRCIN_SPAN 16
#define LRCIN_TYPE "altera_avalon_pio"


/*
 * lrcout configuration
 *
 */

#define ALT_MODULE_CLASS_lrcout altera_avalon_pio
#define LRCOUT_BASE 0x81180
#define LRCOUT_BIT_CLEARING_EDGE_REGISTER 0
#define LRCOUT_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LRCOUT_CAPTURE 1
#define LRCOUT_DATA_WIDTH 1
#define LRCOUT_DO_TEST_BENCH_WIRING 0
#define LRCOUT_DRIVEN_SIM_VALUE 0
#define LRCOUT_EDGE_TYPE "ANY"
#define LRCOUT_FREQ 160000000
#define LRCOUT_HAS_IN 1
#define LRCOUT_HAS_OUT 0
#define LRCOUT_HAS_TRI 0
#define LRCOUT_IRQ 16
#define LRCOUT_IRQ_INTERRUPT_CONTROLLER_ID 0
#define LRCOUT_IRQ_TYPE "EDGE"
#define LRCOUT_NAME "/dev/lrcout"
#define LRCOUT_RESET_VALUE 0
#define LRCOUT_SPAN 16
#define LRCOUT_TYPE "altera_avalon_pio"


/*
 * onchip_memory2 configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_memory2 altera_avalon_onchip_memory2
#define ONCHIP_MEMORY2_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_MEMORY2_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_MEMORY2_BASE 0x40000
#define ONCHIP_MEMORY2_CONTENTS_INFO ""
#define ONCHIP_MEMORY2_DUAL_PORT 0
#define ONCHIP_MEMORY2_GUI_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_INIT_CONTENTS_FILE "de2i_150_onchip_memory2"
#define ONCHIP_MEMORY2_INIT_MEM_CONTENT 1
#define ONCHIP_MEMORY2_INSTANCE_ID "NONE"
#define ONCHIP_MEMORY2_IRQ -1
#define ONCHIP_MEMORY2_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_MEMORY2_NAME "/dev/onchip_memory2"
#define ONCHIP_MEMORY2_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_MEMORY2_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_MEMORY2_SINGLE_CLOCK_OP 0
#define ONCHIP_MEMORY2_SIZE_MULTIPLE 1
#define ONCHIP_MEMORY2_SIZE_VALUE 204800
#define ONCHIP_MEMORY2_SPAN 204800
#define ONCHIP_MEMORY2_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_MEMORY2_WRITABLE 1


/*
 * rightdata configuration
 *
 */

#define ALT_MODULE_CLASS_rightdata altera_avalon_pio
#define RIGHTDATA_BASE 0x810b0
#define RIGHTDATA_BIT_CLEARING_EDGE_REGISTER 0
#define RIGHTDATA_BIT_MODIFYING_OUTPUT_REGISTER 0
#define RIGHTDATA_CAPTURE 0
#define RIGHTDATA_DATA_WIDTH 16
#define RIGHTDATA_DO_TEST_BENCH_WIRING 0
#define RIGHTDATA_DRIVEN_SIM_VALUE 0
#define RIGHTDATA_EDGE_TYPE "NONE"
#define RIGHTDATA_FREQ 160000000
#define RIGHTDATA_HAS_IN 1
#define RIGHTDATA_HAS_OUT 0
#define RIGHTDATA_HAS_TRI 0
#define RIGHTDATA_IRQ -1
#define RIGHTDATA_IRQ_INTERRUPT_CONTROLLER_ID -1
#define RIGHTDATA_IRQ_TYPE "NONE"
#define RIGHTDATA_NAME "/dev/rightdata"
#define RIGHTDATA_RESET_VALUE 0
#define RIGHTDATA_SPAN 16
#define RIGHTDATA_TYPE "altera_avalon_pio"


/*
 * rightready configuration
 *
 */

#define ALT_MODULE_CLASS_rightready altera_avalon_pio
#define RIGHTREADY_BASE 0x81090
#define RIGHTREADY_BIT_CLEARING_EDGE_REGISTER 0
#define RIGHTREADY_BIT_MODIFYING_OUTPUT_REGISTER 0
#define RIGHTREADY_CAPTURE 1
#define RIGHTREADY_DATA_WIDTH 1
#define RIGHTREADY_DO_TEST_BENCH_WIRING 0
#define RIGHTREADY_DRIVEN_SIM_VALUE 0
#define RIGHTREADY_EDGE_TYPE "RISING"
#define RIGHTREADY_FREQ 160000000
#define RIGHTREADY_HAS_IN 1
#define RIGHTREADY_HAS_OUT 0
#define RIGHTREADY_HAS_TRI 0
#define RIGHTREADY_IRQ 14
#define RIGHTREADY_IRQ_INTERRUPT_CONTROLLER_ID 0
#define RIGHTREADY_IRQ_TYPE "EDGE"
#define RIGHTREADY_NAME "/dev/rightready"
#define RIGHTREADY_RESET_VALUE 0
#define RIGHTREADY_SPAN 16
#define RIGHTREADY_TYPE "altera_avalon_pio"


/*
 * rightsenddata configuration
 *
 */

#define ALT_MODULE_CLASS_rightsenddata altera_avalon_pio
#define RIGHTSENDDATA_BASE 0x81070
#define RIGHTSENDDATA_BIT_CLEARING_EDGE_REGISTER 0
#define RIGHTSENDDATA_BIT_MODIFYING_OUTPUT_REGISTER 0
#define RIGHTSENDDATA_CAPTURE 0
#define RIGHTSENDDATA_DATA_WIDTH 16
#define RIGHTSENDDATA_DO_TEST_BENCH_WIRING 0
#define RIGHTSENDDATA_DRIVEN_SIM_VALUE 0
#define RIGHTSENDDATA_EDGE_TYPE "NONE"
#define RIGHTSENDDATA_FREQ 160000000
#define RIGHTSENDDATA_HAS_IN 0
#define RIGHTSENDDATA_HAS_OUT 1
#define RIGHTSENDDATA_HAS_TRI 0
#define RIGHTSENDDATA_IRQ -1
#define RIGHTSENDDATA_IRQ_INTERRUPT_CONTROLLER_ID -1
#define RIGHTSENDDATA_IRQ_TYPE "NONE"
#define RIGHTSENDDATA_NAME "/dev/rightsenddata"
#define RIGHTSENDDATA_RESET_VALUE 0
#define RIGHTSENDDATA_SPAN 16
#define RIGHTSENDDATA_TYPE "altera_avalon_pio"


/*
 * sclk configuration
 *
 */

#define ALT_MODULE_CLASS_sclk altera_avalon_pio
#define SCLK_BASE 0x811c0
#define SCLK_BIT_CLEARING_EDGE_REGISTER 0
#define SCLK_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SCLK_CAPTURE 0
#define SCLK_DATA_WIDTH 1
#define SCLK_DO_TEST_BENCH_WIRING 0
#define SCLK_DRIVEN_SIM_VALUE 0
#define SCLK_EDGE_TYPE "NONE"
#define SCLK_FREQ 160000000
#define SCLK_HAS_IN 0
#define SCLK_HAS_OUT 1
#define SCLK_HAS_TRI 0
#define SCLK_IRQ -1
#define SCLK_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SCLK_IRQ_TYPE "NONE"
#define SCLK_NAME "/dev/sclk"
#define SCLK_RESET_VALUE 0
#define SCLK_SPAN 16
#define SCLK_TYPE "altera_avalon_pio"


/*
 * sdin configuration
 *
 */

#define ALT_MODULE_CLASS_sdin altera_avalon_pio
#define SDIN_BASE 0x811b0
#define SDIN_BIT_CLEARING_EDGE_REGISTER 0
#define SDIN_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SDIN_CAPTURE 0
#define SDIN_DATA_WIDTH 1
#define SDIN_DO_TEST_BENCH_WIRING 0
#define SDIN_DRIVEN_SIM_VALUE 0
#define SDIN_EDGE_TYPE "NONE"
#define SDIN_FREQ 160000000
#define SDIN_HAS_IN 0
#define SDIN_HAS_OUT 1
#define SDIN_HAS_TRI 0
#define SDIN_IRQ -1
#define SDIN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SDIN_IRQ_TYPE "NONE"
#define SDIN_NAME "/dev/sdin"
#define SDIN_RESET_VALUE 0
#define SDIN_SPAN 16
#define SDIN_TYPE "altera_avalon_pio"


/*
 * switch0 configuration
 *
 */

#define ALT_MODULE_CLASS_switch0 altera_avalon_pio
#define SWITCH0_BASE 0x81200
#define SWITCH0_BIT_CLEARING_EDGE_REGISTER 0
#define SWITCH0_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SWITCH0_CAPTURE 1
#define SWITCH0_DATA_WIDTH 1
#define SWITCH0_DO_TEST_BENCH_WIRING 0
#define SWITCH0_DRIVEN_SIM_VALUE 0
#define SWITCH0_EDGE_TYPE "ANY"
#define SWITCH0_FREQ 160000000
#define SWITCH0_HAS_IN 1
#define SWITCH0_HAS_OUT 0
#define SWITCH0_HAS_TRI 0
#define SWITCH0_IRQ 7
#define SWITCH0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define SWITCH0_IRQ_TYPE "EDGE"
#define SWITCH0_NAME "/dev/switch0"
#define SWITCH0_RESET_VALUE 0
#define SWITCH0_SPAN 16
#define SWITCH0_TYPE "altera_avalon_pio"


/*
 * switch1 configuration
 *
 */

#define ALT_MODULE_CLASS_switch1 altera_avalon_pio
#define SWITCH1_BASE 0x81110
#define SWITCH1_BIT_CLEARING_EDGE_REGISTER 0
#define SWITCH1_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SWITCH1_CAPTURE 1
#define SWITCH1_DATA_WIDTH 1
#define SWITCH1_DO_TEST_BENCH_WIRING 0
#define SWITCH1_DRIVEN_SIM_VALUE 0
#define SWITCH1_EDGE_TYPE "ANY"
#define SWITCH1_FREQ 160000000
#define SWITCH1_HAS_IN 1
#define SWITCH1_HAS_OUT 0
#define SWITCH1_HAS_TRI 0
#define SWITCH1_IRQ 9
#define SWITCH1_IRQ_INTERRUPT_CONTROLLER_ID 0
#define SWITCH1_IRQ_TYPE "EDGE"
#define SWITCH1_NAME "/dev/switch1"
#define SWITCH1_RESET_VALUE 0
#define SWITCH1_SPAN 16
#define SWITCH1_TYPE "altera_avalon_pio"


/*
 * switch2 configuration
 *
 */

#define ALT_MODULE_CLASS_switch2 altera_avalon_pio
#define SWITCH2_BASE 0x81100
#define SWITCH2_BIT_CLEARING_EDGE_REGISTER 0
#define SWITCH2_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SWITCH2_CAPTURE 1
#define SWITCH2_DATA_WIDTH 1
#define SWITCH2_DO_TEST_BENCH_WIRING 0
#define SWITCH2_DRIVEN_SIM_VALUE 0
#define SWITCH2_EDGE_TYPE "ANY"
#define SWITCH2_FREQ 160000000
#define SWITCH2_HAS_IN 1
#define SWITCH2_HAS_OUT 0
#define SWITCH2_HAS_TRI 0
#define SWITCH2_IRQ 10
#define SWITCH2_IRQ_INTERRUPT_CONTROLLER_ID 0
#define SWITCH2_IRQ_TYPE "EDGE"
#define SWITCH2_NAME "/dev/switch2"
#define SWITCH2_RESET_VALUE 0
#define SWITCH2_SPAN 16
#define SWITCH2_TYPE "altera_avalon_pio"


/*
 * switch3 configuration
 *
 */

#define ALT_MODULE_CLASS_switch3 altera_avalon_pio
#define SWITCH3_BASE 0x810f0
#define SWITCH3_BIT_CLEARING_EDGE_REGISTER 0
#define SWITCH3_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SWITCH3_CAPTURE 1
#define SWITCH3_DATA_WIDTH 1
#define SWITCH3_DO_TEST_BENCH_WIRING 0
#define SWITCH3_DRIVEN_SIM_VALUE 0
#define SWITCH3_EDGE_TYPE "ANY"
#define SWITCH3_FREQ 160000000
#define SWITCH3_HAS_IN 1
#define SWITCH3_HAS_OUT 0
#define SWITCH3_HAS_TRI 0
#define SWITCH3_IRQ 11
#define SWITCH3_IRQ_INTERRUPT_CONTROLLER_ID 0
#define SWITCH3_IRQ_TYPE "EDGE"
#define SWITCH3_NAME "/dev/switch3"
#define SWITCH3_RESET_VALUE 0
#define SWITCH3_SPAN 16
#define SWITCH3_TYPE "altera_avalon_pio"


/*
 * switch4 configuration
 *
 */

#define ALT_MODULE_CLASS_switch4 altera_avalon_pio
#define SWITCH4_BASE 0x810e0
#define SWITCH4_BIT_CLEARING_EDGE_REGISTER 0
#define SWITCH4_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SWITCH4_CAPTURE 1
#define SWITCH4_DATA_WIDTH 1
#define SWITCH4_DO_TEST_BENCH_WIRING 0
#define SWITCH4_DRIVEN_SIM_VALUE 0
#define SWITCH4_EDGE_TYPE "ANY"
#define SWITCH4_FREQ 160000000
#define SWITCH4_HAS_IN 1
#define SWITCH4_HAS_OUT 0
#define SWITCH4_HAS_TRI 0
#define SWITCH4_IRQ 12
#define SWITCH4_IRQ_INTERRUPT_CONTROLLER_ID 0
#define SWITCH4_IRQ_TYPE "EDGE"
#define SWITCH4_NAME "/dev/switch4"
#define SWITCH4_RESET_VALUE 0
#define SWITCH4_SPAN 16
#define SWITCH4_TYPE "altera_avalon_pio"


/*
 * switch5 configuration
 *
 */

#define ALT_MODULE_CLASS_switch5 altera_avalon_pio
#define SWITCH5_BASE 0x81050
#define SWITCH5_BIT_CLEARING_EDGE_REGISTER 0
#define SWITCH5_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SWITCH5_CAPTURE 1
#define SWITCH5_DATA_WIDTH 1
#define SWITCH5_DO_TEST_BENCH_WIRING 0
#define SWITCH5_DRIVEN_SIM_VALUE 0
#define SWITCH5_EDGE_TYPE "ANY"
#define SWITCH5_FREQ 160000000
#define SWITCH5_HAS_IN 1
#define SWITCH5_HAS_OUT 0
#define SWITCH5_HAS_TRI 0
#define SWITCH5_IRQ 17
#define SWITCH5_IRQ_INTERRUPT_CONTROLLER_ID 0
#define SWITCH5_IRQ_TYPE "EDGE"
#define SWITCH5_NAME "/dev/switch5"
#define SWITCH5_RESET_VALUE 0
#define SWITCH5_SPAN 16
#define SWITCH5_TYPE "altera_avalon_pio"


/*
 * switch6 configuration
 *
 */

#define ALT_MODULE_CLASS_switch6 altera_avalon_pio
#define SWITCH6_BASE 0x81040
#define SWITCH6_BIT_CLEARING_EDGE_REGISTER 1
#define SWITCH6_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SWITCH6_CAPTURE 1
#define SWITCH6_DATA_WIDTH 1
#define SWITCH6_DO_TEST_BENCH_WIRING 0
#define SWITCH6_DRIVEN_SIM_VALUE 0
#define SWITCH6_EDGE_TYPE "ANY"
#define SWITCH6_FREQ 160000000
#define SWITCH6_HAS_IN 1
#define SWITCH6_HAS_OUT 0
#define SWITCH6_HAS_TRI 0
#define SWITCH6_IRQ 18
#define SWITCH6_IRQ_INTERRUPT_CONTROLLER_ID 0
#define SWITCH6_IRQ_TYPE "EDGE"
#define SWITCH6_NAME "/dev/switch6"
#define SWITCH6_RESET_VALUE 0
#define SWITCH6_SPAN 16
#define SWITCH6_TYPE "altera_avalon_pio"


/*
 * switch7 configuration
 *
 */

#define ALT_MODULE_CLASS_switch7 altera_avalon_pio
#define SWITCH7_BASE 0x81030
#define SWITCH7_BIT_CLEARING_EDGE_REGISTER 0
#define SWITCH7_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SWITCH7_CAPTURE 1
#define SWITCH7_DATA_WIDTH 1
#define SWITCH7_DO_TEST_BENCH_WIRING 0
#define SWITCH7_DRIVEN_SIM_VALUE 0
#define SWITCH7_EDGE_TYPE "ANY"
#define SWITCH7_FREQ 160000000
#define SWITCH7_HAS_IN 1
#define SWITCH7_HAS_OUT 0
#define SWITCH7_HAS_TRI 0
#define SWITCH7_IRQ 19
#define SWITCH7_IRQ_INTERRUPT_CONTROLLER_ID 0
#define SWITCH7_IRQ_TYPE "EDGE"
#define SWITCH7_NAME "/dev/switch7"
#define SWITCH7_RESET_VALUE 0
#define SWITCH7_SPAN 16
#define SWITCH7_TYPE "altera_avalon_pio"


/*
 * switch8 configuration
 *
 */

#define ALT_MODULE_CLASS_switch8 altera_avalon_pio
#define SWITCH8_BASE 0x81020
#define SWITCH8_BIT_CLEARING_EDGE_REGISTER 0
#define SWITCH8_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SWITCH8_CAPTURE 1
#define SWITCH8_DATA_WIDTH 1
#define SWITCH8_DO_TEST_BENCH_WIRING 0
#define SWITCH8_DRIVEN_SIM_VALUE 0
#define SWITCH8_EDGE_TYPE "ANY"
#define SWITCH8_FREQ 160000000
#define SWITCH8_HAS_IN 1
#define SWITCH8_HAS_OUT 0
#define SWITCH8_HAS_TRI 0
#define SWITCH8_IRQ 20
#define SWITCH8_IRQ_INTERRUPT_CONTROLLER_ID 0
#define SWITCH8_IRQ_TYPE "EDGE"
#define SWITCH8_NAME "/dev/switch8"
#define SWITCH8_RESET_VALUE 0
#define SWITCH8_SPAN 16
#define SWITCH8_TYPE "altera_avalon_pio"


/*
 * sysid_qsys configuration
 *
 */

#define ALT_MODULE_CLASS_sysid_qsys altera_avalon_sysid_qsys
#define SYSID_QSYS_BASE 0x81220
#define SYSID_QSYS_ID 0
#define SYSID_QSYS_IRQ -1
#define SYSID_QSYS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_QSYS_NAME "/dev/sysid_qsys"
#define SYSID_QSYS_SPAN 8
#define SYSID_QSYS_TIMESTAMP 1394063797
#define SYSID_QSYS_TYPE "altera_avalon_sysid_qsys"


/*
 * uart configuration
 *
 */

#define ALT_MODULE_CLASS_uart altera_avalon_uart
#define UART_BASE 0x81000
#define UART_BAUD 115200
#define UART_DATA_BITS 8
#define UART_FIXED_BAUD 1
#define UART_FREQ 160000000
#define UART_IRQ 1
#define UART_IRQ_INTERRUPT_CONTROLLER_ID 0
#define UART_NAME "/dev/uart"
#define UART_PARITY 'N'
#define UART_SIM_CHAR_STREAM ""
#define UART_SIM_TRUE_BAUD 0
#define UART_SPAN 32
#define UART_STOP_BITS 1
#define UART_SYNC_REG_DEPTH 2
#define UART_TYPE "altera_avalon_uart"
#define UART_USE_CTS_RTS 0
#define UART_USE_EOP_REGISTER 0

#endif /* __SYSTEM_H_ */
