/*
 * Ring_Buffer.c
 *
 *  Created on: Jun 11, 2023
 *      Author: oem
 */

#include "Ring_buffer.h"
#include "string.h"
#include "stdlib.h"
//extern BUFFER_SIZE;




/*============= Whrite Byte ==============*/
void Ring_WriteByte(RingBuff_t *buffer, uint8_t sumbol)
{

	uint8_t next = (buffer->head + 1) % BUFFER_SIZE;		//index of next free cell
	if (next != buffer->tail)								//check if the buffer is full
	{
		buffer->data[buffer->head] = sumbol;					//save data
		buffer->head = next;								//update index head
	}

}
/*============= Whrite Byte ==============*/




/*============= Whrite Arrey ==============*/
void Ring_WriteArray(RingBuff_t *buffer, uint8_t *array, uint16_t len)
{
	while (len--)
	{
		Ring_WriteByte(buffer, *(array++));

	}
}
/*============= Whrite Arrey ==============*/



/*============= Read buffer ==============*/
//char* Ring_Read(RingBuff_t *buffer)
//{
//	if (buffer->tail != buffer->head)
//	{
//		int len = strlen(buffer);
//		char *dat = malloc(strlen(buffer)); // выделение памяти для массива данных
////		char *dat = 0;
//		for (int i = 0; i < len; i++)
//		{
//			dat[i] = buffer->data[(buffer->tail)];
//			buffer->tail = (buffer->tail + 1) % BUFFER_SIZE;
//			if (buffer->tail == buffer->head)
//			{
//				break; // если достигнут индекс головы, выходим из цикла
//			}
//		}
//		return dat;
//	}
//	else
//	{
//		return NULL; // буфер пустой, возвращаем NULL
//	}
//}


char* Ring_Read(RingBuff_t *buffer)
{

	if (buffer->tail != buffer->head)	//	перевіряємо, пустий буфєр чи повний
	{
//		uint8_t *data;
		int len = (buffer->head - buffer->tail + BUFFER_SIZE) % BUFFER_SIZE;
		 char* data = (char*) malloc((len + 1) * sizeof(char));
		for (int i = 0; i < len; i++)
		{
			*(data + i) = buffer->data[buffer->tail];	//	якщо буфер не пустий,витягується єлемент, на який указує  buffer->tail
			buffer->tail = (buffer->tail + 1) % BUFFER_SIZE;//	обчислення ногого індексу хвоста
		}
		  data[len-1] = '\0'; // додавання завершального символу рядка
		return data;
	}
	else
	{
		return 0;								//	buffer is empty
	}
}

/*============= Read buffer ==============*/










