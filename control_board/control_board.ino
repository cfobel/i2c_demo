// Control board master
// Copyright Christian Fobel <christian at fobel dot net>
//
// Demonstrates transmitting a _broadcast_ message, i.e., a transmission sent
// to address 0.  Note that the receiving end must have the lowest bit of
// `TWAR` set to 1 to respond to _broadcast_ messages.
#include <Wire.h>
#include "config.h"
#include "I2C_Anything.h"

#define BROADCAST_ADDRESS    0x0


void setup() {
    pinMode(13, OUTPUT);
    // join i2c bus (address optional for master)
    Wire.begin(MASTER_ADDRESS);
    TWBR = 12;
}

byte x = 0;

void loop() {
    digitalWrite(13, HIGH);
    delay(50);
    digitalWrite(13, LOW);
    // Broadcast to all devices.
    Wire.beginTransmission(BROADCAST_ADDRESS);
    // sends five bytes
    I2C_writeAnything("broadcast: ");
    // sends one byte
    I2C_writeAnything(x);
    // stop transmitting
    Wire.endTransmission();
    x++;
    delay(50);
}
