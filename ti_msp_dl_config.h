/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X
#define CONFIG_MSPM0G3507

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)


#define GPIO_HFXT_PORT                                                     GPIOA
#define GPIO_HFXIN_PIN                                             DL_GPIO_PIN_5
#define GPIO_HFXIN_IOMUX                                         (IOMUX_PINCM10)
#define GPIO_HFXOUT_PIN                                            DL_GPIO_PIN_6
#define GPIO_HFXOUT_IOMUX                                        (IOMUX_PINCM11)
#define CPUCLK_FREQ                                                     80000000



/* Defines for Motor_A */
#define Motor_A_INST                                                       TIMG7
#define Motor_A_INST_IRQHandler                                 TIMG7_IRQHandler
#define Motor_A_INST_INT_IRQN                                   (TIMG7_INT_IRQn)
#define Motor_A_INST_CLK_FREQ                                           80000000
/* GPIO defines for channel 1 */
#define GPIO_Motor_A_C1_PORT                                               GPIOA
#define GPIO_Motor_A_C1_PIN                                        DL_GPIO_PIN_2
#define GPIO_Motor_A_C1_IOMUX                                     (IOMUX_PINCM7)
#define GPIO_Motor_A_C1_IOMUX_FUNC                    IOMUX_PINCM7_PF_TIMG7_CCP1
#define GPIO_Motor_A_C1_IDX                                  DL_TIMER_CC_1_INDEX

/* Defines for Motor_B */
#define Motor_B_INST                                                       TIMA1
#define Motor_B_INST_IRQHandler                                 TIMA1_IRQHandler
#define Motor_B_INST_INT_IRQN                                   (TIMA1_INT_IRQn)
#define Motor_B_INST_CLK_FREQ                                           80000000
/* GPIO defines for channel 1 */
#define GPIO_Motor_B_C1_PORT                                               GPIOA
#define GPIO_Motor_B_C1_PIN                                       DL_GPIO_PIN_16
#define GPIO_Motor_B_C1_IOMUX                                    (IOMUX_PINCM38)
#define GPIO_Motor_B_C1_IOMUX_FUNC                   IOMUX_PINCM38_PF_TIMA1_CCP1
#define GPIO_Motor_B_C1_IDX                                  DL_TIMER_CC_1_INDEX

/* Defines for Debug_Buzzer */
#define Debug_Buzzer_INST                                                  TIMA0
#define Debug_Buzzer_INST_IRQHandler                            TIMA0_IRQHandler
#define Debug_Buzzer_INST_INT_IRQN                              (TIMA0_INT_IRQn)
#define Debug_Buzzer_INST_CLK_FREQ                                      80000000
/* GPIO defines for channel 0 */
#define GPIO_Debug_Buzzer_C0_PORT                                          GPIOA
#define GPIO_Debug_Buzzer_C0_PIN                                  DL_GPIO_PIN_21
#define GPIO_Debug_Buzzer_C0_IOMUX                               (IOMUX_PINCM46)
#define GPIO_Debug_Buzzer_C0_IOMUX_FUNC              IOMUX_PINCM46_PF_TIMA0_CCP0
#define GPIO_Debug_Buzzer_C0_IDX                             DL_TIMER_CC_0_INDEX



/* Defines for WR_TASK_PERIODIC_TICK */
#define WR_TASK_PERIODIC_TICK_INST                                      (TIMG12)
#define WR_TASK_PERIODIC_TICK_INST_IRQHandler                       TIMG12_IRQHandler
#define WR_TASK_PERIODIC_TICK_INST_INT_IRQN                       (TIMG12_INT_IRQn)
#define WR_TASK_PERIODIC_TICK_INST_LOAD_VALUE                                (79999U)



