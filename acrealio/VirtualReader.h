#ifndef VirtualReader_H
#define VirtualReader_H

#include "Arduino.h"
#include "RfidModule.h"

class VirtualReader : public RfidModule
{
public:
    VirtualReader();
    void setPins(int sensor, HardwareSerial* serialid);
    void read();
    void update();
    byte isCardPresent();
    void getUID(byte* uid);

private:
    byte card;               // 0 : no card 1: virtual

    boolean pinset;  // pin init done flag
    boolean readcmd; // read request from host flag

    int buttonpin;
};

#endif
