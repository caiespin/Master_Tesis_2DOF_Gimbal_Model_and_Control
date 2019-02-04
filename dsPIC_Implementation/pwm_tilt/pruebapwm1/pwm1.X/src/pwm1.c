/*--------------------------------------------------------------
 *   MPLAB Blockset v3.35 for Microchip dsPIC chip family.     *
 *   Generate .c and .h files from Simulink model              *
 *   and compile to .elf, .hex and .cof file that can be       *
 *   flashed into the microcontroller                          *
 *                                                             *
 *      The Microchip name PIC, dsPIC, and MPLAB are           *
 *      registered trademarks of Microchip Technology Inc.     *
 *      MATLAB, Simulink, and Real-Time Workshop are           *
 *      registered trademarks of The MathWorks, Inc.           *
 *                                                             *
 *  Blockset authors: L.Kerhuel, U.Kumar                       *
 *  Product Page:  http://www.microchip.com/SimulinkBlocks     *
 *          Forum: http://www.microchip.com/forums/f192.aspx   *
 *          Wiki:  http://microchip.wikidot.com/simulink:start *
 *--------------------------------------------------------------
 *
 * File: pwm1.c
 *
 * Real-Time Workshop code generated for Simulink model pwm1.
 *
 * Model version                        : 1.20
 * Real-Time Workshop file version      : 8.5 (R2013b) 08-Aug-2013
 * Real-Time Workshop file generated on : Thu Apr 09 11:26:11 2015
 * TLC version                          : 8.5 (Aug  6 2013)
 * C source code generated on           : Thu Apr 09 11:26:11 2015
 */

#include "pwm1.h"
#include "pwm1_private.h"

/* Block signals (auto storage) */
B_pwm1_T pwm1_B;

/* Block states (auto storage) */
DW_pwm1_T pwm1_DW;

/* Real-time model */
RT_MODEL_pwm1_T pwm1_M_;
RT_MODEL_pwm1_T *const pwm1_M = &pwm1_M_;

/* Model step function for TID0 */
void pwm1_step0(void)                  /* Sample time: [0.001s, 0.0s] */
{
  /* local block i/o variables */
  boolean_T rtb_Limitsw;
  boolean_T rtb_Switch;
  boolean_T rtb_Toggle;

  /* S-Function (MCHP_Digital_Input): '<Root>/Limitsw' */

  /* MCHP_Digital_Input Block: <Root>/Limitsw/Output */
  rtb_Limitsw = PORTBbits.RB8;         /* Read pin B8 */

  /* Logic: '<S1>/Logical Operator1' incorporates:
   *  Delay: '<S1>/Integer Delay3'
   *  RelationalOperator: '<S2>/FixPt Relational Operator'
   *  UnitDelay: '<S2>/Delay Input1'
   */
  rtb_Toggle = ((int16_T)rtb_Limitsw < (int16_T)pwm1_DW.DelayInput1_DSTATE) ^
    pwm1_DW.IntegerDelay3_DSTATE;

  /* Switch: '<S1>/Switch' */
  rtb_Switch = rtb_Toggle;

  /* S-Function (MCHP_Digital_Output_Write): '<S4>/Digital Output Write' */
  LATBbits.LATB11 = rtb_Switch;

  /* Update for Delay: '<S1>/Integer Delay3' */
  pwm1_DW.IntegerDelay3_DSTATE = rtb_Toggle;

  /* Update for UnitDelay: '<S2>/Delay Input1' */
  pwm1_DW.DelayInput1_DSTATE = rtb_Limitsw;
}

/* Model step function for TID1 */
void pwm1_step1(void)                  /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (MCHP_PWM): '<S1>/ENABLE' */
  /* PWM Output Function !! */

  /* Update for S-Function (MCHP_PWM): '<S1>/ENABLE' */
  P1DC2 = 1200U;                       /* Period for Channel 2 */
}

