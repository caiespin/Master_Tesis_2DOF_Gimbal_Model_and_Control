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
 * File: VectorNavRead_main.c
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

/* Microchip Global Variables */
/* Set Fuses Options */
_FOSCSEL( FNOSC_PRI ) ;
_FOSC( POSCMD_EC & OSCIOFNC_ON & FCKSM_CSECMD ) ;
_FWDT( FWDTEN_OFF ) ;
_FPOR( FPWRT_PWR16 ) ;
_FICD( ICS_PGD3 & JTAGEN_OFF ) ;

/* Scheduler */
void __attribute__((__interrupt__,__auto_psv__)) _T1Interrupt(void)
{
  {
    struct {
      unsigned int Flags0 : 1;
      unsigned int Flags1 : 1;
    } static volatile Overrun;

    struct {
      unsigned int Flags0 : 1;
      unsigned int Flags1 : 1;
    } static volatile event;

    static int_T taskCounter[2] = { 0, 0 };

    _T1IF = 0;                         /* Re-enable interrupt */

    /* Check subrate overrun, set rates that need to run this time step*/
    if (taskCounter[1] == 0) {         /* task dropped on overload */
      event.Flags1 = 1U;
    }

    /* Update task internal counters */
    taskCounter[1]++;
    if (taskCounter[1] == 10) {
      taskCounter[1]= 0;
    }

    /* Step the model for base rate */
    /* Start profiling task 0 */
    VectorNavRead_step(0);

    /* Get model outputs here */
    _T1IF = 0;

    /* Stop profiling task 0 */
    if (_T1IF) {
      return;                          /* Will re-enter into the interrupt */
    }

    /* Re-Enable Interrupt */
    _IPL0 = 1;                         /* Set IPL to 1 (interrupt priority is 2) */
    _IPL1 = 0;

    /* Step the model for any subrate */
    /* Handle Task 1 */
    if (Overrun.Flags1) {
      return;                          /* Priority to higher rate steps interrupted */
    }

    if (event.Flags1) {
      Overrun.Flags1 = 1;
      do {
        /* Start profiling task 1 */
        event.Flags1 = 0U;
        VectorNavRead_step(1);

        /* Get model outputs here */
        ;                              /* Execute task tid 1 */

        /* Stop profiling task 1 */
      } while (event.Flags1);

      Overrun.Flags1 = 0U;
    }

    _IPL1 = 1;
    _IPL0 = 0;
  }
}

int main()
{
  /* Initialize model */
  /* Start Clock Switching */
  if ((OSCCONbits.COSC & 1) && !(OSCCONbits.COSC & 4))/* check not already in PLL mode (0?1) */
  {
    __builtin_write_OSCCONH(0);        /* Clock Switch to non PLL mode */
    __builtin_write_OSCCONL(0x01);     /* Start clock switching */
    asm("nop");
    asm("nop");
    while (OSCCONbits.COSC != 0) ;
  }

  PLLFBD = 0x9E;                       /* configure Oscillator PLL : PLLDIV */
  CLKDIV = 0x19;                       /* configure Oscillator PLL : FRCDIV ; PLLPOST ; PLLPRE */
  __builtin_write_OSCCONH(3);          /* Clock Switch to desired configuration */
  __builtin_write_OSCCONL(0x01);       /* Start clock switching */

  /* Configure Pins as Analog or Digital */
  AD1PCFGL = 0;

  /* Configure Remappables Pins */
  RPINR18 = 0x0E;
  RPINR19 = 0x15;
  RPOR6 = 0x0300;
  RPOR10 = 0x05;

  /* Configure Digitals I/O directions */
  TRISB = 0xDFFF;
  TRISC = 0xFFEF;

  /* Finish clock switching procedure */
  while (OSCCONbits.COSC != 3) ;       /* Wait for Oscillator Stabilisation */
  while (OSCCONbits.LOCK != 1) ;       /* Wait for PLL Stabilisation */

  /* Initialize model */
  VectorNavRead_initialize();

  /* Configure Timers */
  /* Configuration for TIMER 1 */
  _T1IP = 2;
  _T1IF = 0;
  _T1IE = 1;                           /* Enable Timer interrupt. */
  PR1 = 0x9C3F;                        /* Period */

  /* Timer 1 will be enabled after the configuration function. */

  /* Enable Time-step */
  TMR1 = 0x9C3E;
  T1CON = 0x8000;                      /* Timer 1 is the source trigger for the model Time-step */

  /* Main Loop */
  for (;;) ;
}                                      /* end of main() */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
