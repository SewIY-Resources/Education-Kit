/*********************************************************
  This is a library for the MPR121 12-channel Capacitive touch sensor

  Designed specifically to work with the MPR121 Breakout in the Adafruit shop
  ----> https://www.adafruit.com/products/

  These sensors use I2C communicate, at least 2 pins are required
  to interface

  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  BSD license, all text above must be included in any redistribution

  Modded by Jayson Owens/ja450n to include TinyWire support for ATtiny Boards
  
  Use TinyWireM.h for ATtiny's, otherwise stick with Wire.h

  IMPORTANT - If using ATtiny you won't be able to use the
  hardware Serial functions, so you'll need to comment out or remove
  the Serial.x calls in the example code below

  Modded by Patrick Wynn/Patrick-Wynn to work kit developed by SewIY

**********************************************************/

#include <TinyWireM.h>
#include "Adafruit_MPR121.h"
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define LED_PIN PB4
#define LED_COUNT 6

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_MPR121 cap = Adafruit_MPR121();

uint16_t lasttouched = 0;
uint16_t currtouched = 0;

void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  strip.begin();
  strip.show();
  strip.setBrightness(30); //set brighness low so batteries last
  cap.begin(0x5A);//I2C address for MRP121
}

void loop() {
  currtouched = cap.touched();
  if (cap.touched() & (1 << 4)) { //this tells if pin 4 is touched. if you want to add more touch lines copy this section and just change the "4" to the number channel you want to use
    strip.setPixelColor(0, strip.Color(0, 255, 255)); //led_num,r,g,b
    strip.setPixelColor(1, strip.Color(0, 255, 255));
    strip.setPixelColor(2, strip.Color(0, 255, 255));
    strip.setPixelColor(3, strip.Color(0, 255, 255));

    strip.show();
  }
  if (! (cap.touched() & (1 << 4)) ) {//this tells when the touch line is no longer touched. if you wish to add more touch lines copy this fucntion and change the "4" to the pin you are adding
    strip.clear();
    strip.show();
  }
  lasttouched = currtouched;
}
