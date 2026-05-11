/*
 * Copyright (c) 2021, Texas Instruments Incorporated
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

#include "ti_msp_dl_config.h"
#include "my_Ticks.h"

#include "bsp_key.h"
#include "bsp_uart.h"
#include "bsp_track.h"
#include "bsp_motor.h"
#include "bsp_buzzer.h"
#include "bsp_encoder.h"

#include "pid.h"

float vofa_arry[20];

void LED_Test(void)
{
    DL_GPIO_togglePins(Debug_led_PORT, Debug_led_Debug_led1_PIN);
}

void NULL_Test(void)
{
    WR_TASK_PERIODIC(NULL_test_task, 10);
}

int main(void)
{
    SYSCFG_DL_init();
    BspKey_Init();
    BspUART_Init();    
    BspEncoder_Init();
    BspMotor_Init();
    // BspTarck_Init();
    SpeedLop_Init();

    while (1) 
    {

        Track_Task();
        // BspMotor_SetSpeed(BSP_MOTOR_A, 10000); // 右轮
        // BspMotor_SetSpeed(BSP_MOTOR_B, 10000); // 左轮 
        // SpeedLoop_set(BSP_MOTOR_A, 40);
        // SpeedLoop_set(BSP_MOTOR_B, 40);
        // 长按中间按键开启循迹调试模式
        WR_KeyControlTask(TrackLop_Init, &bsp_key_param[Key_center].key_longpressflag);



        WR_KeyControlTask(LED_Test, &bsp_key_param[Key_right].key_releaseflag);
        WR_KeyControlTask(LED_Test, &bsp_key_param[Key_left].key_pressflag);
        WR_KeyControlTask(LED_Test, &bsp_key_param[Key_up].key_longpressflag);
        WR_KeyControlTask(LED_Test, &bsp_key_param[Key_down].key_releaseflag);


        // 不清楚VOFA什么问题部分位的值一直是0
        // vofa_arry[0] = bsp_encoder_param[E1].speed;
        // vofa_arry[1] = bsp_encoder_param[E2].speed;

        vofa_arry[0] = Yaw_received;
        // vofa_arry[0] = coord;
        // vofa_arry[1] = last_coord;
        // vofa_arry[2] = qty;

        // vofa_arry[0] = coord;
        // vofa_arry[1] = last_coord;

        VOFA_SendData(vofa_arry, 1);
    }
}



