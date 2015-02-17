//
// Knightrider's KITT effect, should be used in combination with
// https://www.youtube.com/watch?v=UBP7xH348cI
//
// @license MIT 2015 Dennis de Greef <github.com/dennisdegreef/orderq/blob/master/LICENSE>
// 

#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN       7
#define NUMPIXEL  150

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXEL, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  knightrider(1);
}

void knightrider(uint8_t wait) {
  uint32_t color = strip.Color(255, 0, 0);
  uint8_t i;
  
  for(i = 0; i < strip.numPixels(); i++) {
    if(i == 0) {
       strip.setPixelColor(strip.numPixels() - 1, 0, 0, 0); 
    } else {
       strip.setPixelColor(i - 1, 0, 0, 0);
    }
     strip.setPixelColor(i, color);
     strip.show();
     delay(wait);
  }
  
  for(i = strip.numPixels(); i > 0; i--) {
    if(i == 0) {
       strip.setPixelColor(strip.numPixels() + 1, 0, 0, 0); 
    } else {
       strip.setPixelColor(i + 1, 0, 0, 0);
    }
     strip.setPixelColor(i, color);
     strip.show();
     delay(wait);
  }
}

