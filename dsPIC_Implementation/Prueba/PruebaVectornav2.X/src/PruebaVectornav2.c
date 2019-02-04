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
 * File: PruebaVectornav2.c
 *
 * Real-Time Workshop code generated for Simulink model PruebaVectornav2.
 *
 * Model version                        : 1.32
 * Real-Time Workshop file version      : 8.5 (R2013b) 08-Aug-2013
 * Real-Time Workshop file generated on : Tue Sep 29 15:29:36 2015
 * TLC version                          : 8.5 (Aug  6 2013)
 * C source code generated on           : Tue Sep 29 15:29:36 2015
 */

#include "PruebaVectornav2.h"
#include "PruebaVectornav2_private.h"

/* Block signals (auto storage) */
B_PruebaVectornav2_T PruebaVectornav2_B;

/* Real-time model */
RT_MODEL_PruebaVectornav2_T PruebaVectornav2_M_;
RT_MODEL_PruebaVectornav2_T *const PruebaVectornav2_M = &PruebaVectornav2_M_;

/* Model step function for TID0 */
void PruebaVectornav2_step0(void)      /* Sample time: [0.001s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID1 */
void PruebaVectornav2_step1(void)      /* Sample time: [0.01s, 0.0s] */
{
  /* MCHP_UART_Rx Block for UARTRef 1: <Root>/UART Rx/Outputs */
  {
    {
      int_T i1;
      uint8_T *y0 = &PruebaVectornav2_B.U1Rx[0] ;
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

  /* MCHP_UART_Tx Block for UARTRef 2: <Root>/UART Tx/Outputs */
  {
    uint16_T Tmp;
    Tmp = ~(MCHP_UART2_Tx.tail - MCHP_UART2_Tx.head);
    Tmp = Tmp & (Tx_BUFF_SIZE_Uart2 - 1);/* Modulo Buffer Size */

    {
      int_T i1;
      uint8_T *u0 = &PruebaVectornav2_B.U1Rx[0] ;
      for (i1 = 0; i1 < 128 ; i1++) {
        if ((Tmp != 0) && (u0[i1] != 0)) {
          MCHP_UART2_Tx.buffer[MCHP_UART2_Tx.tail] = u0[i1];
          MCHP_UART2_Tx.tail = (MCHP_UART2_Tx.tail + 1) & (Tx_BUFF_SIZE_Uart2 -
            1);
          Tmp--;
        } else
          break;
      }
    }

    _U2TXIF = U2STAbits.TRMT;
  }
}

/* Model step wrapper function for compatibility with a static main program */
void PruebaVectornav2_step(int_T tid)
{
  switch (tid) {
   case 0 :
    PruebaVectornav2_step0();
    break;

   case 1 :
    PruebaVectornav2_step1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void PruebaVectornav2_initialize(void)
{
  /* Registration code */

  /* block I/O */
  (void) memset(((void *) &PruebaVectornav2_B), 0,
                sizeof(B_PruebaVectornav2_T));

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
  /* Initialisation sequence for UART 1 */
  {
    const uint8_T InitSequence[15] = { 36, 86, 78, 87, 82, 71, 44, 48, 54, 44,
      49, 50, 42, 88, 88 };

    U1BRG = 0x56;                      /* Baud rate: 115200 (-0.22%) */
    U1MODE = 0x8008;
    U1STA = 0x2400;
    __delay32(1042);                   /* Wait for 1042 cycles */

    {
      uint_T i1;
      for (i1 = 0; i1 < 15 ; i1++) {
        while (U1STAbits.UTXBF == 1) ; /* Wait for one empty space within buffer UART */
        U1TXREG = InitSequence[i1];
      }
    }

    while (U1STAbits.TRMT == 0) ;      /* Wait for all value to be sent */
    U1MODE = 0;                        /* Then switch off UART */
  }

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