/* Model step function for TID2 */
void pwm1_step2(void)                  /* Sample time: [0.1s, 0.0s] */
{
  /* MCHP_UART_Rx Block for UARTRef 2: <Root>/UART Rx/Outputs */
  {
    static uint8_T U2LastValue ;
    if (MCHP_UART2_Rx.tail != MCHP_UART2_Rx.head) {
      pwm1_B.U2Rx = (uint8_T) MCHP_UART2_Rx.buffer[MCHP_UART2_Rx.head];/* Use only the 8 low bytes or RxReg */
      MCHP_UART2_Rx.head = (MCHP_UART2_Rx.head+1) & (Rx_BUFF_SIZE_Uart2-1);
      U2LastValue = pwm1_B.U2Rx;
    } else {
      pwm1_B.U2Rx = U2LastValue;
    }
  }

  /* MCHP_UART_Tx Block for UARTRef 2: <Root>/UART Tx/Outputs */
  {
    uint16_T Tmp;
    Tmp = ~(MCHP_UART2_Tx.tail - MCHP_UART2_Tx.head);
    Tmp = Tmp & (Tx_BUFF_SIZE_Uart2 - 1);/* Modulo Buffer Size */
    if (Tmp != 0) {
      MCHP_UART2_Tx.buffer[MCHP_UART2_Tx.tail] = pwm1_B.U2Rx;
      MCHP_UART2_Tx.tail = (MCHP_UART2_Tx.tail + 1) & (Tx_BUFF_SIZE_Uart2 - 1);
      Tmp--;
    }

    _U2TXIF = U2STAbits.TRMT;
  }
}

/* Model step wrapper function for compatibility with a static main program */
void pwm1_step(int_T tid)
{
  switch (tid) {
   case 0 :
    pwm1_step0();
    break;

   case 1 :
    pwm1_step1();
    break;

   case 2 :
    pwm1_step2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void pwm1_initialize(void)
{
  /* Registration code */

  /* block I/O */
  (void) memset(((void *) &pwm1_B), 0,
                sizeof(B_pwm1_T));

  /* states (dwork) */
  (void) memset((void *)&pwm1_DW, 0,
                sizeof(DW_pwm1_T));

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* Start for S-Function (MCHP_PWM): '<S1>/ENABLE' */
  PWM1CON1 = 0x20;
  PWM1CON2 = 0x06;
  P1DTCON1 = 0x00;
  P1DTCON2 = 0x01;
  P1FLTACON = 0x86;
  P1TPER = 0x07CF;
  P1SECMP = 0xC8;
  P1TCON = 0x8000;                     /* Enable PWM */

  /* MCHP_Digital_Output_Write Block: '<S3>/Digital Output Write' */
  LATCbits.LATC8 = FALSE;

  /* MCHP_UART_Config Block for UART 2: <Root>/UART DEBUG/Initialize */
  U2BRG = 0x56;                        /* Baud rate: 115200 (-0.22%) */
  U2MODE = 0x8008;
  U2STA = 0x2400;

  /* Configure UART2 Tx Interruption */
  MCHP_UART2_Tx.head = 0;              /* Initialise Circular Buffers */
  MCHP_UART2_Tx.tail = 0;
  _U2TXIP = 1;                         /* Tx Interrupt priority set to 1 */
  _U2TXIF = 0;
  _U2TXIE = 1;                         /* Enable Interrupt */

  /* Configure UART2 Rx Interruption */
  MCHP_UART2_Rx.head = 0;              /* Initialise Circular Buffers */
  MCHP_UART2_Rx.tail = 0;
  _U2RXIP = 1;                         /* Rx Interrupt priority set to 1 */
  _U2RXIF = 0;
  _U2RXIE = 1;                         /* Enable Interrupt */

  /* InitializeConditions for Delay: '<S1>/Integer Delay3' */
  pwm1_DW.IntegerDelay3_DSTATE = TRUE;
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
