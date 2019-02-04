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
 * File: comuserialmainboard.c
 *
 * Real-Time Workshop code generated for Simulink model comuserialmainboard.
 *
 * Model version                        : 1.23
 * Real-Time Workshop file version      : 8.5 (R2013b) 08-Aug-2013
 * Real-Time Workshop file generated on : Wed Apr 22 10:32:33 2015
 * TLC version                          : 8.5 (Aug  6 2013)
 * C source code generated on           : Wed Apr 22 10:32:34 2015
 */

#include "comuserialmainboard.h"
#include "comuserialmainboard_private.h"

/* Block signals (auto storage) */
B_comuserialmainboard_T comuserialmainboard_B;

/* Real-time model */
RT_MODEL_comuserialmainboard_T comuserialmainboard_M_;
RT_MODEL_comuserialmainboard_T *const comuserialmainboard_M =
  &comuserialmainboard_M_;

/* Model step function for TID0 */
void comuserialmainboard_step0(void)   /* Sample time: [0.001s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID1 */
void comuserialmainboard_step1(void)   /* Sample time: [0.1s, 0.0s] */
{
  /* MCHP_UART_Rx Block for UARTRef 1: <Root>/UART Rx/Outputs */
  {
    static uint8_T U1LastValue ;
    if (MCHP_UART1_Rx.tail != MCHP_UART1_Rx.head) {
      comuserialmainboard_B.U1Rx = (uint8_T)
        MCHP_UART1_Rx.buffer[MCHP_UART1_Rx.head];/* Use only the 8 low bytes or RxReg */
      MCHP_UART1_Rx.head = (MCHP_UART1_Rx.head+1) & (Rx_BUFF_SIZE_Uart1-1);
      U1LastValue = comuserialmainboard_B.U1Rx;
    } else {
      comuserialmainboard_B.U1Rx = U1LastValue;
    }
  }

  /* MCHP_UART_Tx Block for UARTRef 1: <Root>/UART Tx1/Outputs */
  {
    uint16_T Tmp;
    Tmp = ~(MCHP_UART1_Tx.tail - MCHP_UART1_Tx.head);
    Tmp = Tmp & (Tx_BUFF_SIZE_Uart1 - 1);/* Modulo Buffer Size */
    if (Tmp != 0) {
      MCHP_UART1_Tx.buffer[MCHP_UART1_Tx.tail] = ((uint8_T)50U);
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
      MCHP_UART2_Tx.buffer[MCHP_UART2_Tx.tail] = comuserialmainboard_B.U1Rx;
      MCHP_UART2_Tx.tail = (MCHP_UART2_Tx.tail + 1) & (Tx_BUFF_SIZE_Uart2 - 1);
      Tmp--;
    }

    _U2TXIF = U2STAbits.TRMT;
  }
}

/* Model step wrapper function for compatibility with a static main program */
void comuserialmainboard_step(int_T tid)
{
  switch (tid) {
   case 0 :
    comuserialmainboard_step0();
    break;

   case 1 :
    comuserialmainboard_step1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void comuserialmainboard_initialize(void)
{
  /* Registration code */

  /* block I/O */
  (void) memset(((void *) &comuserialmainboard_B), 0,
                sizeof(B_comuserialmainboard_T));

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

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
