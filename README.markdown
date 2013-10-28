Overview
========

This project demonstrates some advanced I2C concepts, discussed [here] [1].


Timing
======

Using the default transmission rate, the I2C clock runs at 100kHz, which
translates to ~96us/byte of actual payload.  This timing takes the overhead
padding the payload into account.

By using a clock rate of 400kHz instead, the transmission speed increases to
~28us/byte.  As shown in the file `master_writer/master_writer.ino`, the
clock-rate can be set by modifying the contents of the `TWBR`-register _(search
for `TWBR` [here] [1])_.

To demonstrate the usage of 400kHz clock-rate, load the `master_writer` project
on one device and load the `slave_receiver` onto another device and connect a
serial terminal to the `slave_receiver` device.  You should see output similar to:

    x is 1
    x is 2
    x is 3
    x is 4
    x is 5
    ...
    ...
    ...
    x is 254
    x is 254
    x is 1
    x is 2
    x is 3
    ...

__NB__ See `i2c-SCL-TWBR_default.pdf` and `i2c-SCL-TWBR_12.pdf` to show that
the clock-rate does indeed change when changing `TWBR`.


Broadcast
=========

By default, a slave receiver only responds to transmissions sent to the slave's
specific address.  However, as described [here] [1], by setting the lowest bit
of the slave's `TWAR` register to 1, the slave will also respond to any
transmissions to address `0x00`, which is reserved as a special, _broadcast_
address.

To demonstrate the sending and receiving of a broadcast message, load the
`control_board` project on one device and load the `extension_module` onto
one _(or more)_ device(s) and connect a serial terminal to the
`extension_module` devices. You should see output similar to:

    broadcast: 1
    broadcast: 2
    broadcast: 3
    broadcast: 4
    broadcast: 5
    ...
    ...
    ...
    broadcast: 254
    broadcast: 254
    broadcast: 1
    broadcast: 2
    broadcast: 3
    ...

__NB__ Just to reiterate, the broadcast messages are _not_ sent to a specific
slave-device address.  Instead, the slave-devices are configured to listen to
_broadcast_ messages and the master-device sends out a _broadcast_ message by
transmitting to address `0x00`.


[1]: http://www.gammon.com.au/forum/?id=10896
