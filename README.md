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

__How to Use__<br />

After you finish sewing up your kit it is time to get some code running on it. First take your programmer and get it all plugged in. Follow the diagram below to plug it into the SewIY Micro Board.....

Programmer --> SewIY Micro Board <br />
--------------------------------- <br />
Reset ->        Reset<br />
MOSI ->         MOSI<br />
MISO   ->       MISO <br />
5V       ->     PWR<br />
SCK        ->   SCK<br />
GND          -> GND<br />

After it is wired go to the Arduino IDE. Under Tool -> Board select ATtiny microcontrollers. The under Tools -> Processor select ATTiny85. Following the same step do Tools -> Clock select internal 16 MHz. Finally to set the IDE into the correct programming mode select Tools -> Programmer select USBtinyISP. Then you are ready to upload code. Download the code above and upload it to your SewIY Educational Kit. 
