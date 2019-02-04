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
 * File: pwm1.h
 *
 * Real-Time Workshop code generated for Simulink model pwm1.
 *
 * Model version                        : 1.20
 * Real-Time Workshop file version      : 8.5 (R2013b) 08-Aug-2013
 * Real-Time Workshop file generated on : Thu Apr 09 11:26:11 2015
 * TLC version                          : 8.5 (Aug  6 2013)
 * C source code generated on           : Thu Apr 09 11:26:11 2015
 */

#ifndef RTW_HEADER_pwm1_h_
#define RTW_HEADER_pwm1_h_
#ifndef pwm1_COMMON_INCLUDES_
# define pwm1_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* pwm1_COMMON_INCLUDES_ */

#include "pwm1_types.h"
#define FCY                            4.0E+7

/* Include for pic 33F */
#include <p33Fxxxx.h>
#include <libpic30.h>                  /* For possible use with C function Call block (delay_ms or delay_us functions might be used by few peripherals) */
#include <libq.h>                      /* For possible use with C function Call block */

/* Macros for accessing real-time model data structure */
#ifndef rtmCounterLimit
# define rtmCounterLimit(rtm, idx)     ((rtm)->Timing.TaskCounters.cLimit[(idx)])
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Declare UART2 Tx Circular Buffer Structure */
#define Tx_BUFF_SIZE_Uart2             (32)

typedef struct MCHP_UART2_TxStr{
  volatile uint8_T buffer[Tx_BUFF_SIZE_Uart2];/* Size Rx_BUFF_SIZE_Uart2 is 32 */
  uint_T tail;                         /* tail is the index for the next value to be read from the Circular buffer */
  volatile uint_T head;                /* head is the index for the next value to be written into the Circular buffer */
} MCHP_UART2_TxStr;

/* Declare UART2 Rx Circular Buffer Structure */
#define Rx_BUFF_SIZE_Uart2             (32)

typedef struct MCHP_UART2_RxStr{
  volatile uint8_T buffer[Rx_BUFF_SIZE_Uart2];/* Size Rx_BUFF_SIZE_Uart2 is 32 */
  volatile uint_T tail;                /* tail is the index for the next value to be written into the Circular buffer */
  uint_T head;                         /* head is the index for the next value to be read from the Circular buffer */
} MCHP_UART2_RxStr;

/* To read the UART2 Rx Circular with a custom code: read the next value: buffer[head], then increment head index by 1 modulo Rx_BUFF_SIZE_Uart2 (=32).
   code example:
   if (U2STAbits.URXDA != 0) _U2RXIF = 1;  				// Flush internal UART buffer forcing the interrupt
   if (MCHP_UART2_Rx.tail != MCHP_UART2_Rx.head)	{  		// is buffer not empty ?
   output = (uint8_T) MCHP_UART2_Rx.buffer[MCHP_UART2_Rx.head ++];     // Read one char
   MCHP_UART2_Rx.head &= (Rx_BUFF_SIZE_Uart2-1); 	// modulo : use a simple bitewise "and" operator as <Rx_BUFF_SIZE_Uart2> is a power of 2
   }
 */

/* Block signals (auto storage) */
typedef struct {
  uint8_T U2Rx;                        /* '<Root>/UART Rx' */
} B_pwm1_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  boolean_T IntegerDelay3_DSTATE;      /* '<S1>/Integer Delay3' */
  boolean_T DelayInput1_DSTATE;        /* '<S2>/Delay Input1' */
} DW_pwm1_T;

/* Real-time Model Data Structure */
struct tag_RTM_pwm1_T {
  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[3];
      uint8_T cLimit[3];
    } TaskCounters;
  } Timing;
};

/* Block signals (auto storage) */
extern B_pwm1_T pwm1_B;

/* Block states (auto storage) */
extern DW_pwm1_T pwm1_DW;

/* Model entry point functions */
extern void pwm1_initialize(void);
extern void pwm1_step(int_T tid);

/* Real-time Model object */
extern RT_MODEL_pwm1_T *const pwm1_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'pwm1'
 * '<S1>'   : 'pwm1/DRIVER'
 * '<S2>'   : 'pwm1/DRIVER/Change when button is pressed'
 * '<S3>'   : 'pwm1/DRIVER/MODE'
 * '<S4>'   : 'pwm1/DRIVER/PHASE'
 */
#endif                                 /* RTW_HEADER_pwm1_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
