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
    if(data[0]==36 && data[1]==86 && data[2]==78 && data[3]==71 && data[4]==89 && data[5]==82 && data[6]==44)
    {
        wy[0]=data[18];
        wy[1]=data[19];
        wy[2]=data[20];
        wy[3]=data[21];
        wy[4]=data[22];
        wy[5]=data[23];
        wy[6]=data[24];
        wy[7]=data[25];
        wy[8]=data[26];
        wy[9]=data[27];
        for(i=0;i<10;i++)
        {
            WriteUART(wy[i]);
        } 
        WriteUART(10);
        WriteUART(13);
    }
}

void send_wTz(unsigned char data[])
{
    unsigned char wz[17];
    int i=0;
    if(data[0]==36 && data[1]==86 && data[2]==78 && data[3]==71 && data[4]==89 && data[5]==82 && data[6]==44)
    {
        wz[0]=data[0];
        wz[1]=data[1];
        wz[2]=data[2];
        wz[3]=data[3];
        wz[4]=data[4];
        wz[5]=data[5];
        wz[6]=data[6];
        wz[7]=data[29];
        wz[8]=data[30];
        wz[9]=data[31];
        wz[10]=data[32];
        wz[11]=data[33];
        wz[12]=data[34];
        wz[13]=data[35];
        wz[14]=data[36];
        wz[15]=data[37];
        wz[16]=data[38];
        for(i=0;i<17;i++)
        {
            WriteUART(wz[i]);
        } 
        WriteUART(10);
        WriteUART(13);
    }
}

double Receive_wTy(unsigned char data[])
{
    unsigned char wy[10];
    double wTy=0.000000;
    if(data[0]==36 && data[1]==86 && data[2]==78 && data[3]==71 && data[4]==89 && data[5]==82 && data[6]==44)
    {
        wy[0]=data[18];
        wy[1]=data[19];
        wy[2]=data[20];
        wy[3]=data[21];
        wy[4]=data[22];
        wy[5]=data[23];
        wy[6]=data[24];
        wy[7]=data[25];
        wy[8]=data[26];
        wy[9]=data[27];
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



