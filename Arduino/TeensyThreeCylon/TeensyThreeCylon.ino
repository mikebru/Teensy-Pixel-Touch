#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS_One 90
#define NUM_LEDS_Two 400
#define NUM_LEDS_Three 400


// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806, define both DATA_PIN and CLOCK_PIN


#define DATA_One_PIN 8
#define DATA_Two_PIN 14
#define DATA_Three_PIN 7

// Define the array of leds
CRGB leds_One[NUM_LEDS_One];
CRGB leds_Two[NUM_LEDS_Two];
CRGB leds_Three[NUM_LEDS_Three];

void setup() { 
	Serial.begin(57600);
	Serial.println("resetting");
	LEDS.addLeds<WS2812,DATA_One_PIN,RGB>(leds_One, NUM_LEDS_One);
  LEDS.addLeds<WS2812,DATA_Two_PIN,RGB>(leds_Two,NUM_LEDS_Two);
  LEDS.addLeds<WS2812,DATA_Three_PIN,RGB>(leds_Three,NUM_LEDS_Three);
	LEDS.setBrightness(84);
}

void loop() { 
	static uint8_t hue = 0;
	Serial.print("x");
	// First slide the led in one direction
	for(int i = 0; i < NUM_LEDS_One; i++) {
		// Set the i'th led to red 
		leds_One[i] = CHSV(hue++, 255, 255);
		// Show the leds
		FastLED.show(); 
		// now that we've shown the leds, reset the i'th led to black
		// leds[i] = CRGB::Black;

		// Wait a lttle bit before we loop around and do it again
		
	}


   for(int i = 0; i < NUM_LEDS_Two; i++) {
    // Set the i'th led to red 
    leds_Two[i] = CHSV(hue++, 255, 255);
    // Show the leds
    FastLED.show(); 
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    // Wait a little bit before we loop around and do it again
  }


   for(int i = 0; i < NUM_LEDS_Three; i++) {
    // Set the i'th led to red 
    leds_Three[i] = CHSV(hue++, 255, 255);
    // Show the leds
    FastLED.show(); 
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    // Wait a little bit before we loop around and do it again
  }


}
