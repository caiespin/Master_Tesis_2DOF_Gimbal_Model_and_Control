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
 * File: ControlSM_Tilt.c
 *
 * Real-Time Workshop code generated for Simulink model ControlSM_Tilt.
 *
 * Model version                        : 1.93
 * Real-Time Workshop file version      : 8.5 (R2013b) 08-Aug-2013
 * Real-Time Workshop file generated on : Thu Oct 01 16:59:36 2015
 * TLC version                          : 8.5 (Aug  6 2013)
 * C source code generated on           : Thu Oct 01 16:59:37 2015
 */

#include "ControlSM_Tilt.h"
#include "ControlSM_Tilt_private.h"

/* Block signals (auto storage) */
B_ControlSM_Tilt_T ControlSM_Tilt_B;

/* Block states (auto storage) */
DW_ControlSM_Tilt_T ControlSM_Tilt_DW;

/* Real-time model */
RT_MODEL_ControlSM_Tilt_T ControlSM_Tilt_M_;
RT_MODEL_ControlSM_Tilt_T *const ControlSM_Tilt_M = &ControlSM_Tilt_M_;

/* Model step function for TID0 */
void ControlSM_Tilt_step0(void)        /* Sample time: [0.001s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID1 */
void ControlSM_Tilt_step1(void)        /* Sample time: [0.025s, 0.0s] */
{
  /* local block i/o variables */
  boolean_T rtb_Compare;
  real_T rtb_UnaryMinus2;
  real_T rtb_Gain;
  uint16_T rtb_Gain_0;

  /* MCHP_UART_Rx Block for UARTRef 1: <Root>/UART Rx/Outputs */
  {
    {
      int_T i1;
      uint8_T *y0 = &ControlSM_Tilt_B.U1Rx[0] ;
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

  /* S-Function (MCHP_C_function_Call): '<Root>/C Function Call1' */
  send_wTz(
           &ControlSM_Tilt_B.U1Rx[0]
           );

  /* S-Function (MCHP_C_function_Call): '<Root>/C Function Call' */
  ControlSM_Tilt_B.CFunctionCall = Receive_wTy(
    &ControlSM_Tilt_B.U1Rx[0]
    );

  /* UnaryMinus: '<S2>/Unary Minus2' */
  rtb_UnaryMinus2 = -ControlSM_Tilt_B.CFunctionCall;

  /* Sum: '<S2>/Add' incorporates:
   *  Constant: '<S2>/Constant1'
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
   *  Product: '<S2>/Product'
   *  UnaryMinus: '<S2>/Unary Minus2'
   */
  rtb_Gain = ControlSM_Tilt_DW.DiscreteTimeIntegrator_DSTATE * 550.0 +
    -ControlSM_Tilt_B.CFunctionCall;

  /* Saturate: '<S2>/Saturation' */
  if (rtb_Gain >= 1.0) {
    rtb_Gain = 1.0;
  } else {
    if (rtb_Gain <= -1.0) {
      rtb_Gain = -1.0;
    }
  }

  /* Gain: '<S2>/Gain' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   *  Product: '<S2>/Product1'
   *  Product: '<S2>/Product2'
   *  Product: '<S2>/Product3'
   *  Saturate: '<S2>/Saturation'
   *  Sum: '<S2>/Add1'
   *  UnaryMinus: '<S2>/Unary Minus'
   *  UnaryMinus: '<S2>/Unary Minus1'
   *  UnaryMinus: '<S2>/Unary Minus2'
   */
  rtb_Gain = (-(-ControlSM_Tilt_B.CFunctionCall * 550.0) + -(rtb_Gain * 10.0)) *
    0.17817 * 2.4;

  /* RelationalOperator: '<S5>/Compare' incorporates:
   *  Constant: '<S5>/Constant'
   */
  rtb_Compare = (rtb_Gain >= 0.0);

  /* S-Function (MCHP_Digital_Output_Write): '<S6>/Digital Output Write' */
  LATBbits.LATB11 = rtb_Compare;

  /* Abs: '<S1>/Abs' */
  if (rtb_Gain < 0.0) {
    rtb_Gain = floor(-rtb_Gain);
    if (rtIsInf(rtb_Gain)) {
      rtb_Gain_0 = 0U;
    } else {
      rtb_Gain_0 = (uint16_T)fmod(rtb_Gain, 65536.0);
    }
  } else {
    rtb_Gain = floor(rtb_Gain);
    if (rtIsNaN(rtb_Gain) || rtIsInf(rtb_Gain)) {
      rtb_Gain_0 = 0U;
    } else {
      rtb_Gain_0 = (uint16_T)fmod(rtb_Gain, 65536.0);
    }
  }

  /* End of Abs: '<S1>/Abs' */

  /* Saturate: '<S1>/Saturation' */
  if (rtb_Gain_0 <= 3997U) {
    ControlSM_Tilt_B.Saturation = rtb_Gain_0;
  } else {
    ControlSM_Tilt_B.Saturation = 3997U;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* S-Function (MCHP_PWM): '<S1>/PWM' */
  /* PWM Output Function !! */

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  ControlSM_Tilt_DW.DiscreteTimeIntegrator_DSTATE += 0.025 * rtb_UnaryMinus2;

  /* Update for S-Function (MCHP_PWM): '<S1>/PWM' */
  P1DC2 = ControlSM_Tilt_B.Saturation; /* Period for Channel 2 */
}

/* Model step wrapper function for compatibility with a static main program */
void ControlSM_Tilt_step(int_T tid)
{
  switch (tid) {
   case 0 :
    ControlSM_Tilt_step0();
    break;

   case 1 :
    ControlSM_Tilt_step1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void ControlSM_Tilt_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* block I/O */
  (void) memset(((void *) &ControlSM_Tilt_B), 0,
                sizeof(B_ControlSM_Tilt_T));

  /* states (dwork) */
  (void) memset((void *)&ControlSM_Tilt_DW, 0,
                sizeof(DW_ControlSM_Tilt_T));

  /* S-Function "Microchip MASTER" initialization Block: <Root>/Microchip Master */

  /* Start for S-Function (MCHP_PWM): '<S1>/PWM' */
  PWM1CON1 = 0x20;
  PWM1CON2 = 0x06;
  P1DTCON1 = 0x00;
  P1DTCON2 = 0x01;
  P1FLTACON = 0x80;
  P1TPER = 0x07CF;
  P1SECMP = 0xC8;
  P1TCON = 0x8000;                     /* Enable PWM */

  /* MCHP_Digital_Output_Write Block: '<S7>/Digital Output Write' */
  LATCbits.LATC8 = TRUE;

  /* MCHP_Digital_Output_Write Block: '<S3>/Digital Output Write' */
  LATBbits.LATB2 = FALSE;

  /* MCHP_Digital_Output_Write Block: '<S4>/Digital Output Write' */
  LATAbits.LATA8 = FALSE;

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
