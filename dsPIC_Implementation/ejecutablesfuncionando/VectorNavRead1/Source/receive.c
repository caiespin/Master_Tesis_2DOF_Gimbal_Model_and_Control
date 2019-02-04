#include <stdint.h>  

uint8_t check(uint8_t *data)
{
    uint8_t wy[10];
    uint8_t wz[10]={72,111,108,111,95,75,67,75,67,75};
    int i;
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
        return wy;
    }
    else
        return wz;
}
