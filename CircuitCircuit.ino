/*
 * Circuit Circuit - Makey Makey simulator for Adafruit Circuit Playground
 * Version 1.0 by Kris Swanson, 9/2016
 * Thanks to Tony DiCola and Adafruit for megademo code which this is based on.
 */


#include <Adafruit_CircuitPlayground.h>
#include "Adafruit_SleepyDog.h"
#include <Keyboard.h>
#include <Mouse.h>

#define CAP_THRESHOLD    300  // Threshold for a capacitive touch (higher = less sensitive).
#define CAP_SAMPLES      20   // Number of samples to take for a capacitive touch read.
#define TONE_DURATION_MS 100  // Duration in milliseconds to play a tone when touched.

#define UP_KEY 10  // Set pin for Up Arrow Key
#define DOWN_KEY 9  // Set pin for Down Arrow Key
#define LEFT_KEY 6  // Set pin for Left Arrow Key
#define RIGHT_KEY 12  // Set pin for Right Arrow Key
#define SPACE_KEY 1  // Set pin for Space Bar
#define SHIFT_KEY 0  // Set pin for Command Key
#define CTRL_KEY 2  // Set pin for ALT Key
#define MOUSE_CLICK 3 // Set pin for Left Mouse Click

void setup() {

  // Initialize Circuit Playground library.
  CircuitPlayground.begin();
  // Initialize Arduino mouse library.
  Keyboard.begin();
  Mouse.begin();

}

void loop() {


  // Check if slide switch is on the left (false) and go to sleep.
  while (!CircuitPlayground.slideSwitch()) {
    // Turn off the pixels, then go into deep sleep for a second.
    CircuitPlayground.clearPixels();
    Watchdog.sleep(1000);
  }

 
   //// Clear all the neopixels.

   
    for (int i=0; i<10; ++i) {
      CircuitPlayground.strip.setPixelColor(i, 0);
    }
    
    // Check if any of the cap touch inputs are pressed and turn on those pixels.
    // Also play a tone if in tone playback mode.
    
    if (CircuitPlayground.readCap(UP_KEY, CAP_SAMPLES) >= CAP_THRESHOLD) {
      CircuitPlayground.strip.setPixelColor(3, CircuitPlayground.colorWheel(0));
      Keyboard.press(0xda);
    }
    else {
      Keyboard.release(0xda);
    }
    

    if (CircuitPlayground.readCap(DOWN_KEY, CAP_SAMPLES) >= CAP_THRESHOLD) {
      CircuitPlayground.strip.setPixelColor(4, CircuitPlayground.colorWheel(25));
      Keyboard.press(0xd9);
    }
    else {
      Keyboard.release(0xd9);
    }

  if (CircuitPlayground.readCap(RIGHT_KEY, CAP_SAMPLES) >= CAP_THRESHOLD) {
      CircuitPlayground.strip.setPixelColor(1, CircuitPlayground.colorWheel(50));
      Keyboard.press(0xd7);
    }
    else {
      Keyboard.release(0xd7);
    }

  if (CircuitPlayground.readCap(LEFT_KEY, CAP_SAMPLES) >= CAP_THRESHOLD) {
      CircuitPlayground.strip.setPixelColor(0, CircuitPlayground.colorWheel(0));
      Keyboard.press(0xd8);
    }
    else {
      Keyboard.release(0xd8);
    }

  if (CircuitPlayground.readCap(SPACE_KEY, CAP_SAMPLES) >= CAP_THRESHOLD) {
      CircuitPlayground.strip.setPixelColor(9, CircuitPlayground.colorWheel(0));
      Keyboard.press(' ');
    }
    else {
      Keyboard.release(' ');
    }

  if (CircuitPlayground.readCap(SHIFT_KEY, CAP_SAMPLES) >= CAP_THRESHOLD) {
      CircuitPlayground.strip.setPixelColor(8, CircuitPlayground.colorWheel(0));
      Keyboard.press(0x81);
    }
    else {
      Keyboard.release(0x81);
    }  

  if (CircuitPlayground.readCap(CTRL_KEY, CAP_SAMPLES) >= CAP_THRESHOLD) {
      CircuitPlayground.strip.setPixelColor(6, CircuitPlayground.colorWheel(0));
      Keyboard.press(0x80);
    }
    else {
      Keyboard.release(0x80);
    }  

  if (CircuitPlayground.readCap(MOUSE_CLICK, CAP_SAMPLES) >= CAP_THRESHOLD) {
      CircuitPlayground.strip.setPixelColor(5, CircuitPlayground.colorWheel(0));
      Mouse.click();
    }
    else {
      Mouse.release();
    }  


  // Light up the pixels.
    CircuitPlayground.strip.show();
  }   
