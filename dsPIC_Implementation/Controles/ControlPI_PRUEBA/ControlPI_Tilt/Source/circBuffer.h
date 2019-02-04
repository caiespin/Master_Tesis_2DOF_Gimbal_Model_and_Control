/**
 * @file circBuffer.h
 * @author Mariano I Lizarraga
 * @date Dec 2008
 *
 * This library implements a circular buffer to be used in the serial readers
 * for the GPS, telemetry encoders/decoders.
 * 
 * Convention Notes
 * The HEAD, as in any queue points to the next available byte to be READ
 * The TAIL, points to the next available position to be written
 * 
 */

#ifndef _CIRCBUFFER_H_
#define _CIRCBUFFER_H_

#ifdef __cplusplus
       extern "C"{
#endif

/// @brief Predefined circular buffer size
#define BSIZE			512

/// @brief Circular Buffer data structure
typedef struct CircBuffer{
	unsigned char buffer[BSIZE];
	int head;
	int tail;
	unsigned int size;
	unsigned char overflowCount;
}CircBuffer;


//@brief  Exported Type used to generically address a CB pointer
typedef struct CircBuffer* CBRef;

// @biref this Function returns a pointer to a new Circular Buffer
void newCircBuffer (CBRef cB);

/// @brief this function frees the Circular Buffer CB Ref
void freeCircBuffer (CBRef* cB);

/// @brief returns the amount of unread bytes in the circular buffer
unsigned int getLength (CBRef cB);

/// @brief returns the actual index of the head
int readHead (CBRef cB);

/// @brief returns the actual index of the tail
int readTail (CBRef cB);

/**
 * @brief returns the byte (actual value) that the head points to. this
 * does not mark the byte as read, so succesive calls to peak will
 * always return the same value
 */
unsigned char peak(CBRef cB);

/// @brief returns the front of the circular buffer and marks the byte as read
unsigned char readFront (CBRef cB);

/// @brief writes one byte at the end of the circular buffer, returns 1 if overflow occured
unsigned char writeBack (CBRef cB, unsigned char data);

/// @brief empties the circular buffer. It does not change the size. use with caution!!
void makeEmpty (CBRef cB);

/// @brief returns the amount of times the CB has overflown;
unsigned char getOverflow(CBRef cB);


#ifdef __cplusplus
       }
#endif

#endif /* _CIRCBUFFER_H_ */

