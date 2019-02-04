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
 * File: PruebaSendfloatMatlab.c
 *
 * Real-Time Workshop code generated for Simulink model PruebaSendfloatMatlab.
 *
 * Model version                        : 1.52
 * Real-Time Workshop file version      : 8.5 (R2013b) 08-Aug-2013
 * Real-Time Workshop file generated on : Mon Apr 27 15:01:43 2015
 * TLC version                          : 8.5 (Aug  6 2013)
 * C source code generated on           : Mon Apr 27 15:01:44 2015
 */

#include "PruebaSendfloatMatlab.h"
#include "PruebaSendfloatMatlab_private.h"

/* Real-time model */
RT_MODEL_PruebaSendfloatMatla_T PruebaSendfloatMatlab_M_;
RT_MODEL_PruebaSendfloatMatla_T *const PruebaSendfloatMatlab_M =
  &PruebaSendfloatMatlab_M_;

/* Model step function for TID0 */
void PruebaSendfloatMatlab_step0(void) /* Sample time: [0.001s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID1 */
void PruebaSendfloatMatlab_step1(void) /* Sample time: [0.1s, 0.0s] */
{
  /* S-Function (MCHP_C_function_Call): '<Root>/C Function Call' */
  WriteStringUART(
                  12.4546797
                  );
}

/* Model step wrapper function for compatibility with a static main program */
void PruebaSendfloatMatlab_step(int_T tid)
{
  switch (tid) {
   case 0 :
    PruebaSendfloatMatlab_step0();
    break;

   case 1 :
    PruebaSendfloatMatlab_step1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void PruebaSendfloatMatlab_initialize(void)
{
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
