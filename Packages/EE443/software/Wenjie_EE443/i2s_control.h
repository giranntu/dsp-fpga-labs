/*
 * I2S_control.h
 *
 *  Created on: Jan 23, 2014
 *      Author: zhwj814
 */

int I2S_collect_left();
int I2S_collect_right();
void I2S_send_left(int leftdata);
void I2S_send_right(int rightdata);
void I2S_send_lr(int left, int right);
