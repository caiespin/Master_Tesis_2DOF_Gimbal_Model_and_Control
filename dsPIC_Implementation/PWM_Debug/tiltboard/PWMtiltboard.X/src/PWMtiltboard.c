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
 * File: PWMtiltboard.c
 *
 * Real-Time Workshop code generated for Simulink model PWMtiltboard.
 *
 * Model version                        : 1.27
 * Real-Time Workshop file version      : 8.5 (R2013b) 08-Aug-2013
 * Real-Time Workshop file generated on : Mon Apr 13 15:54:13 2015
 * TLC version                          : 8.5 (Aug  6 2013)
 * C source code generated on           : Mon Apr 13 15:54:13 2015
 */

#include "PWMtiltboard.h"
#include "PWMtiltboard_private.h"

/* Block signals (auto storage) */
B_PWMtiltboard_T PWMtiltboard_B;

/* Real-time model */
RT_MODEL_PWMtiltboard_T PWMtiltboard_M_;
RT_MODEL_PWMtiltboard_T *const PWMtiltboard_M = &PWMtiltboard_M_;

/* Model step function for TID0 */
void PWMtiltboard_step0(void)          /* Sample time: [0.001s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID1 */
void PWMtiltboard_step1(void)          /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (MCHP_PWM): '<Root>/PWM' */
  /* PWM Output Function !! */

  /* Update for S-Function (MCHP_PWM): '<Root>/PWM' */
  P1DC2 = 1000U;                       /* Period for Channel 2 */
}

/* Model step function for TID2 */
void PWMtiltboard_step2(void)          /* Sample time: [0.05s, 0.0s] */
{
  /* local block i/o variables */
  boolean_T rtb_LS_DWN_DS;

  /* S-Function (MCHP_Digital_Input): '<Root>/LS_DWN_DS' */

  /* MCHP_Digital_Input Block: <Root>/LS_DWN_DS/Output */
  rtb_LS_DWN_DS = PORTBbits.RB8;       /* Read pin B8 */

  /* S-Function (MCHP_Digital_Output_Write): '<S2>/Digital Output Write' incorporates:
   *  S-Function (MCHP_Digital_Input): '<Root>/LS_TP_DS'
   */
  LATBbits.LATB11 = PORTCbits.RC7;
}

/* Model step function for TID3 */
void PWMtiltboard_step3(void)          /* Sample time: [0.1s, 0.0s] */
{
  /* MCHP_UART_Rx Block for UARTRef 1: <Root>/UART Rx/Outputs */
  {
    static uint8_T U1LastValue ;
    if (MCHP_UART1_Rx.tail != MCHP_UART1_Rx.head) {
      PWMtiltboard_B.U1Rx = (uint8_T) MCHP_UART1_Rx.buffer[MCHP_UART1_Rx.head];/* Use only the 8 low bytes or RxReg */
      MCHP_UART1_Rx.head = (MCHP_UART1_Rx.head+1) & (Rx_BUFF_SIZE_Uart1-1);
      U1LastValue = PWMtiltboard_B.U1Rx;
    } else {
      PWMtiltboard_B.U1Rx = U1LastValue;
    }
  }

  /* MCHP_UART_Rx Block for UARTRef 2: <Root>/UART Rx1/Outputs */
  {
    static uint8_T U2LastValue ;
    if (MCHP_UART2_Rx.tail != MCHP_UART2_Rx.head) {
      PWMtiltboard_B.U2Rx = (uint8_T) MCHP_UART2_Rx.buffer[MCHP_UART2_Rx.head];/* Use only the 8 low bytes or RxReg */
      MCHP_UART2_Rx.head = (MCHP_UART2_Rx.head+1) & (Rx_BUFF_SIZE_Uart2-1);
      U2LastValue = PWMtiltboard_B.U2Rx;
    } else {
      PWMtiltboard_B.U2Rx = U2LastValue;
    }
  }

  /* MCHP_UART_Tx Block for UARTRef 1: <Root>/UART Tx1/Outputs */
  {
    uint16_T Tmp;
    Tmp = ~(MCHP_UART1_Tx.tail - MCHP_UART1_Tx.head);
    Tmp = Tmp & (Tx_BUFF_SIZE_Uart1 - 1);/* Modulo Buffer Size */
    if (Tmp != 0) {
      MCHP_UART1_Tx.buffer[MCHP_UART1_Tx.tail] = PWMtiltboard_B.U1Rx;
      MCHP_UART1_Tx.tail = (MCHP_UART1_Tx.tail + 1) & (Tx_BUFF_SIZE_Uart1 - 1);
      Tmp--;
    }

    _U1TXIF = U1STAbits.TRMT;
  }

  /* MCHP_UART_Tx Block for UARTRef 2: <Root>/UART Tx/Outputs */
  {
    uint16_T Tmp;
    Tmp = ~(MCHP_UART2_Tx.tail - MCHP_UART2_Tx.head);
    Tmp = Tmp & (Tx_BUFF_SIZE_Uart2 - 1);/* Modulo Buffer Size */
    if (Tmp != 0) {
      MCHP_UART2_Tx.buffer[MCHP_UART2_Tx.tail] = PWMtiltboard_B.U2Rx;
      MCHP_UART2_Tx.tail = (MCHP_UART2_Tx.tail + 1) & (Tx_BUFF_SIZE_Uart2 - 1);
      Tmp--;
    }

    _U2TXIF = U2STAbits.TRMT;
  }
}

/* Model step wrapper function for compatibility with a static main program */
void PWMtiltboard_step(int_T tid)
{
  switch (tid) {
   case 0 :
    PWMtiltboard_step0();
    break;

   case 1 :
    PWMtiltboard_step1();
    break;

   case 2 :
    PWMtiltboard_step2();
    break;

   case 3 :
    PWMtiltboard_step3();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void PWMtiltboard_initialize(void)
{
  /* Registration code */

  /* block I/O */
  (void) memset(((void *) &PWMtiltboard_B), 0,
                sizeof(B_PWMtiltboard_T));

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* MCHP_Digital_Output_Write Block: '<S1>/Digital Output Write' */
  LATCbits.LATC8 = TRUE;

  /* Start for S-Function (MCHP_PWM): '<Root>/PWM' */
  PWM1CON1 = 0x20;
  PWM1CON2 = 0x06;
  P1DTCON1 = 0x00;
  P1DTCON2 = 0x01;
  P1FLTACON = 0x80;
  P1TPER = 0x07CF;
  P1SECMP = 0xC8;
  P1TCON = 0x8000;                     /* Enable PWM */

  /* MCHP_UART_Config Block for UART 2: <Root>/UART Configuration/Initialize */
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

  /* MCHP_UART_Config Block for UART 1: <Root>/UART Configuration1/Initialize */
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
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
