void InvCad(char *str, int len)
{
    int i=0, j=len-1, temp;

    while (i<j)
    {
        temp = str[i];

        str[i] = str[j];
        str[j] = temp;
        i++; j--;
    }
}

 int intToStr(int x, int d)
{
     char str[];
     int i = 0;
     while (x)
     {
        str[i++] = (x%10) + '0';
        x = x/10;
     }
    while (i < d)
        str[i++] = '0';
    InvCad(str, i);
    str[i] = '\0';
    return str;
}

void ftoa(float n, char *res, int afterpoint)
{
    int opcion,ipart,i,j,k;
    float fpart;
    if(n>0){
        opcion=1;
    }
    if(n==0){
        opcion=2;
    }
    if(n<0){
        n=n*-1;
        opcion=3;
    }
    switch(opcion){
      case 1:
         ipart = (int)n;
         fpart = n - (float)ipart;
         i = intToStr(ipart, res, 1);
         if (afterpoint != 0)
         {
             res[i] = '.';
             fpart = fpart * pow(10, afterpoint);
             intToStr((int)fpart, res + i + 1, afterpoint);
         }
      break;
      case 2:
         res[0] = '0';
         res[1] = '.';
         res[2] = '0';
         res[3] = '0';
         res[4] = '0';
         res[5] = '0';
         res[6] = '\0';
      break;
      case 3:
         ipart = (int)n;

         fpart = n - (float)ipart;
         i = intToStr(ipart, res, 1);
         if (afterpoint != 0)
         {
             res[i] = '.';
             fpart = fpart * pow(10, afterpoint);

             j=intToStr((int)fpart, res + i + 1, afterpoint);
             j=j+i+1;
         }
         for(k=j;k>0;k--)
            res[k]=res[k-1];
         res[j+1]='\0';
         res[0]='-';
      break;

}
}

void WriteUART(unsigned int data)
{
    while (U1STAbits.TRMT==0);
    if(U1MODEbits.PDSEL == 3)
        U1TXREG = data;
    else
        U1TXREG = data & 0xFF;
}

void WriteStringUART(const char * s)
{
    while(*s)
     WriteUART(*s++);
}

void WritefloatUART(float num)
{
    char res[20];
    ftoa(num, res, 4);
    WriteStringUART(res);
}


