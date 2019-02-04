/**
 * @file vectorNav.h
 * @author Rafael Alberto Cruz Gomez
 * @date Sep, 2015
 *
 * This file implements the vector nav protocol 
 * 
 */
#ifndef VECTOR_NAV_
#define VECTOR_NAV_


#ifdef __cplusplus
       extern "C"{
#endif
       	
#include "serialPort.h"
#include "circBuffer.h"

#include <stdlib.h>
#include <string.h>

#define VECNAVHEADER 0x24
#define VECNAVHCR	 0x2A

//! Enumeration of states for the receiving state machine
typedef enum
{
	HEADER=0,
	CR=1
}
VNState;

//! This function decode the vector nav and shows the data for the simulink model
void vectorNavParse(float* acc);

#ifdef __cplusplus
       }
#endif
       
#endif /* VECTOR_NAV_ */
