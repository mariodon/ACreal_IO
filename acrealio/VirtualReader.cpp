#include "Arduino.h"
#include "VirtualReader.h"

VirtualReader::VirtualReader()
{
    card = 0;
    readcmd = false;
    pinset = false;
}

void VirtualReader::setPins(int sensor, HardwareSerial* serialid)
{
    buttonpin = sensor;
    // Initialize button pin for inserting card
    pinMode(buttonpin, INPUT);
    digitalWrite(buttonpin, HIGH);

    pinset=true;
}

void VirtualReader::update()
{
    if (!pinset)
        return;
    if (!readcmd)
        return;

    // Button is not pressed
    if (digitalRead(buttonpin)) {
      card = 0;
    }
    // Button is pressed down
    else {
      card = 1;
    }

    readcmd = false;
}

byte VirtualReader::isCardPresent()
{
    return card;
}

void VirtualReader::read()
{
    readcmd = true;
}

void VirtualReader::getUID(byte* uida)
{
    // Set Virtual card UID
    memcpy(uida, (const byte [8]){0xE0, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 8);
}
