# SewIY Education Kit
__Resources Needed__<br />
Download Arduino Software [Link](https://www.arduino.cc/en/software)<br />
Setup page for ATTINY Programmer [Link](https://learn.sparkfun.com/tutorials/tiny-avr-programmer-hookup-guide/all)<br />
Library for MPR121 Breakoutboard  [Link](https://github.com/ja450n/Adafruit_MPR121_Library)<br />
Tiny Wire Library needed for ATTINY85 to communicate with MPR121 [Link](https://github.com/adafruit/TinyWireM/archive/master.zip)<br />
NeoPixel Library for driving the RGB LEDs [Link](https://github.com/adafruit/Adafruit_NeoPixel)<br />
ATTiny board core. [Link](https://create.arduino.cc/projecthub/arjun/programming-attiny85-with-arduino-uno-afb829)


__Useful links__<br />
https://www.arduino.cc/en/guide/libraries <br />

__How to Make__<br />
First place the battery board onto the textile making sure to leave room for the main board,cap touch board, and LEDs. Then begin to sew both the power and ground traces as shown below.(NOTE: The battery board currently does not have lables on it. With the plug facing you the left pad is power and the right pad is ground) After it is sew into place begin to solder all the pads as shown.<br />

![battery board](https://github.com/SewIY-Resources/Education-Kit/blob/main/images/IMG_3732.jpg)<br />

After soldering both the battery board and the main board power pads begin to place up to five LEDs onto the right side of the micro board. The middle pad that is labeled A2 goes to IN on the LED and PWR and GND goes to its matching pad on the LED as well.(NOTE: after sewing A2 to IN on the first LED for each following LED OUT goes to IN)<br />

![LEDs](https://github.com/SewIY-Resources/Education-Kit/blob/main/images/IMG_3731.jpg)<br />

The second to last step is to assembly is to sew the micro board to the Adafruit MPR121 Breakout Board. <br />

Micro Board --> MPR121 Breakout<br />
------------------------------------- <br />
PWR -> 3Vo <br />
GND -> GND <br />
SDA -> SDS <br />
SCl -> SCL <br />

![MPR121](https://github.com/SewIY-Resources/Education-Kit/blob/main/images/IMG_3730.jpg)<br />

Lastly sew traces from 1,5,and 10 on the MPR121 Breakout Board and solder them to complete the cap touch line. <br />
Your SewIY Education Kit is now completed... now all you have left to do is to program the boards.<br />

__How to Program__<br />

After you finish sewing up your kit it is time to get some code running on it. First take your programmer and get it all plugged in. Follow the diagram below to connect it to the SewIY Micro Board:

Programmer --> SewIY Micro Board <br />
--------------------------------- <br />
Reset ->        Reset<br />
MOSI ->         MOSI<br />
MISO   ->       MISO <br />
5V       ->     PWR<br />
SCK        ->   SCK<br />
GND          -> GND<br />

After it is wired open the Arduino IDE. Under Tool -> Board select ATtiny microcontrollers. Then under Tools -> Processor select ATTiny85. Following the same step do Tools -> Clock select internal 16 MHz. Finally, to set the IDE into the correct programming mode select Tools -> Programmer select USBtinyISP. Then you are ready to upload code. Download the code above and upload it to your SewIY Educational Kit. 
