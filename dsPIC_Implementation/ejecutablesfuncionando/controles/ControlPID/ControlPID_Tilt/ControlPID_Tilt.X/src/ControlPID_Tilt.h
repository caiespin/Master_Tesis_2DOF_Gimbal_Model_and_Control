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
 * File: ControlPID_Tilt.h
 *
 * Real-Time Workshop code generated for Simulink model ControlPID_Tilt.
 *
 * Model version                        : 1.86
 * Real-Time Workshop file version      : 8.5 (R2013b) 08-Aug-2013
 * Real-Time Workshop file generated on : Fri Oct 02 14:09:36 2015
 * TLC version                          : 8.5 (Aug  6 2013)
 * C source code generated on           : Fri Oct 02 14:09:36 2015
 */

#ifndef RTW_HEADER_ControlPID_Tilt_h_
#define RTW_HEADER_ControlPID_Tilt_h_
#ifndef ControlPID_Tilt_COMMON_INCLUDES_
# define ControlPID_Tilt_COMMON_INCLUDES_
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#endif                                 /* ControlPID_Tilt_COMMON_INCLUDES_ */

#include "ControlPID_Tilt_types.h"
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

/* Declare UART1 Tx Circular Buffer Structure */
#define Tx_BUFF_SIZE_Uart1             (128)

typedef struct MCHP_UART1_TxStr{
  volatile uint8_T buffer[Tx_BUFF_SIZE_Uart1];/* Size Rx_BUFF_SIZE_Uart1 is 128 */
  uint_T tail;                         /* tail is the index for the next value to be read from the Circular buffer */
  volatile uint_T head;                /* head is the index for the next value to be written into the Circular buffer */
} MCHP_UART1_TxStr;

/* Declare UART1 Rx Circular Buffer Structure */
#define Rx_BUFF_SIZE_Uart1             (128)

typedef struct MCHP_UART1_RxStr{
  volatile uint8_T buffer[Rx_BUFF_SIZE_Uart1];/* Size Rx_BUFF_SIZE_Uart1 is 128 */
  volatile uint_T tail;                /* tail is the index for the next value to be written into the Circular buffer */
  uint_T head;                         /* head is the index for the next value to be read from the Circular buffer */
} MCHP_UART1_RxStr;

/* To read the UART1 Rx Circular with a custom code: read the next value: buffer[head], then increment head index by 1 modulo Rx_BUFF_SIZE_Uart1 (=128).
   code example:
   if (U1STAbits.URXDA != 0) _U1RXIF = 1;  				// Flush internal UART buffer forcing the interrupt
   if (MCHP_UART1_Rx.tail != MCHP_UART1_Rx.head)	{  		// is buffer not empty ?
   output = (uint8_T) MCHP_UART1_Rx.buffer[MCHP_UART1_Rx.head ++];     // Read one char
   MCHP_UART1_Rx.head &= (Rx_BUFF_SIZE_Uart1-1); 	// modulo : use a simple bitewise "and" operator as <Rx_BUFF_SIZE_Uart1> is a power of 2
   }
 */

/* Block signals (auto storage) */
typedef struct {
  real_T CFunctionCall;                /* '<Root>/C Function Call' */
  uint16_T Saturation;                 /* '<S1>/Saturation' */
  uint8_T U1Rx[128];                   /* '<Root>/UART Rx' */
  boolean_T PWM;                       /* '<S1>/PWM' */
} B_ControlPID_Tilt_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S8>/Integrator' */
  real_T Filter_DSTATE;                /* '<S8>/Filter' */
} DW_ControlPID_Tilt_T;

/* Real-time Model Data Structure */
struct tag_RTM_ControlPID_Tilt_T {
  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
      uint8_T cLimit[2];
    } TaskCounters;
  } Timing;
};

/* Block signals (auto storage) */
extern B_ControlPID_Tilt_T ControlPID_Tilt_B;

/* Block states (auto storage) */
extern DW_ControlPID_Tilt_T ControlPID_Tilt_DW;

/* Model entry point functions */
extern void ControlPID_Tilt_initialize(void);
extern void ControlPID_Tilt_step(int_T tid);

/* Real-time Model object */
extern RT_MODEL_ControlPID_Tilt_T *const ControlPID_Tilt_M;

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
 * '<Root>' : 'ControlPID_Tilt'
 * '<S1>'   : 'ControlPID_Tilt/MOTOR_DRIVER'
 * '<S2>'   : 'ControlPID_Tilt/PI_CONTROL'
 * '<S3>'   : 'ControlPID_Tilt/Video_OSD_Selector'
 * '<S4>'   : 'ControlPID_Tilt/Video_Source_Selector'
 * '<S5>'   : 'ControlPID_Tilt/MOTOR_DRIVER/Compare To Zero'
 * '<S6>'   : 'ControlPID_Tilt/MOTOR_DRIVER/Digital Output'
 * '<S7>'   : 'ControlPID_Tilt/MOTOR_DRIVER/Digital Output1'
 * '<S8>'   : 'ControlPID_Tilt/PI_CONTROL/Discrete PID Controller'
 */
#endif                                 /* RTW_HEADER_ControlPID_Tilt_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
