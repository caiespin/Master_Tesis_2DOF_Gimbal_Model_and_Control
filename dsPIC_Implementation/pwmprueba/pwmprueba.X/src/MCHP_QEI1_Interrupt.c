#include "pwmprueba.h"
#include "pwmprueba_private.h"

volatile uint16_T MCHP_QEI1_Count ;
void __attribute__((__interrupt__,__shadow__,__auto_psv__)) _QEI1Interrupt(void)
{
  _QEI1IF = 0;                         /* Clear Interrupt Flag */
  if (QEI1CONbits.UPDN == 1)           /* Use direction for detecting upward or downard turn count */
    MCHP_QEI1_Count++;
  else
    MCHP_QEI1_Count--;
}
