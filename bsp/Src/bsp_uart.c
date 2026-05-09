#include "bsp_uart.h"

/**
 * @brief printf重定向到UART串口重定向
 * 
 * 需要注意的是不同编译器的printf重定向实现可能不同
 * 所以还是建议AI去搞一下printf重定向的实现
 * 
 */
#ifdef __cplusplus
extern "C" {
#endif

int fputc(int ch, FILE *f) {
    while(DL_UART_isBusy(Debug_UART_INST) == UART_STAT_BUSY_SET);
    DL_UART_Main_transmitData(Debug_UART_INST, ch);
    return ch;
}

#ifdef __cplusplus
}
#endif


