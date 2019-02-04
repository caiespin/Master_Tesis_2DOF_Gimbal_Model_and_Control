#include <xc.h>
#include <stdint.h>  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void WriteUART(unsigned char data)
{
    while (U2STAbits.TRMT==0);
    if(U2MODEbits.PDSEL == 3)
        U2TXREG = data;
    else
        U2TXREG = data & 0xFF;
}

void send_wTy(unsigned char data[])
{
    unsigned char wy[10];
    unsigned char wz[10]={43,48,46,48,48,48,48,48,48,48};
    int i=0;
    if(data[0]==36 && data[1]==86 && data[2]==78 && data[3]==89 && data[4]==77 && data[5]==82 && data[6]==44)
    {
        wy[0]=data[85];
        wy[1]=data[86];
        wy[2]=data[87];
        wy[3]=data[88];
        wy[4]=data[89];
        wy[5]=data[90];
        wy[6]=data[91];
        wy[7]=data[92];
        wy[8]=data[93];
        wy[9]=data[94];
        for(i=0;i<10;i++)
        {
            WriteUART(wy[i]);
        }  
        WriteUART(13);
    }
    else
    {
        wy[0]=43;
        wy[1]=48;
        wy[2]=46;
        wy[3]=48;
        wy[4]=48;
        wy[5]=48;
        wy[6]=48;
        wy[7]=48;
        wy[8]=48;
        wy[9]=48;
    }
}

double Receive_wTy(unsigned char data[])
{
    unsigned char wy[10];
    double wTy;
    if(data[0]==36 && data[1]==86 && data[2]==78 && data[3]==89 && data[4]==77 && data[5]==82 && data[6]==44)
    {
        wy[0]=data[85];
        wy[1]=data[86];
        wy[2]=data[87];
        wy[3]=data[88];
        wy[4]=data[89];
        wy[5]=data[90];
        wy[6]=data[91];
        wy[7]=data[92];
        wy[8]=data[93];
        wy[9]=data[94];
        wTy = atof(wy);
        return wTy;
    }
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

double atofloat(uint8_t *buf)
{
    return atof(*buf);
}



