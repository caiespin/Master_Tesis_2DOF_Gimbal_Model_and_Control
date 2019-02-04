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
 * Model version                        : 1.23
 * Real-Time Workshop file version      : 8.5 (R2013b) 08-Aug-2013
 * Real-Time Workshop file generated on : Fri Apr 24 16:07:46 2015
 * TLC version                          : 8.5 (Aug  6 2013)
 * C source code generated on           : Fri Apr 24 16:07:46 2015
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
  boolean_T rtb_DigitalInput;
  boolean_T rtb_Switch;
  boolean_T rtb_Toggle;

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input' */

  /* MCHP_Digital_Input Block: <Root>/Digital Input/Output */
  rtb_DigitalInput = PORTBbits.RB2;    /* Read pin B2 */

  /* Logic: '<Root>/Logical Operator1' incorporates:
   *  Delay: '<Root>/Integer Delay3'
   *  RelationalOperator: '<S1>/FixPt Relational Operator'
   *  UnitDelay: '<S1>/Delay Input1'
   */
  rtb_Toggle = ((int16_T)rtb_DigitalInput < (int16_T)pwm1_DW.DelayInput1_DSTATE)
    ^ pwm1_DW.IntegerDelay3_DSTATE;

  /* Switch: '<Root>/Switch' */
  rtb_Switch = rtb_Toggle;

  /* S-Function (MCHP_Digital_Output_Write): '<S3>/Digital Output Write' */
  LATAbits.LATA7 = rtb_Switch;

  /* S-Function (MCHP_QEI): '<Root>/QEI' */
  pwm1_B.U1CH1 = POS1CNT;              /* Read QEI 1 position */

  /* Update for Delay: '<Root>/Integer Delay3' */
  pwm1_DW.IntegerDelay3_DSTATE = rtb_Toggle;

  /* Update for UnitDelay: '<S1>/Delay Input1' */
  pwm1_DW.DelayInput1_DSTATE = rtb_DigitalInput;

  /* MCHP_UART_Tx-Matlab Block for UARTRef 1: <Root>/UART Tx-Matlab/Outputs */
  {
    volatile static uint16_T index = 0;
    int16_T tmp;
    tmp = ~(MCHP_UART1_Tx.tail - MCHP_UART1_Tx.head);
    tmp = tmp & (Tx_BUFF_SIZE_Uart1 - 1);/* Modulo Buffer Size */
    if (tmp > 3)
      tmp = 3;                         /* Stop condition for do-while loop*/
    do {
      switch (index) {
       case 0:                         /* CH 1 */
        tmp = tmp - 3;
        if (tmp < 0)
          break;
        MCHP_UART1_Tx.buffer[MCHP_UART1_Tx.tail] = 5 ;/* Control byte */
        MCHP_UART1_Tx.tail = (MCHP_UART1_Tx.tail + 1) & (Tx_BUFF_SIZE_Uart1 - 1);
        MCHP_UART1_Tx.buffer[MCHP_UART1_Tx.tail] = pwm1_B.U1CH1 ;/* LSB First*/
        MCHP_UART1_Tx.tail = (MCHP_UART1_Tx.tail + 1) & (Tx_BUFF_SIZE_Uart1 - 1);
        MCHP_UART1_Tx.buffer[MCHP_UART1_Tx.tail] = (pwm1_B.U1CH1 >> 8);/* MSB Last*/
        MCHP_UART1_Tx.tail = (MCHP_UART1_Tx.tail + 1) & (Tx_BUFF_SIZE_Uart1 - 1);
        if (++index >= 1)
          index = 0;
      }
    } while (tmp >= 1);                /* either buffer is full or we send all datas */

    _U1TXIF = U1STAbits.TRMT;          /* enable interrupt ; */
  }
}

/* Model step function for TID1 */
void pwm1_step1(void)                  /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (MCHP_PWM): '<Root>/PWM' */
  /* PWM Output Function !! */

  /* Update for S-Function (MCHP_PWM): '<Root>/PWM' */
  P1DC1 = 2500U;                       /* Period for Channel 1 */
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

  /* Start for S-Function (MCHP_PWM): '<Root>/PWM' */
  PWM1CON1 = 0x10;
  PWM1CON2 = 0x06;
  P1DTCON1 = 0x00;
  P1DTCON2 = 0x01;
  P1FLTACON = 0x86;
  P1TPER = 0x07CF;
  P1SECMP = 0xC8;
  P1TCON = 0x8000;                     /* Enable PWM */

  /* MCHP_Digital_Output_Write Block: '<S2>/Digital Output Write' */
  LATAbits.LATA10 = FALSE;

  /* Start for S-Function (MCHP_QEI): '<Root>/QEI' */
  /* Initialize QEI 1 Peripheral */
  MAX1CNT = 65535;
  DFLT1CON = 0x01F0;
  QEI1CON = 0x0C00;

  /* MCHP_UART_Config Block for UART 1: <Root>/UART Configuration/Initialize */
  U1BRG = 0x56;                        /* Baud rate: 115200 (-0.22%) */
  U1MODE = 0x8008;
  U1STA = 0x2400;

  /* Configure UART1 Tx Interruption */
  MCHP_UART1_Tx.head = 0;              /* Initialise Circular Buffers */
  MCHP_UART1_Tx.tail = 0;
  _U1TXIP = 1;                         /* Tx Interrupt priority set to 1 */
  _U1TXIF = 0;
  _U1TXIE = 1;                         /* Enable Interrupt */

  /* Configure UART1 Rx Interruption */
  MCHP_UART1_Rx.head = 0;              /* Initialise Circular Buffers */
  MCHP_UART1_Rx.tail = 0;
  _U1RXIP = 1;                         /* Rx Interrupt priority set to 1 */
  _U1RXIF = 0;
  _U1RXIE = 1;                         /* Enable Interrupt */

  /* InitializeConditions for Delay: '<Root>/Integer Delay3' */
  pwm1_DW.IntegerDelay3_DSTATE = TRUE;
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
