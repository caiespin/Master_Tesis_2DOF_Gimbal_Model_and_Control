#include "ControlPI_Pan.h"
#include "ControlPI_Pan_private.h"

MCHP_UART2_RxStr MCHP_UART2_Rx;
void __attribute__((__interrupt__,__auto_psv__)) _U2RXInterrupt(void)
{
  uint_T Tmp;
  Tmp = ~(MCHP_UART2_Rx.tail - MCHP_UART2_Rx.head);/* head - tail - 1 */
  Tmp &= (Rx_BUFF_SIZE_Uart2-1);       /* Tmp =  (head - tail - 1) modulo buffersize Rx_BUFF_SIZE_Uart2)	<==> Rx_BUFF_SIZE_Uart2 - (head - tail) - 1*/
  _U2RXIF = 0;
  while (U2STAbits.URXDA == 1) {
    if (Tmp--) {
      MCHP_UART2_Rx.buffer[MCHP_UART2_Rx.tail] = (uint8_T) U2RXREG;
      MCHP_UART2_Rx.tail = (MCHP_UART2_Rx.tail+1) & (Rx_BUFF_SIZE_Uart2-1);
    } else {
      unsigned int a;
      do
        a = U2RXREG;
      while (U2STAbits.URXDA == 1);
      break;
    }
  }

  if (U2STAbits.OERR == 1) {
    _U2RXIF = 0;
    U2STAbits.OERR = 0;                /* Buffer Overflow cleared */
  }
}
