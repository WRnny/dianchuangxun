#ifndef __BSP_UART_H__
#define __BSP_UART_H__

#include "ti_msp_dl_config.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

 #define UART_RX_BUF_SIZE 32

extern uint8_t rx_data;

extern float Yaw_received; // Yaw轴接收数据

/**
 * @brief 串口初始化
 * 
 */
void BspUART_Init(void);

/**
 * @brief 串口发送VOFA数据
 * 
 * @param data 发送的数据
 * @param count 发送多少数据
 */
void VOFA_SendData(float* data, int count);

#endif /* __BSP_UART_H__ */
