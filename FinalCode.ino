#include <FastLED.h> // Include library

// Global variables for LED STRIP
#define NUM_LEDS 60   // There are 60 LEDs on the strip
#define LED_PIN 12    // The LED strip receives programming through pin 12
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define BRIGHTNESS 50 // Brightness is between 0-255

#define NEGATIVE_COLOR CRGB::Red
#define POSITIVE_COLOR CRGB::Green
#define NO_COLOR CRGB::Black

// Global variables for force-sensitive resistor
#define FSR_PIN_A0 A0  // FSR at A0
#define FSR_PIN_A1 A1 // FSR at A1
#define THRESHOLD 100 

int sensorA0;  // Sensor readings for FSR at A0
int sensorA1;  // Sensor readings for FSR at A1

CRGB leds[NUM_LEDS];  // Declare LED array

void setup() {
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS); // Set up LED strip
    pinMode(FSR_PIN_A0, INPUT); // Set FSR pin A0 as input
    pinMode(FSR_PIN_A1, INPUT); // Set FSR pin A1 as input
    FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
    sensorA0 = analogRead(FSR_PIN_A0); // Read FSR value at A0
    sensorA1 = analogRead(FSR_PIN_A1); // Read FSR value at A1

    if (sensorA0 > THRESHOLD) { // if FSR at A0 is pressed
        fill_solid(leds, NUM_LEDS, CRGB::Red);  // Turn LEDs red
    } else if (sensorA1 > THRESHOLD) {// if FSR at A1 is pressed
        fill_solid(leds, NUM_LEDS, CRGB::Green);  // Turn LEDs green
    } else {
      fill_solid(leds, NUM_LEDS, CRGB::Black); // turn LEDS off
    }

    FastLED.show(); // Update LED strip
}