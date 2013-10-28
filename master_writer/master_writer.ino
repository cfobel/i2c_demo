// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI slave device
// Refer to the "Wire Slave Receiver" example for use with this

// Created 29 March 2006

// This example code is in the public domain.
#include <Wire.h>
#include "config.h"

void setup() {
    // join i2c bus (address optional for master)
    Wire.begin(MASTER_ADDRESS);
    TWBR = 12;
}

byte x = 0;

void loop() {
    // transmit to slave device
    Wire.beginTransmission(SLAVE_ADDRESS);
    // sends five bytes
    Wire.write("x is ");
    // sends one byte
    Wire.write(x);
    // stop transmitting
    Wire.endTransmission();
    x++;
    delay(500);
}
