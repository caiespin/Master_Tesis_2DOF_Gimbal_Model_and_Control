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
 * File: ControlPID_Pan.c
 *
 * Real-Time Workshop code generated for Simulink model ControlPID_Pan.
 *
 * Model version                        : 1.85
 * Real-Time Workshop file version      : 8.5 (R2013b) 08-Aug-2013
 * Real-Time Workshop file generated on : Fri Oct 02 14:03:15 2015
 * TLC version                          : 8.5 (Aug  6 2013)
 * C source code generated on           : Fri Oct 02 14:03:16 2015
 */

#include "ControlPID_Pan.h"
#include "ControlPID_Pan_private.h"

/* Block signals (auto storage) */
B_ControlPID_Pan_T ControlPID_Pan_B;

/* Block states (auto storage) */
DW_ControlPID_Pan_T ControlPID_Pan_DW;

/* Real-time model */
RT_MODEL_ControlPID_Pan_T ControlPID_Pan_M_;
RT_MODEL_ControlPID_Pan_T *const ControlPID_Pan_M = &ControlPID_Pan_M_;

/* Model step function for TID0 */
void ControlPID_Pan_step0(void)        /* Sample time: [0.001s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID1 */
void ControlPID_Pan_step1(void)        /* Sample time: [0.025s, 0.0s] */
{
  /* local block i/o variables */
  boolean_T rtb_Compare;
  real_T rtb_Sum;
  real_T rtb_FilterCoefficient;
  uint16_T rtb_Sum_0;

  /* MCHP_UART_Rx Block for UARTRef 1: <Root>/UART Rx/Outputs */
  {
    {
      int_T i1;
      uint8_T *y0 = &ControlPID_Pan_B.U1Rx[0] ;
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
  ControlPID_Pan_B.CFunctionCall = Receive_wTz(
    &ControlPID_Pan_B.U1Rx[0]
    );

  /* Gain: '<S6>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S6>/Filter'
   *  Gain: '<S6>/Derivative Gain'
   *  Sum: '<S6>/SumD'
   */
  rtb_FilterCoefficient = (110.0 * ControlPID_Pan_B.CFunctionCall -
    ControlPID_Pan_DW.Filter_DSTATE) * 0.0;

  /* Sum: '<S6>/Sum' incorporates:
   *  DiscreteIntegrator: '<S6>/Integrator'
   *  Gain: '<S6>/Proportional Gain'
   */
  rtb_Sum = (350.0 * ControlPID_Pan_B.CFunctionCall +
             ControlPID_Pan_DW.Integrator_DSTATE) + rtb_FilterCoefficient;

  /* RelationalOperator: '<S3>/Compare' incorporates:
   *  Constant: '<S3>/Constant'
   */
  rtb_Compare = (rtb_Sum >= 0.0);

  /* S-Function (MCHP_Digital_Output_Write): '<S5>/Digital Output Write' */
  LATAbits.LATA7 = rtb_Compare;

  /* Abs: '<S1>/Abs' */
  if (rtb_Sum < 0.0) {
    rtb_Sum = floor(-rtb_Sum);
    if (rtIsInf(rtb_Sum)) {
      rtb_Sum_0 = 0U;
    } else {
      rtb_Sum_0 = (uint16_T)fmod(rtb_Sum, 65536.0);
    }
  } else {
    rtb_Sum = floor(rtb_Sum);
    if (rtIsNaN(rtb_Sum) || rtIsInf(rtb_Sum)) {
      rtb_Sum_0 = 0U;
    } else {
      rtb_Sum_0 = (uint16_T)fmod(rtb_Sum, 65536.0);
    }
  }

  /* End of Abs: '<S1>/Abs' */

  /* Saturate: '<S1>/Saturation' */
  if (rtb_Sum_0 <= 3997U) {
    ControlPID_Pan_B.Saturation = rtb_Sum_0;
  } else {
    ControlPID_Pan_B.Saturation = 3997U;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* S-Function (MCHP_PWM): '<S1>/PWM' */
  /* PWM Output Function !! */

  /* Gain: '<S6>/Integral Gain' */
  rtb_Sum = 3200.0 * ControlPID_Pan_B.CFunctionCall;

  /* Update for DiscreteIntegrator: '<S6>/Integrator' */
  ControlPID_Pan_DW.Integrator_DSTATE += 0.025 * rtb_Sum;

  /* Update for DiscreteIntegrator: '<S6>/Filter' */
  ControlPID_Pan_DW.Filter_DSTATE += 0.025 * rtb_FilterCoefficient;

  /* Update for S-Function (MCHP_PWM): '<S1>/PWM' */
  P1DC1 = ControlPID_Pan_B.Saturation; /* Period for Channel 1 */

  /* MCHP_UART_Tx Block for UARTRef 2: <Root>/UART Tx/Outputs */
  {
    uint16_T Tmp;
    Tmp = ~(MCHP_UART2_Tx.tail - MCHP_UART2_Tx.head);
    Tmp = Tmp & (Tx_BUFF_SIZE_Uart2 - 1);/* Modulo Buffer Size */

    {
      int_T i1;
      uint8_T *u0 = &ControlPID_Pan_B.U1Rx[0] ;
      for (i1 = 0; i1 < 128 ; i1++) {
        if (Tmp != 0) {
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
void ControlPID_Pan_step(int_T tid)
{
  switch (tid) {
   case 0 :
    ControlPID_Pan_step0();
    break;

   case 1 :
    ControlPID_Pan_step1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void ControlPID_Pan_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* block I/O */
  (void) memset(((void *) &ControlPID_Pan_B), 0,
                sizeof(B_ControlPID_Pan_T));

  /* states (dwork) */
  (void) memset((void *)&ControlPID_Pan_DW, 0,
                sizeof(DW_ControlPID_Pan_T));

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* Start for S-Function (MCHP_PWM): '<S1>/PWM' */
  PWM1CON1 = 0x10;
  PWM1CON2 = 0x06;
  P1DTCON1 = 0x00;
  P1DTCON2 = 0x01;
  P1FLTACON = 0x80;
  P1TPER = 0x07CF;
  P1SECMP = 0xC8;
  P1TCON = 0x8000;                     /* Enable PWM */

  /* MCHP_Digital_Output_Write Block: '<S4>/Digital Output Write' */
  LATAbits.LATA10 = TRUE;

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