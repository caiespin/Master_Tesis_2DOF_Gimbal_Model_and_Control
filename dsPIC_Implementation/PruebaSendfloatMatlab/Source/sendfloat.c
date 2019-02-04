#include <xc.h>
#include <stdint.h>  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void WriteUART(unsigned int data)
{
    while (U2STAbits.TRMT==0);
    if(U2MODEbits.PDSEL == 3)
        U2TXREG = data;
    else
        U2TXREG = data & 0xFF;
}


void Send_float(double flt)
{
    int i;
    unsigned char str[10];
    sprintf(str, "%f", flt);
    for(i=0;i<10;i++)
    {    
        WriteUART(str[i]);
    } 
    WriteUART(10);
    WriteUART(13);
}


