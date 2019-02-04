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

void send_wTz(unsigned char data[] )
{
    unsigned char wz[17];
    int i=0;
    if(data[0]==36 && data[1]==86 && data[2]==78 && data[3]==89 && data[4]==77 && data[5]==82 && data[6]==44)
    {
        wz[0]=data[0];
        wz[1]=data[1];
        wz[2]=data[2];
        wz[3]=data[3];
        wz[4]=data[4];
        wz[5]=data[5];
        wz[6]=data[6];
        wz[7]=data[107];
        wz[8]=data[108];
        wz[9]=data[109];
        wz[10]=data[110];
        wz[11]=data[111];
        wz[12]=data[112];
        wz[13]=data[113];
        wz[14]=data[114];
        wz[15]=data[115];
        wz[16]=data[116];
        for(i=0;i<17;i++)
        {
            WriteUART(wz[i]);
        } 
        WriteUART(10);
        WriteUART(13);
    }
}


void send_data(unsigned char data[], double contr)
{
    unsigned char rates[39], str[10];
    int l=0;
    sprintf(str, "%f", contr);
    if(data[0]==36 && data[1]==86 && data[2]==78 && data[3]==89 && data[4]==77 && data[5]==82 && data[6]==44)
    {
        rates[0]=data[0];
        rates[1]=data[1];
        rates[2]=data[2];
        rates[3]=data[3];
        rates[4]=data[4];
        rates[5]=data[5];
        rates[6]=data[6];
        rates[7]=data[107];
        rates[8]=data[108];
        rates[9]=data[109];
        rates[10]=data[110];
        rates[11]=data[111];
        rates[12]=data[112];
        rates[13]=data[113];
        rates[14]=data[114];
        rates[15]=data[115];
        rates[16]=data[116];
        rates[17]='44';
        rates[18]=data[96];
        rates[19]=data[97];
        rates[20]=data[98];
        rates[21]=data[99];
        rates[22]=data[100];
        rates[23]=data[101];
        rates[24]=data[102];
        rates[25]=data[103];
        rates[26]=data[104];
        rates[27]=data[105];
        rates[28]='44';
        rates[29]=str[0];
        rates[30]=str[1];
        rates[31]=str[2];
        rates[32]=str[3];
        rates[33]=str[4];
        rates[34]=str[5];
        rates[35]=str[6];
        rates[36]=str[7];
        rates[37]=str[8];
        rates[38]=str[9];
        for(l=0;l<39;l++)
        {
            WriteUART(rates[l]);
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



