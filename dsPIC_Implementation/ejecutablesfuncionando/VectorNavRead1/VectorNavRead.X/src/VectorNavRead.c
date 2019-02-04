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
 * File: VectorNavRead.c
 *
 * Real-Time Workshop code generated for Simulink model VectorNavRead.
 *
 * Model version                        : 1.45
 * Real-Time Workshop file version      : 8.5 (R2013b) 08-Aug-2013
 * Real-Time Workshop file generated on : Thu Apr 23 14:19:12 2015
 * TLC version                          : 8.5 (Aug  6 2013)
 * C source code generated on           : Thu Apr 23 14:19:13 2015
 */

#include "VectorNavRead.h"
#include "VectorNavRead_private.h"

/* Block signals (auto storage) */
B_VectorNavRead_T VectorNavRead_B;

/* Block states (auto storage) */
DW_VectorNavRead_T VectorNavRead_DW;

/* Real-time model */
RT_MODEL_VectorNavRead_T VectorNavRead_M_;
RT_MODEL_VectorNavRead_T *const VectorNavRead_M = &VectorNavRead_M_;

/* Model step function for TID0 */
void VectorNavRead_step0(void)         /* Sample time: [0.001s, 0.0s] */
{
  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.001s, 0.0s] to Sample time: [0.01s, 0.0s]  */
  (VectorNavRead_M->Timing.RateInteraction.TID0_1)++;
  if ((VectorNavRead_M->Timing.RateInteraction.TID0_1) > 9) {
    VectorNavRead_M->Timing.RateInteraction.TID0_1 = 0;
  }

  /* RateTransition: '<Root>/Rate Transition' */
  if (VectorNavRead_M->Timing.RateInteraction.TID0_1 == 1) {
    memcpy(&VectorNavRead_B.RateTransition[0L],
           &VectorNavRead_DW.RateTransition_Buffer0[0L], sizeof(uint8_T) << 7U);
  }

  /* End of RateTransition: '<Root>/Rate Transition' */

  /* S-Function (MCHP_C_function_Call): '<Root>/C Function Call' */
  VectorNavRead_B.U2Tx = check(
    &VectorNavRead_B.RateTransition[0]
    );

  /* RateTransition: '<Root>/Rate Transition1' */
  if (VectorNavRead_M->Timing.RateInteraction.TID0_1 == 1) {
    VectorNavRead_B.U2Tx_e = VectorNavRead_B.U2Tx;
  }

  /* End of RateTransition: '<Root>/Rate Transition1' */
}

/* Model step function for TID1 */
void VectorNavRead_step1(void)         /* Sample time: [0.01s, 0.0s] */
{
  /* MCHP_UART_Rx Block for UARTRef 1: <Root>/UART Rx/Outputs */
  {
    {
      int_T i1;
      uint8_T *y0 = &VectorNavRead_B.U1Rx[0] ;
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

  /* Update for RateTransition: '<Root>/Rate Transition' */
  memcpy(&VectorNavRead_DW.RateTransition_Buffer0[0L], &VectorNavRead_B.U1Rx[0L],
         sizeof(uint8_T) << 7U);

  /* MCHP_UART_Tx Block for UARTRef 2: <Root>/UART Tx/Outputs */
  {
    uint16_T Tmp;
    Tmp = ~(MCHP_UART2_Tx.tail - MCHP_UART2_Tx.head);
    Tmp = Tmp & (Tx_BUFF_SIZE_Uart2 - 1);/* Modulo Buffer Size */
    if (Tmp != 0) {
      MCHP_UART2_Tx.buffer[MCHP_UART2_Tx.tail] = VectorNavRead_B.U2Tx_e;
      MCHP_UART2_Tx.tail = (MCHP_UART2_Tx.tail + 1) & (Tx_BUFF_SIZE_Uart2 - 1);
      Tmp--;
    }

    _U2TXIF = U2STAbits.TRMT;
  }
}

/* Model step wrapper function for compatibility with a static main program */
void VectorNavRead_step(int_T tid)
{
  switch (tid) {
   case 0 :
    VectorNavRead_step0();
    break;

   case 1 :
    VectorNavRead_step1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void VectorNavRead_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)VectorNavRead_M, 0,
                sizeof(RT_MODEL_VectorNavRead_T));
  (VectorNavRead_M)->Timing.TaskCounters.cLimit[0] = 1;
  (VectorNavRead_M)->Timing.TaskCounters.cLimit[1] = 10;

  /* block I/O */
  (void) memset(((void *) &VectorNavRead_B), 0,
                sizeof(B_VectorNavRead_T));

  /* states (dwork) */
  (void) memset((void *)&VectorNavRead_DW, 0,
                sizeof(DW_VectorNavRead_T));

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
  _U1RXIP = 3;                         /* Rx Interrupt priority set to 3 */
  _U1RXIF = 0;
  _U1RXIE = 1;                         /* Enable Interrupt */
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
