/*
 * Ring_buffer.h
 *
 *  Created on: Jun 11, 2023
 *      Author: oem
 */
#include <main.h>

#ifndef RING_BUFFER_H_
#define RING_BUFFER_H_

#define BUFFER_SIZE 128

typedef struct
{
	uint8_t data[BUFFER_SIZE];
	uint8_t head;
	uint8_t tail;

}RingBuff_t;

void Ring_WriteByte(RingBuff_t *buffer, uint8_t sumbol);
void Ring_WriteArray(RingBuff_t *buffer, uint8_t *array, uint16_t len);
char* Ring_Read(RingBuff_t *buffer);




#endif /* RING_BUFFER_H_ */
