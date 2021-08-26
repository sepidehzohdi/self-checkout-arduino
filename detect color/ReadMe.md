# TCS3200
TCS3200 is a module that detect three color(red,blue,green).For detecting these 3 colors, It uses an 8*8 photodiode array.16 of them for red,16 for blue,16 for greenand 16 without a filter. It has 10 pins: Two grands and two Vcc,S0-S3,out,LED.

- S0 & S1 are used for frequency scale. This option permits the module to be used with different microcontrollers and control sampling frequency.
1. S0:low,S1:low   -> mode:powerdown
2. S0:low,S1:high  -> mode:2%
3. S0:high,S1:low  -> mode:20%
4. S0:high,S1:high -> mode:100%

- S2 & S3 are used for selecting the filter that I mentioned before. 
1. S2:low,S3:low   -> color:red
2. S2:low,S3:high  -> color:blue
3. S2:high,S3:low  -> color:no color
4. S2:high,S3:high -> color:green

- out is our output pin. We get duration of reacieving signal from this pin. So we should read it.

- LED is related to the leds that we have on module. If we don't like to use them we can put this pin low.

## hardware
- Arduino
- TCS3200 module

## software
- Arduino IDE

## setup
1. Connect S0 to pin4, S1 to pin5, S2 to pin6, S3 to pin7, out to pin 8,Vcc to 5v and GND to GND.
2. Upload calibration file and follow its ReadMe
3. Upload detect and you can distinguish between different color now!