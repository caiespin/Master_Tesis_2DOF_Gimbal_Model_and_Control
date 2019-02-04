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
 * Model version                        : 1.57
 * Real-Time Workshop file version      : 8.5 (R2013b) 08-Aug-2013
 * Real-Time Workshop file generated on : Mon Apr 27 16:36:24 2015
 * TLC version                          : 8.5 (Aug  6 2013)
 * C source code generated on           : Mon Apr 27 16:36:24 2015
 */

#include "PruebaSendfloatMatlab.h"
#include "PruebaSendfloatMatlab_private.h"

/* Block signals (auto storage) */
B_PruebaSendfloatMatlab_T PruebaSendfloatMatlab_B;

/* Block states (auto storage) */
DW_PruebaSendfloatMatlab_T PruebaSendfloatMatlab_DW;

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
  uint16_T rtb_FixPtSum1;

  /* Trigonometry: '<Root>/Trigonometric Function' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  UnitDelay: '<S1>/Output'
   */
  PruebaSendfloatMatlab_B.TrigonometricFunction = sin
    (PruebaSendfloatMatlab_DW.Output_DSTATE);

  /* S-Function (MCHP_C_function_Call): '<Root>/C Function Call' */
  Send_float(
             PruebaSendfloatMatlab_B.TrigonometricFunction
             );

  /* Sum: '<S2>/FixPt Sum1' incorporates:
   *  Constant: '<S2>/FixPt Constant'
   *  UnitDelay: '<S1>/Output'
   */
  rtb_FixPtSum1 = PruebaSendfloatMatlab_DW.Output_DSTATE + 1U;

  /* Update for UnitDelay: '<S1>/Output' */
  PruebaSendfloatMatlab_DW.Output_DSTATE = rtb_FixPtSum1;
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
  /* Registration code */

  /* block I/O */
  (void) memset(((void *) &PruebaSendfloatMatlab_B), 0,
                sizeof(B_PruebaSendfloatMatlab_T));

  /* states (dwork) */
  (void) memset((void *)&PruebaSendfloatMatlab_DW, 0,
                sizeof(DW_PruebaSendfloatMatlab_T));

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
