/**
 * @file:   serialPort.c
 * @author: Rafael Alberto Cruz Gomez
 * @date:   September 2015
 * @brief:  This file implements the required hardware configuration to get the serial port up and running
 */

#include "serialPort.h"

#define DELAY_105uS asm volatile ("REPEAT, #4201"); Nop(); // 105 uS delay


/** 
* circular buffer to enqueue data as it comes in 
* @type CircularBuffer  
*/
struct CircBuffer telBufferIn_t;
CBRef telBuffer;

void serialPort1(void){

    telBuffer = (struct CircBuffer*) &telBufferIn_t;
    newCircBuffer(telBuffer);
    
    // Configure and open the port;
    // U1MODE Register
    // ==============
    U1MODEbits.UARTEN = 0; // Disable the port
    U1MODEbits.USIDL = 0; // Stop on idle
    U1MODEbits.IREN = 0; // No IR decoder
    U1MODEbits.RTSMD = 0; // Ready to send mode (irrelevant)
    U1MODEbits.UEN = 0; // Only RX and TX
    U1MODEbits.WAKE = 1; // Enable at startup
    U1MODEbits.LPBACK = 0; // Disable loopback
    U1MODEbits.ABAUD = 0; // Disable autobaud
    U1MODEbits.URXINV = 0; // Normal+ operation (high is idle)
    U1MODEbits.PDSEL = 0; // No parity 8 bit
    U1MODEbits.STSEL = 0; // 1 stop bit
    U1MODEbits.BRGH = 0; // Low speed mode

    // U1STA Register
    // ==============
    U1STAbits.UTXISEL0 = 0; // generate interrupt on every char
    U1STAbits.UTXISEL1 = 0; // for the DMA
    U1STAbits.URXISEL = 0; // RX interrupt when a char is in
    U1STAbits.OERR = 0; // clear overun error

    // U1BRG Register
    // ==============
    U1BRG = COMM_BRG; // Set the baud rate for 115,200

    // Initialize the Interrupt
    // ========================
    IPC2bits.U1RXIP = 6; // Interrupt priority 7
    IFS0bits.U1RXIF = 0; // Clear the interrupt flag
    IEC0bits.U1RXIE = 1; // Enable interrupts

    // Enable the port;
    U1MODEbits.UARTEN = 1; // Enable the port
    U1STAbits.UTXEN = 1; // Enable TX

    IEC4bits.U1EIE = 1;//Enable the error interrupt
    DELAY_105uS  
}

void serialPort2(void){

    telBuffer = (struct CircBuffer*) &telBufferIn_t;
    newCircBuffer(telBuffer);
    
    // Configure and open the port;
    // U1MODE Register
    // ==============
    U2MODEbits.UARTEN = 0; // Disable the port
    U2MODEbits.USIDL = 0; // Stop on idle
    U2MODEbits.IREN = 0; // No IR decoder
    U2MODEbits.RTSMD = 0; // Ready to send mode (irrelevant)
    U2MODEbits.UEN = 0; // Only RX and TX
    U2MODEbits.WAKE = 1; // Enable at startup
    U2MODEbits.LPBACK = 0; // Disable loopback
    U2MODEbits.ABAUD = 0; // Disable autobaud
    U2MODEbits.URXINV = 0; // Normal+ operation (high is idle)
    U2MODEbits.PDSEL = 0; // No parity 8 bit
    U2MODEbits.STSEL = 0; // 1 stop bit
    U2MODEbits.BRGH = 0; // Low speed mode

    // U1STA Register
    // ==============
    U2STAbits.UTXISEL0 = 0; // generate interrupt on every char
    U2STAbits.UTXISEL1 = 0; // for the DMA
    U2STAbits.URXISEL = 0; // RX interrupt when a char is in
    U2STAbits.OERR = 0; // clear overun error

    // U1BRG Register
    // ==============
    U2BRG = COMM_BRG; // Set the baud rate for 115,200

    // Initialize the Interrupt
    // ========================
    IPC7bits.U2RXIP = 6; // Interrupt priority 7
    IFS1bits.U2RXIF = 0; // Clear the interrupt flag
    IEC1bits.U2RXIE = 1; // Enable interrupts

    // Enable the port;
    U2MODEbits.UARTEN = 1; // Enable the port
    U2STAbits.UTXEN = 1; // Enable TX

    IEC4bits.U2EIE = 1;//Enable the error interrupt
    DELAY_105uS  
}

void ppsInit(void){
    // Unlock Registers
    #ifndef UNIT_TEST
    __builtin_write_OSCCONL(OSCCON & ~(1<<6));
    #endif
    
    AD1PCFGL= 0xFFFF;   // Digital pin configuration
    RPINR18bits.U1RXR=14;   // U1RX PIN 14
    RPINR19bits.U2RXR=24;   // U2RX PIN 24
    RPOR6bits.RP13R = 3; // U1TX = RP13 PIN 11
    RPOR8bits.RP16R = 5; // U2TX = RP16   PIN 25

    TRISBbits.TRISB13 = 0;  // U1TX OUTPUT
    TRISCbits.TRISC0 = 0;   // U2TX OUTPUT
    TRISBbits.TRISB14 = 1;  // U1TX OUTPUT
    TRISBbits.TRISb3 = 1;   // U2TX OUTPUT

    // Lock registers
    #ifndef UNIT_TEST
    __builtin_write_OSCCONL(OSCCON | ~(1<<6));
    #endif
}


void serialPortHWInit(void){
    ppsInit();
    serialPort1();
    serialPort2();
}


/////////////////////////////////
// Interrupt Handling Routines //
/////////////////////////////////

#ifndef UNIT_TEST


void __attribute__((__interrupt__, no_auto_psv)) _U1RXInterrupt(void) {

    // Read the buffer while it has data
    // and add it to the circular buffer
    while (U1STAbits.URXDA == 1) {
        writeBack(telBuffer, U1RXREG);
    }

    // If there was an overun error clear it and continue
    if (U1STAbits.OERR == 1) {
        U1STAbits.OERR = 0;
    }

    // clear the interrupt
    IFS0bits.U1RXIF = 0;

}

void __attribute__((interrupt, no_auto_psv)) _U1ErrInterrupt(void) {

    // If there was an overun error clear it and continue
    if (U1STAbits.OERR == 1) {
        U1STAbits.OERR = 0;
    }

    // If there was an overun error clear it and continue
    if (IFS4bits.U1EIF == 1) {
        IFS4bits.U1EIF = 0; // Clear the UART1 Error Interrupt Flag
    }
}

void __attribute__((interrupt, no_auto_psv)) _U2ErrInterrupt(void) {

    // If there was an overun error clear it and continue
    if (U2STAbits.OERR == 1) {
        U2STAbits.OERR = 0;
    }

    // If there was an overun error clear it and continue
    if (IFS4bits.U2EIF == 1) {
        IFS4bits.U2EIF = 0; // Clear the UART1 Error Interrupt Flag
    }
}

#endif
