#include "vectorNav.h"

// VECTOR NAV checksum code

void csToAscii(unsigned char checksum, unsigned char* ascii){
    if(!ascii){
        return;
    }
    unsigned char val1 = checksum & 0xF0;
    unsigned char val2 = checksum & 0x0F;

    val1 = val1 >> 4;
    if (val1 > 9){
        ascii[0] = val1 + 55;
    }else{
        ascii[0] = val1 + 48;
    }
    if (val2 > 9){
        ascii[1] = val2 + 55;
    }else{
        ascii[1] = val2 + 48;
    }
}

void getChecksum(unsigned char* sentence, unsigned char size) {

    unsigned int i;
    unsigned short checksum = 0;
    unsigned char x[2]= {0,0};
    
    for(i=1; i<(size-2); i++){
        cksum ^= data[i];
    }
    csToAscii(cksum, x);

    if(x[0]==sentence[size-1] && x[1]==sentence[size]){
        sentence[254] = 1;
    }

    return;
}

// this function reads the serial stream as it comes in
// then assembles full messages, verifies the checksum and
// if valid sends it out to the parser
unsigned char vectorNavSeparate(unsigned char* outStream, unsigned char* tmpLen) {

    if(!outStream){
        return 0;
    }

    //! The current state of the finite-state-machine for the decoding of incoming messages
    static VNState vnState = HEADER;
    static uint8_t length = 0;

    //! Check if there is no previos data
    if(vnState==HEADER){ 
        memset(outStream,0,255);
    }

    //! variable that controls the input buffer
    unsigned char tempData = 0;

    while (*tmpLen > 0){

        switch (vnState){

            case HEADER:

                tempData = peak(telBuffer);
                while(*tmpLen > 0 && tempData != VECNAVHEADER){
                    tempData = readFront(telBuffer);
                    *tmpLen -=1;
                    // Read without removing next data in case it didnt find a start of frame
                    tempData = peak(telBuffer);
                }
                // if we got out of the while and lenght > 0, thus we found a header
                if (*tmpLen > 0){
                    // Stores the first value in the output stream
                    outStream[0] = readFront(telBuffer);
                    vnState = CR;
                    length = 1;     // where the value is stored
                    *tmpLen -=1;
                }
            break;

            case CR:
                tempData = peak(telBuffer);
                while(*tmpLen > 0 && tempData != VECNAVCR){
                    outStream[length] = readFront(telBuffer);
                    *tmpLen -=1;
                    length++;
                    // Read without removing next data in case it didnt find a end of frame
                    tempData = peak(telBuffer);
                }
                // if we got out of the while and lenght > 0, thus we found a EOF
                if (*tmpLen > 0){
                    // Stores the first value in the output stream
                    outStream[length] = readFront(telBuffer);
                    *tmpLen -=1;
                    length++;
                    outStream[length] = readFront(telBuffer);
                    *tmpLen -=1;
                    length++;
                    outStream[length] = readFront(telBuffer);
                    *tmpLen -=1;
                    length++;
                    // Check the checksum
                    getChecksum(outStream,length);
                    length = 0;   // reset the control variable.
                    vnState = HEADER;
                }
            break;
        }
    }
}

void vectorNavParse(float* acc){

    unsigned char tmpLen = getLength(telBuffer);
    static unsigned char inStream[255];
    unsigned char bufferLen = tmpLen;

    while (bufferLen > 10) {
        bufferLen = vectorNavSeparate(inStream, &tmpLen);

        // if the sentence is valid
        if (inStream[255 - 1] == 1) {
            // parse the data according to the header
            unsigned char y[11]; // for help usage
            strncpy((char*)y, (char*)inStream +19, 10); // for Y acc
            acc[0] = atoi((char*)y);

            strncpy((char*)y, (char*)inStream +31, 10); // for Z acc
            acc[1] = atof((char*)y);
        }
    }
}