/* Defines for Debug_UART */
#define Debug_UART_INST                                                    UART0
#define Debug_UART_INST_FREQUENCY                                       40000000
#define Debug_UART_INST_IRQHandler                              UART0_IRQHandler
#define Debug_UART_INST_INT_IRQN                                  UART0_INT_IRQn
#define GPIO_Debug_UART_RX_PORT                                            GPIOA
#define GPIO_Debug_UART_TX_PORT                                            GPIOA
#define GPIO_Debug_UART_RX_PIN                                    DL_GPIO_PIN_11
#define GPIO_Debug_UART_TX_PIN                                    DL_GPIO_PIN_10
#define GPIO_Debug_UART_IOMUX_RX                                 (IOMUX_PINCM22)
#define GPIO_Debug_UART_IOMUX_TX                                 (IOMUX_PINCM21)
#define GPIO_Debug_UART_IOMUX_RX_FUNC                  IOMUX_PINCM22_PF_UART0_RX
#define GPIO_Debug_UART_IOMUX_TX_FUNC                  IOMUX_PINCM21_PF_UART0_TX
#define Debug_UART_BAUD_RATE                                              (9600)
#define Debug_UART_IBRD_40_MHZ_9600_BAUD                                   (260)
#define Debug_UART_FBRD_40_MHZ_9600_BAUD                                    (27)
/* Defines for Rx_yaw */
#define Rx_yaw_INST                                                        UART1
#define Rx_yaw_INST_FREQUENCY                                           40000000
#define Rx_yaw_INST_IRQHandler                                  UART1_IRQHandler
#define Rx_yaw_INST_INT_IRQN                                      UART1_INT_IRQn
#define GPIO_Rx_yaw_RX_PORT                                                GPIOA
#define GPIO_Rx_yaw_RX_PIN                                         DL_GPIO_PIN_9
#define GPIO_Rx_yaw_IOMUX_RX                                     (IOMUX_PINCM20)
#define GPIO_Rx_yaw_IOMUX_RX_FUNC                      IOMUX_PINCM20_PF_UART1_RX
#define Rx_yaw_BAUD_RATE                                                (115200)
#define Rx_yaw_IBRD_40_MHZ_115200_BAUD                                      (21)
#define Rx_yaw_FBRD_40_MHZ_115200_BAUD                                      (45)





/* Port definition for Pin Group Debug_led */
#define Debug_led_PORT                                                   (GPIOB)

/* Defines for Debug_led1: GPIOB.22 with pinCMx 50 on package pin 21 */
#define Debug_led_Debug_led1_PIN                                (DL_GPIO_PIN_22)
#define Debug_led_Debug_led1_IOMUX                               (IOMUX_PINCM50)
/* Defines for Key_center: GPIOB.25 with pinCMx 56 on package pin 27 */
#define Debug_key_Key_center_PORT                                        (GPIOB)
#define Debug_key_Key_center_PIN                                (DL_GPIO_PIN_25)
#define Debug_key_Key_center_IOMUX                               (IOMUX_PINCM56)
/* Defines for Key_left: GPIOA.14 with pinCMx 36 on package pin 7 */
#define Debug_key_Key_left_PORT                                          (GPIOA)
#define Debug_key_Key_left_PIN                                  (DL_GPIO_PIN_14)
#define Debug_key_Key_left_IOMUX                                 (IOMUX_PINCM36)
/* Defines for Key_right: GPIOA.15 with pinCMx 37 on package pin 8 */
#define Debug_key_Key_right_PORT                                         (GPIOA)
#define Debug_key_Key_right_PIN                                 (DL_GPIO_PIN_15)
#define Debug_key_Key_right_IOMUX                                (IOMUX_PINCM37)
/* Defines for Key_down: GPIOA.17 with pinCMx 39 on package pin 10 */
#define Debug_key_Key_down_PORT                                          (GPIOA)
#define Debug_key_Key_down_PIN                                  (DL_GPIO_PIN_17)
#define Debug_key_Key_down_IOMUX                                 (IOMUX_PINCM39)
/* Defines for Key_up: GPIOB.24 with pinCMx 52 on package pin 23 */
#define Debug_key_Key_up_PORT                                            (GPIOB)
#define Debug_key_Key_up_PIN                                    (DL_GPIO_PIN_24)
#define Debug_key_Key_up_IOMUX                                   (IOMUX_PINCM52)
/* Port definition for Pin Group Motor_DIR */
#define Motor_DIR_PORT                                                   (GPIOB)

