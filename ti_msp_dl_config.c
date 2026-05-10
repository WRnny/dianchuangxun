/*
 * Copyright (c) 2023, Texas Instruments Incorporated
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
 *  ============ ti_msp_dl_config.c =============
 *  Configured MSPM0 DriverLib module definitions
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */

#include "ti_msp_dl_config.h"

DL_TimerG_backupConfig gMotor_ABackup;
DL_TimerA_backupConfig gMotor_BBackup;
DL_TimerA_backupConfig gDebug_BuzzerBackup;

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform any initialization needed before using any board APIs
 */
SYSCONFIG_WEAK void SYSCFG_DL_init(void)
{
    SYSCFG_DL_initPower();
    SYSCFG_DL_GPIO_init();
    /* Module-Specific Initializations*/
    SYSCFG_DL_SYSCTL_init();
    SYSCFG_DL_Motor_A_init();
    SYSCFG_DL_Motor_B_init();
    SYSCFG_DL_Debug_Buzzer_init();
    SYSCFG_DL_Debug_UART_init();
    SYSCFG_DL_SYSTICK_init();
    /* Ensure backup structures have no valid state */
	gMotor_ABackup.backupRdy 	= false;
	gMotor_BBackup.backupRdy 	= false;
	gDebug_BuzzerBackup.backupRdy 	= false;


}
/*
 * User should take care to save and restore register configuration in application.
 * See Retention Configuration section for more details.
 */
SYSCONFIG_WEAK bool SYSCFG_DL_saveConfiguration(void)
{
    bool retStatus = true;

	retStatus &= DL_TimerG_saveConfiguration(Motor_A_INST, &gMotor_ABackup);
	retStatus &= DL_TimerA_saveConfiguration(Motor_B_INST, &gMotor_BBackup);
	retStatus &= DL_TimerA_saveConfiguration(Debug_Buzzer_INST, &gDebug_BuzzerBackup);

    return retStatus;
}


SYSCONFIG_WEAK bool SYSCFG_DL_restoreConfiguration(void)
{
    bool retStatus = true;

	retStatus &= DL_TimerG_restoreConfiguration(Motor_A_INST, &gMotor_ABackup, false);
	retStatus &= DL_TimerA_restoreConfiguration(Motor_B_INST, &gMotor_BBackup, false);
	retStatus &= DL_TimerA_restoreConfiguration(Debug_Buzzer_INST, &gDebug_BuzzerBackup, false);

    return retStatus;
}

SYSCONFIG_WEAK void SYSCFG_DL_initPower(void)
{
    DL_GPIO_reset(GPIOA);
    DL_GPIO_reset(GPIOB);
    DL_TimerG_reset(Motor_A_INST);
    DL_TimerA_reset(Motor_B_INST);
    DL_TimerA_reset(Debug_Buzzer_INST);
    DL_UART_Main_reset(Debug_UART_INST);


    DL_GPIO_enablePower(GPIOA);
    DL_GPIO_enablePower(GPIOB);
    DL_TimerG_enablePower(Motor_A_INST);
    DL_TimerA_enablePower(Motor_B_INST);
    DL_TimerA_enablePower(Debug_Buzzer_INST);
    DL_UART_Main_enablePower(Debug_UART_INST);

    delay_cycles(POWER_STARTUP_DELAY);
}

