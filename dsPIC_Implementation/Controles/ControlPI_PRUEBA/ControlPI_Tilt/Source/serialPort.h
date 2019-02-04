/**
 * @file:   serialPort.h
 * @author: Rafael Alberto Cruz Gomez
 * @date:   September, 2015
 * @brief:  This file implements the required hardware configuration to get the serial port up and running
 */

#ifndef SERIAL_PORT_H
#define SERIAL_PORT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "circBuffer.h"
#include "inttypes.h"
#include "p33fj128mc804.h"
    
#define COMM_BRG   21


// Extern some of the internal states to make them testable
// TODO: Remove from header file and include accessor methods
 extern CBRef telBuffer;

/**
 * @brief: This function initializes the serial by configuring the required registers and setting up the
 *         interrupts accordingly.
 */
void serialPortHWInit(void);



#ifdef __cplusplus
}
#endif

#endif  // SERIAL_PORT_H
