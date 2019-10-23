# Halloween Candle
Season's tealight with ATTiny85 and Adafruit Neopixel - and some special effects

## Build Setup

In order to build this little tool, some preparation steps are required.

1. Arduino Mk has to be installed on the system
1. Arduino IDE has to be installed on the system
1. Get the ATTiny core from [here](https://github.com/damellis/attiny/) with 

```git clone https://github.com/damellis/attiny/ ~/Arduino/hardware/attiny/avr```

1. Adjust the ISP type in the Makefile if it's not usbasp

## Set Clock Speed

By default, the ATTiny85 runs at 1 MHz. This code is created for 16 MHz speed.
To change the clock speed, use

```
sudo avrdude -q -p attiny85 -c usbasp-clone -b 19200 -Uefuse:w:0xFF:m
-Uhfuse:w:0xDF:m -Ulfuse:w:0xF1:m
```

## Uploading the Build Result

At the moment `make upload` is not yet working. Instead, use `avrdude`
directly.

```
sudo avrdude -q -p attiny85 -c usbasp-clone -b 19200 -U
flash:w:build-ATtinyX5-attiny85/halloween-candle.hex:i
```
