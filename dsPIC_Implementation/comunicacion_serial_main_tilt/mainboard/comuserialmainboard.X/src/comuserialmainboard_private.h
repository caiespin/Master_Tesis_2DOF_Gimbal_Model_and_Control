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
 * File: comuserialmainboard_private.h
 *
 * Real-Time Workshop code generated for Simulink model comuserialmainboard.
 *
 * Model version                        : 1.23
 * Real-Time Workshop file version      : 8.5 (R2013b) 08-Aug-2013
 * Real-Time Workshop file generated on : Wed Apr 22 10:32:33 2015
 * TLC version                          : 8.5 (Aug  6 2013)
 * C source code generated on           : Wed Apr 22 10:32:34 2015
 */

#ifndef RTW_HEADER_comuserialmainboard_private_h_
#define RTW_HEADER_comuserialmainboard_private_h_
#include "rtwtypes.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

/* Declare UART2 Tx Circular Buffer Structure */
extern MCHP_UART2_TxStr MCHP_UART2_Tx;
extern MCHP_UART2_RxStr MCHP_UART2_Rx;

/* Declare UART1 Tx Circular Buffer Structure */
extern MCHP_UART1_TxStr MCHP_UART1_Tx;
extern MCHP_UART1_RxStr MCHP_UART1_Rx;
extern void comuserialmainboard_step0(void);
extern void comuserialmainboard_step1(void);

#endif                                 /* RTW_HEADER_comuserialmainboard_private_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
