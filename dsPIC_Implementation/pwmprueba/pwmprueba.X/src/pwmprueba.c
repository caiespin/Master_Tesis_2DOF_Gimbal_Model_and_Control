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
 * File: pwmprueba.c
 *
 * Real-Time Workshop code generated for Simulink model pwmprueba.
 *
 * Model version                        : 1.33
 * Real-Time Workshop file version      : 8.5 (R2013b) 08-Aug-2013
 * Real-Time Workshop file generated on : Thu Mar 19 11:44:39 2015
 * TLC version                          : 8.5 (Aug  6 2013)
 * C source code generated on           : Thu Mar 19 11:44:40 2015
 */

#include "pwmprueba.h"
#include "pwmprueba_private.h"

/* Block signals (auto storage) */
B_pwmprueba_T pwmprueba_B;

/* Real-time model */
RT_MODEL_pwmprueba_T pwmprueba_M_;
RT_MODEL_pwmprueba_T *const pwmprueba_M = &pwmprueba_M_;

/* Model step function for TID0 */
void pwmprueba_step0(void)             /* Sample time: [0.001s, 0.0s] */
{
  /* local block i/o variables */
  boolean_T rtb_DigitalInput1;

  /* S-Function (MCHP_Digital_Input): '<Root>/Digital Input1' */

  /* MCHP_Digital_Input Block: <Root>/Digital Input1/Output */
  rtb_DigitalInput1 = PORTBbits.RB13;  /* Read pin B13 */

  /* S-Function (MCHP_QEI): '<Root>/QEI' */
  pwmprueba_B.U1CH1 = MCHP_QEI1_Count;
  pwmprueba_B.U1CH2 = POS1CNT;         /* Read QEI 1 position */

  /* MCHP_UART_Tx-Matlab Block for UARTRef 1: <Root>/UART Tx-Matlab/Outputs */
  {
    volatile static uint16_T index = 0;
    int16_T tmp;
    tmp = ~(MCHP_UART1_Tx.tail - MCHP_UART1_Tx.head);
    tmp = tmp & (Tx_BUFF_SIZE_Uart1 - 1);/* Modulo Buffer Size */
    if (tmp > 6)
      tmp = 6;                         /* Stop condition for do-while loop*/
    do {
      switch (index) {
       case 0:                         /* CH 1 */
        tmp = tmp - 3;
        if (tmp < 0)
          break;
        MCHP_UART1_Tx.buffer[MCHP_UART1_Tx.tail] = 5 ;/* Control byte */
        MCHP_UART1_Tx.tail = (MCHP_UART1_Tx.tail + 1) & (Tx_BUFF_SIZE_Uart1 - 1);
        MCHP_UART1_Tx.buffer[MCHP_UART1_Tx.tail] = pwmprueba_B.U1CH1 ;/* LSB First*/
        MCHP_UART1_Tx.tail = (MCHP_UART1_Tx.tail + 1) & (Tx_BUFF_SIZE_Uart1 - 1);
        MCHP_UART1_Tx.buffer[MCHP_UART1_Tx.tail] = (pwmprueba_B.U1CH1 >> 8);/* MSB Last*/
        MCHP_UART1_Tx.tail = (MCHP_UART1_Tx.tail + 1) & (Tx_BUFF_SIZE_Uart1 - 1);
        if (++index >= 2)
          index = 0;

       case 1:                         /* CH 2 */
        tmp = tmp - 3;
        if (tmp < 0)
          break;
        MCHP_UART1_Tx.buffer[MCHP_UART1_Tx.tail] = 21 ;/* Control byte */
        MCHP_UART1_Tx.tail = (MCHP_UART1_Tx.tail + 1) & (Tx_BUFF_SIZE_Uart1 - 1);
        MCHP_UART1_Tx.buffer[MCHP_UART1_Tx.tail] = pwmprueba_B.U1CH2 ;/* LSB First*/
        MCHP_UART1_Tx.tail = (MCHP_UART1_Tx.tail + 1) & (Tx_BUFF_SIZE_Uart1 - 1);
        MCHP_UART1_Tx.buffer[MCHP_UART1_Tx.tail] = (pwmprueba_B.U1CH2 >> 8);/* MSB Last*/
        MCHP_UART1_Tx.tail = (MCHP_UART1_Tx.tail + 1) & (Tx_BUFF_SIZE_Uart1 - 1);
        if (++index >= 2)
          index = 0;
      }
    } while (tmp >= 1);                /* either buffer is full or we send all datas */

    _U1TXIF = U1STAbits.TRMT;          /* enable interrupt ; */
  }
}

/* Model step function for TID1 */
void pwmprueba_step1(void)             /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (MCHP_PWM): '<Root>/PWM' */
  /* PWM Output Function !! */

  /* S-Function (MCHP_Digital_Output_Write): '<S2>/Digital Output Write' incorporates:
   *  S-Function (MCHP_Digital_Input): '<Root>/Digital Input'
   */
  LATAbits.LATA7 = PORTBbits.RB2;

  /* Update for S-Function (MCHP_PWM): '<Root>/PWM' */
  P1DC1 = 5000U;                       /* Period for Channel 1 */
}

/* Model step wrapper function for compatibility with a static main program */
void pwmprueba_step(int_T tid)
{
  switch (tid) {
   case 0 :
    pwmprueba_step0();
    break;

   case 1 :
    pwmprueba_step1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void pwmprueba_initialize(void)
{
  /* Registration code */

  /* block I/O */
  (void) memset(((void *) &pwmprueba_B), 0,
                sizeof(B_pwmprueba_T));

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* Start for S-Function (MCHP_PWM): '<Root>/PWM' */
  PWM1CON1 = 0x10;
  PWM1CON2 = 0x06;
  P1DTCON1 = 0x00;
  P1DTCON2 = 0x01;
  P1FLTACON = 0x80;
  P1TPER = 0x0F9F;
  P1SECMP = 0x07D0;
  P1TCON = 0x8000;                     /* Enable PWM */

  /* MCHP_Digital_Output_Write Block: '<S1>/Digital Output Write' */
  LATAbits.LATA10 = TRUE;

  /* Start for S-Function (MCHP_QEI): '<Root>/QEI' */
  /* Initialize QEI 1 Peripheral */
  MAX1CNT = 1023;
  DFLT1CON = 0x01F0;
  QEI1CON = 0x0D00;
  _QEI1IP = 5;
  _QEI1IF = 0;
  _QEI1IE = 1;                         /* Enable Interrupt */

  /* MCHP_UART_Config Block for UART 1: <Root>/UART Configuration/Initialize */
  U1BRG = 0xAD;                        /* Baud rate: 57600 (-0.22%) */
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
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
