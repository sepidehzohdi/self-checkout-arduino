# serial communication Jetson nano & Arduino
As you know Jetson is a small, powerful computer for embedded application and AI IOT. In this section I want to send/recieve data to/from Arduino. When you have multiple sensors and a proccessor like raspberry pi or Jetson or other computers, It is standard that you use a micro controller to handle sensors' data and the computer just proccess these datas. So it is valuable to know how a serial communication works.
## hardware
- Arduino board
- Jetson nano and its connections
- programming cable

## software
Arduino IDE
GCC requirements for compiling(I supposed that you setup your Jetson nano)

## how does it work?

### Jetson code
First it opens the port. Then you can choose your own settings(baudrate,stopbit,...). Afterthat you can send a data or recieve a data or both of them. and finally show the result. By putting **while()** you can repeat this proccess.
### Arduino code
In **setup()** I initialize serial and PIN13 to be in output mode. So when Arduino recieves a data LED on PIN13 blinks. In **loop()** Arduino waits for Jetson to open the communication. Then first It sends **Hello** and if the recivebyte is "1" the LED blinks.
## setup
1. Upload Arduino code
2. It is important that GPIO voltages of Jetson are 3.3v while Arduino's GPIOs are 5v. So you should use either pins and level shifter or USB port. Both of them are possible solutions but pins and level shifter does not work for me! So I use a programmer cable for connecting Arduino to USB port of Jetson.
3. After connect that, open a terminal, type **dmesg -s 1024** , find and remember the Arduino port, replace the name of port in jetson code with this name.
4. Just type make and then run the code with this command "./canonicalarduinoread"