/* Defines for AIN2: GPIOB.15 with pinCMx 32 on package pin 3 */
#define Motor_DIR_AIN2_PIN                                      (DL_GPIO_PIN_15)
#define Motor_DIR_AIN2_IOMUX                                     (IOMUX_PINCM32)
/* Defines for AIN1: GPIOB.16 with pinCMx 33 on package pin 4 */
#define Motor_DIR_AIN1_PIN                                      (DL_GPIO_PIN_16)
#define Motor_DIR_AIN1_IOMUX                                     (IOMUX_PINCM33)
/* Defines for BIN1: GPIOB.2 with pinCMx 15 on package pin 50 */
#define Motor_DIR_BIN1_PIN                                       (DL_GPIO_PIN_2)
#define Motor_DIR_BIN1_IOMUX                                     (IOMUX_PINCM15)
/* Defines for BIN2: GPIOB.3 with pinCMx 16 on package pin 51 */
#define Motor_DIR_BIN2_PIN                                       (DL_GPIO_PIN_3)
#define Motor_DIR_BIN2_IOMUX                                     (IOMUX_PINCM16)
/* Defines for E1_B: GPIOB.23 with pinCMx 51 on package pin 22 */
#define Encoder_E1_B_PORT                                                (GPIOB)
// pins affected by this interrupt request:["E1_B","E1_A","E2_B"]
#define Encoder_GPIOB_INT_IRQN                                  (GPIOB_INT_IRQn)
#define Encoder_GPIOB_INT_IIDX                  (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define Encoder_E1_B_IIDX                                   (DL_GPIO_IIDX_DIO23)
#define Encoder_E1_B_PIN                                        (DL_GPIO_PIN_23)
#define Encoder_E1_B_IOMUX                                       (IOMUX_PINCM51)
/* Defines for E1_A: GPIOB.27 with pinCMx 58 on package pin 29 */
#define Encoder_E1_A_PORT                                                (GPIOB)
#define Encoder_E1_A_IIDX                                   (DL_GPIO_IIDX_DIO27)
#define Encoder_E1_A_PIN                                        (DL_GPIO_PIN_27)
#define Encoder_E1_A_IOMUX                                       (IOMUX_PINCM58)
/* Defines for E2_A: GPIOA.12 with pinCMx 34 on package pin 5 */
#define Encoder_E2_A_PORT                                                (GPIOA)
// pins affected by this interrupt request:["E2_A"]
#define Encoder_GPIOA_INT_IRQN                                  (GPIOA_INT_IRQn)
#define Encoder_GPIOA_INT_IIDX                  (DL_INTERRUPT_GROUP1_IIDX_GPIOA)
#define Encoder_E2_A_IIDX                                   (DL_GPIO_IIDX_DIO12)
#define Encoder_E2_A_PIN                                        (DL_GPIO_PIN_12)
#define Encoder_E2_A_IOMUX                                       (IOMUX_PINCM34)
/* Defines for E2_B: GPIOB.6 with pinCMx 23 on package pin 58 */
#define Encoder_E2_B_PORT                                                (GPIOB)
#define Encoder_E2_B_IIDX                                    (DL_GPIO_IIDX_DIO6)
#define Encoder_E2_B_PIN                                         (DL_GPIO_PIN_6)
#define Encoder_E2_B_IOMUX                                       (IOMUX_PINCM23)
/* Port definition for Pin Group Track */
#define Track_PORT                                                       (GPIOB)

/* Defines for Track_1: GPIOB.4 with pinCMx 17 on package pin 52 */
#define Track_Track_1_PIN                                        (DL_GPIO_PIN_4)
#define Track_Track_1_IOMUX                                      (IOMUX_PINCM17)
/* Defines for Track_2: GPIOB.12 with pinCMx 29 on package pin 64 */
#define Track_Track_2_PIN                                       (DL_GPIO_PIN_12)
#define Track_Track_2_IOMUX                                      (IOMUX_PINCM29)
/* Defines for Track_3: GPIOB.17 with pinCMx 43 on package pin 14 */
#define Track_Track_3_PIN                                       (DL_GPIO_PIN_17)
#define Track_Track_3_IOMUX                                      (IOMUX_PINCM43)
/* Defines for Track_4: GPIOB.5 with pinCMx 18 on package pin 53 */
#define Track_Track_4_PIN                                        (DL_GPIO_PIN_5)
#define Track_Track_4_IOMUX                                      (IOMUX_PINCM18)
/* Defines for Track_5: GPIOB.13 with pinCMx 30 on package pin 1 */
#define Track_Track_5_PIN                                       (DL_GPIO_PIN_13)
#define Track_Track_5_IOMUX                                      (IOMUX_PINCM30)
/* Defines for Track_6: GPIOB.19 with pinCMx 45 on package pin 16 */
#define Track_Track_6_PIN                                       (DL_GPIO_PIN_19)
#define Track_Track_6_IOMUX                                      (IOMUX_PINCM45)
/* Defines for Track_7: GPIOB.21 with pinCMx 49 on package pin 20 */
#define Track_Track_7_PIN                                       (DL_GPIO_PIN_21)
#define Track_Track_7_IOMUX                                      (IOMUX_PINCM49)



/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_Motor_A_init(void);
void SYSCFG_DL_Motor_B_init(void);
void SYSCFG_DL_Debug_Buzzer_init(void);
void SYSCFG_DL_WR_TASK_PERIODIC_TICK_init(void);
void SYSCFG_DL_Debug_UART_init(void);
void SYSCFG_DL_Rx_yaw_init(void);

void SYSCFG_DL_SYSTICK_init(void);

bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
