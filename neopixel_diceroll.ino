#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6
int wait = 1500;
#define color strip.Color(0,100,0) 
#define off strip.Color(0,0,0)

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(9, PIN, NEO_RGB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.


void setup() {
  // put your setup code here, to run once:
strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  randomSeed(analogRead(0)+analogRead(1));
}

void loop() {
  // put your main code here, to run repeatedly:

roll();
switch(random(1,7)) {
  case 1:
  one();
  break;
  case 2:
  two();
  break;
  case 3:
  three();
  break;
  case 4:
  four();
  break;
  case 5:
  five();
  break;
  case 6:
  six();
  break;
}
delay(wait+1000);
}

void roll() {
  for (int i = 0; i<25; i++) {
  int tempwait = wait;
  wait = 75;
  one();
  two();
  three();
  four();
  five();
  six();
  wait = tempwait;
  }
}

void one() {
strip.setPixelColor(4,strip.Color(0,255,0)); //one
strip.show();
delay(wait);
diceOff();
}

void two() {
strip.setPixelColor(2, strip.Color(0,255,0)); //two
strip.setPixelColor(6, strip.Color(0,255,0));
strip.show();
delay(wait);
diceOff();
}

void three() {
strip.setPixelColor(2, strip.Color(0,255,0)); //three
strip.setPixelColor(4, strip.Color(0,255,0));
strip.setPixelColor(6, strip.Color(0,255,0));
strip.show();
delay(wait);
diceOff();
}

void four() {
strip.setPixelColor(0, color); //four
strip.setPixelColor(2, color);
strip.setPixelColor(6, color);
strip.setPixelColor(8, color);
strip.show();
delay(wait);
diceOff();
}

void five() {
strip.setPixelColor(0, color); //five
strip.setPixelColor(2, color);
strip.setPixelColor(4, color);
strip.setPixelColor(6, color);
strip.setPixelColor(8, color);
strip.show();
delay(wait);
diceOff();
}

void six() {
strip.setPixelColor(0, color); //six
strip.setPixelColor(2, color);
strip.setPixelColor(3, color);
strip.setPixelColor(5, color);
strip.setPixelColor(6, color);
strip.setPixelColor(8, color);
strip.show();
delay(wait);
diceOff();
}

void diceOff() {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, off);
    strip.show();
   
  }
}
