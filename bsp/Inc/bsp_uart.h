#ifndef __BSP_UART_H__
#define __BSP_UART_H__

#include "ti_msp_dl_config.h"
#include "stdio.h"

typedef struct{
    unsigned char       *buffer;    // 环形缓冲区在RAM中的起始地址
    size_t              length;     // 环形缓冲区的长度
    size_t              count;      // 
    size_t              head;
    size_t              tail;
    size_t              maxCount;
}RingBuf_Object, *RingBuf_Handle;

void BspUART_Init(void);
void BspDMA_Init(void);

#endif /* __BSP_UART_H__ */