SYSCONFIG_WEAK void SYSCFG_DL_GPIO_init(void)
{

    DL_GPIO_initPeripheralAnalogFunction(GPIO_HFXIN_IOMUX);
    DL_GPIO_initPeripheralAnalogFunction(GPIO_HFXOUT_IOMUX);

    DL_GPIO_initPeripheralOutputFunction(GPIO_Motor_A_C1_IOMUX,GPIO_Motor_A_C1_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_Motor_A_C1_PORT, GPIO_Motor_A_C1_PIN);
    DL_GPIO_initPeripheralOutputFunction(GPIO_Motor_B_C1_IOMUX,GPIO_Motor_B_C1_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_Motor_B_C1_PORT, GPIO_Motor_B_C1_PIN);
    DL_GPIO_initPeripheralOutputFunction(GPIO_Debug_Buzzer_C0_IOMUX,GPIO_Debug_Buzzer_C0_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_Debug_Buzzer_C0_PORT, GPIO_Debug_Buzzer_C0_PIN);

    DL_GPIO_initPeripheralOutputFunction(
        GPIO_Debug_UART_IOMUX_TX, GPIO_Debug_UART_IOMUX_TX_FUNC);
    DL_GPIO_initPeripheralInputFunction(
        GPIO_Debug_UART_IOMUX_RX, GPIO_Debug_UART_IOMUX_RX_FUNC);

    DL_GPIO_initDigitalOutputFeatures(Debug_led_Debug_led1_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_DRIVE_STRENGTH_LOW, DL_GPIO_HIZ_DISABLE);

    DL_GPIO_initDigitalInputFeatures(Debug_key_Key_center_IOMUX,
		 DL_GPIO_INVERSION_ENABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(Debug_key_Key_left_IOMUX,
		 DL_GPIO_INVERSION_ENABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(Debug_key_Key_right_IOMUX,
		 DL_GPIO_INVERSION_ENABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(Debug_key_Key_down_IOMUX,
		 DL_GPIO_INVERSION_ENABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(Debug_key_Key_up_IOMUX,
		 DL_GPIO_INVERSION_ENABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalOutput(Motor_DIR_AIN2_IOMUX);

    DL_GPIO_initDigitalOutput(Motor_DIR_AIN1_IOMUX);

    DL_GPIO_initDigitalOutput(Motor_DIR_BIN1_IOMUX);

    DL_GPIO_initDigitalOutput(Motor_DIR_BIN2_IOMUX);

    DL_GPIO_clearPins(GPIOB, Debug_led_Debug_led1_PIN);
    DL_GPIO_setPins(GPIOB, Motor_DIR_AIN2_PIN |
		Motor_DIR_AIN1_PIN |
		Motor_DIR_BIN1_PIN |
		Motor_DIR_BIN2_PIN);
    DL_GPIO_enableOutput(GPIOB, Debug_led_Debug_led1_PIN |
		Motor_DIR_AIN2_PIN |
		Motor_DIR_AIN1_PIN |
		Motor_DIR_BIN1_PIN |
		Motor_DIR_BIN2_PIN);

}


static const DL_SYSCTL_SYSPLLConfig gSYSPLLConfig = {
    .inputFreq              = DL_SYSCTL_SYSPLL_INPUT_FREQ_32_48_MHZ,
	.rDivClk2x              = 1,
	.rDivClk1               = 0,
	.rDivClk0               = 0,
	.enableCLK2x            = DL_SYSCTL_SYSPLL_CLK2X_DISABLE,
	.enableCLK1             = DL_SYSCTL_SYSPLL_CLK1_DISABLE,
	.enableCLK0             = DL_SYSCTL_SYSPLL_CLK0_ENABLE,
	.sysPLLMCLK             = DL_SYSCTL_SYSPLL_MCLK_CLK0,
	.sysPLLRef              = DL_SYSCTL_SYSPLL_REF_HFCLK,
	.qDiv                   = 3,
	.pDiv                   = DL_SYSCTL_SYSPLL_PDIV_1
};
SYSCONFIG_WEAK void SYSCFG_DL_SYSCTL_init(void)
{

	//Low Power Mode is configured to be SLEEP0
    DL_SYSCTL_setBORThreshold(DL_SYSCTL_BOR_THRESHOLD_LEVEL_0);
    DL_SYSCTL_setFlashWaitState(DL_SYSCTL_FLASH_WAIT_STATE_2);

    
	DL_SYSCTL_setSYSOSCFreq(DL_SYSCTL_SYSOSC_FREQ_BASE);
	/* Set default configuration */
	DL_SYSCTL_disableHFXT();
	DL_SYSCTL_disableSYSPLL();
    DL_SYSCTL_setHFCLKSourceHFXTParams(DL_SYSCTL_HFXT_RANGE_32_48_MHZ,10, true);
    DL_SYSCTL_configSYSPLL((DL_SYSCTL_SYSPLLConfig *) &gSYSPLLConfig);
    DL_SYSCTL_setULPCLKDivider(DL_SYSCTL_ULPCLK_DIV_2);
    DL_SYSCTL_setMCLKSource(SYSOSC, HSCLK, DL_SYSCTL_HSCLK_SOURCE_SYSPLL);

}


/*
 * Timer clock configuration to be sourced by  / 1 (80000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   80000000 Hz = 80000000 Hz / (1 * (0 + 1))
 */
static const DL_TimerG_ClockConfig gMotor_AClockConfig = {
    .clockSel = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_1,
    .prescale = 0U
};

static const DL_TimerG_PWMConfig gMotor_AConfig = {
    .pwmMode = DL_TIMER_PWM_MODE_EDGE_ALIGN,
    .period = 10001,
    .isTimerWithFourCC = false,
    .startTimer = DL_TIMER_START,
};

SYSCONFIG_WEAK void SYSCFG_DL_Motor_A_init(void) {

    DL_TimerG_setClockConfig(
        Motor_A_INST, (DL_TimerG_ClockConfig *) &gMotor_AClockConfig);

    DL_TimerG_initPWMMode(
        Motor_A_INST, (DL_TimerG_PWMConfig *) &gMotor_AConfig);

    // Set Counter control to the smallest CC index being used
    DL_TimerG_setCounterControl(Motor_A_INST,DL_TIMER_CZC_CCCTL1_ZCOND,DL_TIMER_CAC_CCCTL1_ACOND,DL_TIMER_CLC_CCCTL1_LCOND);

    DL_TimerG_setCaptureCompareOutCtl(Motor_A_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_ENABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERG_CAPTURE_COMPARE_1_INDEX);

    DL_TimerG_setCaptCompUpdateMethod(Motor_A_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERG_CAPTURE_COMPARE_1_INDEX);
    DL_TimerG_setCaptureCompareValue(Motor_A_INST, 10001, DL_TIMER_CC_1_INDEX);

    DL_TimerG_enableClock(Motor_A_INST);


    
    DL_TimerG_setCCPDirection(Motor_A_INST , DL_TIMER_CC1_OUTPUT );


}
/*
 * Timer clock configuration to be sourced by  / 1 (80000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   80000000 Hz = 80000000 Hz / (1 * (0 + 1))
 */
static const DL_TimerA_ClockConfig gMotor_BClockConfig = {
    .clockSel = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_1,
    .prescale = 0U
};

static const DL_TimerA_PWMConfig gMotor_BConfig = {
    .pwmMode = DL_TIMER_PWM_MODE_EDGE_ALIGN,
    .period = 10001,
    .isTimerWithFourCC = false,
    .startTimer = DL_TIMER_START,
};

SYSCONFIG_WEAK void SYSCFG_DL_Motor_B_init(void) {

    DL_TimerA_setClockConfig(
        Motor_B_INST, (DL_TimerA_ClockConfig *) &gMotor_BClockConfig);

    DL_TimerA_initPWMMode(
        Motor_B_INST, (DL_TimerA_PWMConfig *) &gMotor_BConfig);

    // Set Counter control to the smallest CC index being used
    DL_TimerA_setCounterControl(Motor_B_INST,DL_TIMER_CZC_CCCTL1_ZCOND,DL_TIMER_CAC_CCCTL1_ACOND,DL_TIMER_CLC_CCCTL1_LCOND);

    DL_TimerA_setCaptureCompareOutCtl(Motor_B_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_ENABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERA_CAPTURE_COMPARE_1_INDEX);

    DL_TimerA_setCaptCompUpdateMethod(Motor_B_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERA_CAPTURE_COMPARE_1_INDEX);
    DL_TimerA_setCaptureCompareValue(Motor_B_INST, 10001, DL_TIMER_CC_1_INDEX);

    DL_TimerA_enableClock(Motor_B_INST);


    
    DL_TimerA_setCCPDirection(Motor_B_INST , DL_TIMER_CC1_OUTPUT );


}
/*
 * Timer clock configuration to be sourced by  / 1 (80000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   80000000 Hz = 80000000 Hz / (1 * (0 + 1))
 */
static const DL_TimerA_ClockConfig gDebug_BuzzerClockConfig = {
    .clockSel = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_1,
    .prescale = 0U
};

static const DL_TimerA_PWMConfig gDebug_BuzzerConfig = {
    .pwmMode = DL_TIMER_PWM_MODE_EDGE_ALIGN,
    .period = 65535,
    .isTimerWithFourCC = true,
    .startTimer = DL_TIMER_START,
};

SYSCONFIG_WEAK void SYSCFG_DL_Debug_Buzzer_init(void) {

    DL_TimerA_setClockConfig(
        Debug_Buzzer_INST, (DL_TimerA_ClockConfig *) &gDebug_BuzzerClockConfig);

    DL_TimerA_initPWMMode(
        Debug_Buzzer_INST, (DL_TimerA_PWMConfig *) &gDebug_BuzzerConfig);

    // Set Counter control to the smallest CC index being used
    DL_TimerA_setCounterControl(Debug_Buzzer_INST,DL_TIMER_CZC_CCCTL0_ZCOND,DL_TIMER_CAC_CCCTL0_ACOND,DL_TIMER_CLC_CCCTL0_LCOND);

    DL_TimerA_setCaptureCompareOutCtl(Debug_Buzzer_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_ENABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERA_CAPTURE_COMPARE_0_INDEX);

    DL_TimerA_setCaptCompUpdateMethod(Debug_Buzzer_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERA_CAPTURE_COMPARE_0_INDEX);
    DL_TimerA_setCaptureCompareValue(Debug_Buzzer_INST, 65535, DL_TIMER_CC_0_INDEX);

    DL_TimerA_enableClock(Debug_Buzzer_INST);


    
    DL_TimerA_setCCPDirection(Debug_Buzzer_INST , DL_TIMER_CC0_OUTPUT );


}



static const DL_UART_Main_ClockConfig gDebug_UARTClockConfig = {
    .clockSel    = DL_UART_MAIN_CLOCK_BUSCLK,
    .divideRatio = DL_UART_MAIN_CLOCK_DIVIDE_RATIO_1
};

static const DL_UART_Main_Config gDebug_UARTConfig = {
    .mode        = DL_UART_MAIN_MODE_NORMAL,
    .direction   = DL_UART_MAIN_DIRECTION_TX_RX,
    .flowControl = DL_UART_MAIN_FLOW_CONTROL_NONE,
    .parity      = DL_UART_MAIN_PARITY_NONE,
    .wordLength  = DL_UART_MAIN_WORD_LENGTH_8_BITS,
    .stopBits    = DL_UART_MAIN_STOP_BITS_ONE
};

SYSCONFIG_WEAK void SYSCFG_DL_Debug_UART_init(void)
{
    DL_UART_Main_setClockConfig(Debug_UART_INST, (DL_UART_Main_ClockConfig *) &gDebug_UARTClockConfig);

    DL_UART_Main_init(Debug_UART_INST, (DL_UART_Main_Config *) &gDebug_UARTConfig);
    /*
     * Configure baud rate by setting oversampling and baud rate divisors.
     *  Target baud rate: 9600
     *  Actual baud rate: 9599.81
     */
    DL_UART_Main_setOversampling(Debug_UART_INST, DL_UART_OVERSAMPLING_RATE_16X);
    DL_UART_Main_setBaudRateDivisor(Debug_UART_INST, Debug_UART_IBRD_40_MHZ_9600_BAUD, Debug_UART_FBRD_40_MHZ_9600_BAUD);


    /* Configure Interrupts */
    DL_UART_Main_enableInterrupt(Debug_UART_INST,
                                 DL_UART_MAIN_INTERRUPT_RX);


    DL_UART_Main_enable(Debug_UART_INST);
}

SYSCONFIG_WEAK void SYSCFG_DL_SYSTICK_init(void)
{
    /*
     * Initializes the SysTick period to 1.00 ms,
     * enables the interrupt, and starts the SysTick Timer
     */
    DL_SYSTICK_config(80000);
}

