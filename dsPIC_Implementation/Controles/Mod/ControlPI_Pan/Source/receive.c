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

void send_wTz(unsigned char data[])
{
    unsigned char wz[10];
    int i=0;
    if(data[0]==36 && data[1]==86 && data[2]==78 && data[3]==89 && data[4]==77 && data[5]==82 && data[6]==44)
    {
        wz[0]=data[7];
        wz[1]=data[8];
        wz[2]=data[9];
        wz[3]=data[10];
        wz[4]=data[11];
        wz[5]=data[12];
        wz[6]=data[13];
        wz[7]=data[14];
        wz[8]=data[15];
        wz[9]=data[16];
        for(i=0;i<10;i++)
        {
            WriteUART(wz[i]);
        } 
        WriteUART(10);
        WriteUART(13);
    }
}

double Receive_wTz(unsigned char data[])
{

    unsigned char wz[10];
    double wTz=0.000000;
    if(data[0]==36 && data[1]==86 && data[2]==78 && data[3]==89 && data[4]==77 && data[5]==82 && data[6]==44)
    {
        wz[0]=data[7];
        wz[1]=data[8];
        wz[2]=data[9];
        wz[3]=data[10];
        wz[4]=data[11];
        wz[5]=data[12];
        wz[6]=data[13];
        wz[7]=data[14];
        wz[8]=data[15];
        wz[9]=data[16];
        wTz = atof(wz);
    }
    else 
    {
        wTz=wTz;
    }
    return wTz;
}

unsigned char Receive_wTz2(unsigned char data[])
{

    unsigned char wz[10];
   
    if(data[0]==36 && data[1]==86 && data[2]==78 && data[3]==89 && data[4]==77 && data[5]==82 && data[6]==44)
    {
        wz[0]=data[7];
        wz[1]=data[8];
        wz[2]=data[9];
        wz[3]=data[10];
        wz[4]=data[11];
        wz[5]=data[12];
        wz[6]=data[13];
        wz[7]=data[14];
        wz[8]=data[15];
        wz[9]=data[16];   
    }
    else 
    {
        wz[0]='+';
        wz[1]='0';
        wz[2]='2';
        wz[3]='.';
        wz[4]='8';
        wz[5]='9';
        wz[6]='2';
        wz[7]='3';
        wz[8]='4';
        wz[9]='1';
    }
    return wz;
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

double atofloat(unsigned char data[])
{
    double res;
    res=atof(data);
    return res;
}



