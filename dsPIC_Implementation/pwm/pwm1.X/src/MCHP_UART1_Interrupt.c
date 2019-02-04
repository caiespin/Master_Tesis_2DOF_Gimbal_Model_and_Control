#include "pwm1.h"
#include "pwm1_private.h"

/* Declare UART1 Tx Circular Buffer Structure */
MCHP_UART1_TxStr MCHP_UART1_Tx;
MCHP_UART1_RxStr MCHP_UART1_Rx;
void __attribute__((__interrupt__,__auto_psv__)) _U1TXInterrupt(void)
{
  _U1TXIF = 0;
  while ((U1STAbits.UTXBF == 0) && (MCHP_UART1_Tx.tail != MCHP_UART1_Tx.head) )/* while UxTXREG buffer is not full */
  {
    U1TXREG = MCHP_UART1_Tx.buffer[MCHP_UART1_Tx.head];
    MCHP_UART1_Tx.head = (MCHP_UART1_Tx.head + 1) & (Tx_BUFF_SIZE_Uart1-1);
  }
}

void __attribute__((__interrupt__,__auto_psv__)) _U1RXInterrupt(void)
{
  uint_T Tmp;
  Tmp = ~(MCHP_UART1_Rx.tail - MCHP_UART1_Rx.head);/* head - tail - 1 */
  Tmp &= (Rx_BUFF_SIZE_Uart1-1);       /* Tmp =  (head - tail - 1) modulo buffersize Rx_BUFF_SIZE_Uart1)	<==> Rx_BUFF_SIZE_Uart1 - (head - tail) - 1*/
  _U1RXIF = 0;
  while (U1STAbits.URXDA == 1) {
    if (Tmp--) {
      MCHP_UART1_Rx.buffer[MCHP_UART1_Rx.tail] = (uint8_T) U1RXREG;
      MCHP_UART1_Rx.tail = (MCHP_UART1_Rx.tail+1) & (Rx_BUFF_SIZE_Uart1-1);
    } else {
      unsigned int a;
      do
        a = U1RXREG;
      while (U1STAbits.URXDA == 1);
      break;
    }
  }

  if (U1STAbits.OERR == 1) {
    _U1RXIF = 0;
    U1STAbits.OERR = 0;                /* Buffer Overflow cleared */
  }
}
