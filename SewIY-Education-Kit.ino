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

  Modded by Patrick Wynn/Patrick-Wynn-SewIY to work kit developed by SewIY

**********************************************************/

#include <TinyWireM.h>
#include "Adafruit_MPR121.h"
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define LED_PIN PB4
#define LED_COUNT 5

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
  strip.setBrightness(30); //set brighness low so batteries last max brightness is 255
  cap.begin(0x5A);//I2C address for MRP121
  cap.writeRegister(MPR121_ECR, 0x00);
  cap.setThreshholds(0x01, 0x00);//set the sensitivity of the touch lines
  cap.writeRegister(MPR121_ECR, 0x8F);
}

void loop() {
  currtouched = cap.touched();
  if (cap.touched() & (1 << 1)) {//touch lines will be one five and ten
    strip.setPixelColor(0, strip.Color(255, 0, 255)); //led num,r,g,b
    strip.setPixelColor(1, strip.Color(255, 0, 255));
    strip.setPixelColor(2, strip.Color(255, 0, 255));
    strip.setPixelColor(3, strip.Color(255, 0, 255));
    strip.setPixelColor(3, strip.Color(255, 0, 255));
    strip.show();
  }
  if (cap.touched() & (1 << 5)) {//touch lines will be one five and ten
    strip.setPixelColor(0, strip.Color(255, 0, 255)); //led num,r,g,b
    strip.setPixelColor(1, strip.Color(255, 0, 255));
    strip.setPixelColor(2, strip.Color(255, 0, 255));
    strip.setPixelColor(3, strip.Color(255, 0, 255));
    strip.setPixelColor(3, strip.Color(255, 0, 255));
    strip.show();
  }
  if (cap.touched() & (1 << 10)) {//touch lines will be one five and ten
    strip.setPixelColor(0, strip.Color(255, 0, 255)); //led num,r,g,b
    strip.setPixelColor(1, strip.Color(255, 0, 255));
    strip.setPixelColor(2, strip.Color(255, 0, 255));
    strip.setPixelColor(3, strip.Color(255, 0, 255));
    strip.setPixelColor(3, strip.Color(255, 0, 255));
    strip.show();
  }
  if (! (cap.touched() & (1 << 1)) ) {
    strip.clear();
    strip.show();
  }
  if (! (cap.touched() & (1 << 5)) ) {
    strip.clear();
    strip.show();
  }
  if (! (cap.touched() & (1 << 10)) ) {
    strip.clear();
    strip.show();
  }
  lasttouched = currtouched;
