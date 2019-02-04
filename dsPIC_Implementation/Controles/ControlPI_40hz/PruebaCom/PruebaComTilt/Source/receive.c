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
    int i=0;
    if(data[0]==36 && data[1]==86 && data[2]==78 && data[3]==89 && data[4]==77 && data[5]==82 && data[6]==44)
    {
        wy[0]=data[96];
        wy[1]=data[97];
        wy[2]=data[98];
        wy[3]=data[99];
        wy[4]=data[100];
        wy[5]=data[101];
        wy[6]=data[102];
        wy[7]=data[103];
        wy[8]=data[104];
        wy[9]=data[105];
        for(i=0;i<10;i++)
        {
            WriteUART(wy[i]);
        } 
        WriteUART(10);
        WriteUART(13);
    }
}

double Receive_wTy(unsigned char data[])
{
    unsigned char wy[10];
    double wTy=0.000000;
    if(data[0]==36 && data[1]==86 && data[2]==78 && data[3]==89 && data[4]==77 && data[5]==82 && data[6]==44)
    {
        wy[0]=data[96];
        wy[1]=data[97];
        wy[2]=data[98];
        wy[3]=data[99];
        wy[4]=data[100];
        wy[5]=data[101];
        wy[6]=data[102];
        wy[7]=data[103];
        wy[8]=data[104];
        wy[9]=data[105];
        wTy = atof(wy);
    }
    else 
    {
        wTy=wTy;
    }
    return wTy;
}


void Send_float(double flt)
{
    int i,j,k=8;
    j=abs(flt);
    if(flt<0 && j>=10){k=10;}
    if(flt<0 && j<10){k=9;} 
    unsigned char str[10];
    sprintf(str, "%f", flt);
    for(i=0;i<k;i++)
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



