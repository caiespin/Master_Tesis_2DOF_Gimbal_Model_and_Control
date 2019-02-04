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
 * File: PruebaComReadwTy.c
 *
 * Real-Time Workshop code generated for Simulink model PruebaComReadwTy.
 *
 * Model version                        : 1.59
 * Real-Time Workshop file version      : 8.5 (R2013b) 08-Aug-2013
 * Real-Time Workshop file generated on : Tue Jun 23 11:57:18 2015
 * TLC version                          : 8.5 (Aug  6 2013)
 * C source code generated on           : Tue Jun 23 11:57:19 2015
 */

#include "PruebaComReadwTy.h"
#include "PruebaComReadwTy_private.h"

/* Block signals (auto storage) */
B_PruebaComReadwTy_T PruebaComReadwTy_B;

/* Real-time model */
RT_MODEL_PruebaComReadwTy_T PruebaComReadwTy_M_;
RT_MODEL_PruebaComReadwTy_T *const PruebaComReadwTy_M = &PruebaComReadwTy_M_;

/* Model step function for TID0 */
void PruebaComReadwTy_step0(void)      /* Sample time: [0.001s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID1 */
void PruebaComReadwTy_step1(void)      /* Sample time: [0.025s, 0.0s] */
{
  /* MCHP_UART_Rx Block for UARTRef 1: <Root>/UART Rx/Outputs */
  {
    {
      int_T i1;
      uint8_T *y0 = &PruebaComReadwTy_B.U1Rx[0] ;
      for (i1 = 0; i1 < 128 ; i1++) {
        if (MCHP_UART1_Rx.tail != MCHP_UART1_Rx.head) {
          y0[i1] = (uint8_T) MCHP_UART1_Rx.buffer[MCHP_UART1_Rx.head];/* Use only the 8 low bytes or RxReg */
          MCHP_UART1_Rx.head = (MCHP_UART1_Rx.head+1) & (Rx_BUFF_SIZE_Uart1-1);
        } else {
          break;
        }
      }

      y0[i1] = 0;                      /* add one trailing 0, Watch out, last value is erased if the output vector is 'full'. */
    }
  }

  /* S-Function (MCHP_C_function_Call): '<Root>/C Function Call' */
  send_wTy(
           &PruebaComReadwTy_B.U1Rx[0]
           );
}

/* Model step wrapper function for compatibility with a static main program */
void PruebaComReadwTy_step(int_T tid)
{
  switch (tid) {
   case 0 :
    PruebaComReadwTy_step0();
    break;

   case 1 :
    PruebaComReadwTy_step1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void PruebaComReadwTy_initialize(void)
{
  /* Registration code */

  /* block I/O */
  (void) memset(((void *) &PruebaComReadwTy_B), 0,
                sizeof(B_PruebaComReadwTy_T));

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* MCHP_UART_Config Block for UART 2: <Root>/UART Configuration/Initialize */
  U2BRG = 0x56;                        /* Baud rate: 115200 (-0.22%) */
  U2MODE = 0x8008;
  U2STA = 0x0400;

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
  _U1RXIP = 3;                         /* Rx Interrupt priority set to 3 */
  _U1RXIF = 0;
  _U1RXIE = 1;                         /* Enable Interrupt */
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
