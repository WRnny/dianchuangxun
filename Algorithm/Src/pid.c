#include "pid.h"

/**
 * @brief 开始速度环
 * 
 */
void SpeedLop_Init(void)
{
    // 清除速度环定时器中断标志位
    NVIC_ClearPendingIRQ(PidSpeed_Task_INST_INT_IRQN);

    // 使能速度环定时器中断
    NVIC_EnableIRQ(PidSpeed_Task_INST_INT_IRQN);
}

/**
 * @brief 开启循迹环
 * 
 */
void TrackLop_Init(void)
{
    // 清除循迹环定时器中断标志位
    NVIC_ClearPendingIRQ(PidTrack_Task_INST_INT_IRQN);

    // 使能循迹环定时器中断
    NVIC_EnableIRQ(PidTrack_Task_INST_INT_IRQN);
}

/**
 * @brief PID计算逻辑
 *
 * @param pid_param     PID基本成员Ki,Kp,Kd,target
 * @param pid_item      PID计算的一些基本变量，和一些优化处理变量
 * @param measure       实际测量值
 * @param dt            计算时间间隔
 * @return float        返回PID的调节值
 */
float Pid_Calculate(PID_Param* pid_param, PID_Item* pid_item, float measure, float dt)
{
    if(dt <= 0.0f)
    {
        return 0.0f;
    }

    pid_item->error = pid_param->target - measure;

    if(pid_item->ZERO > 0)
    {
        if(fabs(pid_item->error) < pid_item->ZERO)
        {
            pid_item->error = 0;
        }
    }

    pid_item->integral += pid_item->error;

    // 如果设置了积分限幅在开启积分限幅
    if(pid_item->integral_max > 0.0f)
    {
        pid_item->integral = fmaxf( -pid_item->integral_max, fminf(pid_item->integral_max, pid_item->integral) );
    }

    // 加个低阶滤波系数抗干扰
    float raw_derivative = (pid_item->error - pid_item->last_error) / dt; 
    pid_item->derivative = D_TERM_FILTER * pid_item->derivative + (1.0f - D_TERM_FILTER) * raw_derivative;

    float output = pid_param->Kp * pid_item->error + pid_param->Ki * pid_item->integral + pid_param->Kd * pid_item->derivative; 

    // 如果设置了输出限幅在开启这输出限幅
    if(pid_item->output_max > 0.0f)
    {
        float raw_output = output;
        if(pid_param->target > 0.0f && pid_item->output_min > 0.0f)
        {
            output = fmaxf(pid_item->output_min, fminf(pid_item->output_max, output));
        }
        else if(pid_param->target < 0.0f && pid_item->output_min > 0.0f)
        {
            output = fminf(-pid_item->output_min, fmaxf(-pid_item->output_max, output));
        }
        else
        {
            output = fmaxf(-pid_item->output_max, fminf(pid_item->output_max, output));
        }
        if(fabs(output - raw_output) > 1e-5f && pid_param->Ki > 1e-6f)
        {
            pid_item->integral -= (raw_output - output) * dt / pid_param->Ki;
        }
    }

    pid_item->last_error = pid_item->error;

    return output;
}

PID_Param SpeedloopL_PIDParam = {
    .Kp = 222.0f,
    .Ki = 6.66f,
    .Kd = 0.0f,
    .target = 0.0f // 0 ~ 90 (cm / s)
};

PID_Item SpeedloopL_PIDItem = {
    .integral_max = 0.0f,
    .output_max = 0.0f,
    .output_min = 0.0f,

    .ZERO = 0.0f
};

PID_Param SpeedloopR_PIDParam = {
    .Kp = 333.5f,
    .Ki = 6.66f,
    .Kd = 0.0f,
    .target = 0.0f
};

PID_Item SpeedloopR_PIDItem = {
    .integral_max = 0.0f,
    .output_max = 0.0f,
    .output_min = 0.0f,

    .ZERO = 0.0f
};

volatile float speedloopoutput_L = 0.0f;
volatile float speedloopoutput_R = 0.0f;
/**
 * @brief 电机速度环定时器中断20ms
 * 
 */
void PidSpeed_Task_INST_IRQHandler(void)
{
    switch (DL_Timer_getPendingInterrupt(PidSpeed_Task_INST))
    {
    case DL_TIMER_IIDX_ZERO:
        Claculate_MotorSpeed();

        speedloopoutput_R = Pid_Calculate(&SpeedloopR_PIDParam, &SpeedloopR_PIDItem, bsp_encoder_param[E1].speed, 0.02);
        speedloopoutput_L = Pid_Calculate(&SpeedloopL_PIDParam, &SpeedloopL_PIDItem, bsp_encoder_param[E2].speed, 0.02);

        BspMotor_SetSpeed(BSP_MOTOR_A, speedloopoutput_R);
        BspMotor_SetSpeed(BSP_MOTOR_B, speedloopoutput_L); // 左轮 

        break;
    
    default:
        break;
    }
}

PID_Param Trackloop_PIDParam = {
    .Kp = 7.8f,
    .Ki = 0.0f,
    .Kd = 0.0f,
    .target = 4.0f 
};

PID_Item Trackloop_PIDItem = {
    .integral_max = 0.0f,
    .output_max = 0.0f,
    .output_min = 0.0f,

    .ZERO = 0.0f
};

int base_trackspeed = 27;
volatile float trackloop_output = 0.0f;

/**
 * @brief 循迹位置环
 * 
 */
void PidTrack_Task_INST_IRQHandler(void)
{
    switch (DL_Timer_getPendingInterrupt(PidTrack_Task_INST))
    {
        case DL_TIMER_IIDX_ZERO:

            trackloop_output = Pid_Calculate(&Trackloop_PIDParam, &Trackloop_PIDItem, coord, 0.05);

            SpeedLoop_set(BSP_MOTOR_A, base_trackspeed + trackloop_output); // 右轮
            SpeedLoop_set(BSP_MOTOR_B, base_trackspeed - trackloop_output); // 左轮

            break;

        default:
            break;
    }
}

/**
 * @brief 角度环
 * 
 */
void PidAngle_Task_INST_IRQHandler(void)
{
    switch (DL_Timer_getPendingInterrupt(PidAngle_Task_INST))
    {
        case DL_TIMER_IIDX_ZERO:

        
    }
}
