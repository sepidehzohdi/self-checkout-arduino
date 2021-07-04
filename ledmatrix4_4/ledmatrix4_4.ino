#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 16

#define DATA_PIN 3

int i;
// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
  
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed

}

void loop() { 
  // Turn the LED on, then pause
  for(i=0;i<NUM_LEDS;i++)
  {
    leds[i] = CRGB::Red;
    FastLED.show();
  }
  delay(500);
  // Now turn the LED off, then pause
  for(i=0;i<NUM_LEDS;i++)
  {
    leds[i] = CRGB::Black;
    FastLED.show();
  }
  delay(500);
}
