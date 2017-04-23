/*
 * Circuit Circuit - Makey Makey - like functions for Adafruit Circuit Playground
 * Version 1.1 by Kris Swanson, 4/2017
 * Changelog:
 *  Added lights code on contact, changed keyboard keys
 *  Added on-board button functions:
 *      -right button gives Temp F (uncomment line for Temp C)
 *      -left button gives light level (0-100)
 *      -both are formatted for easy use with Scratch Question block. Example:
 *            Pressing right button sends "t##" then carriage return. ## is temp
 *            Pressing left button sends "l###" then carrage return ### is light level
 * Thanks to Tony DiCola and Adafruit for megademo code which this is based on.
 * Usage notes:
 *                - If you will only be touching one contact at at time,
 *                you don't need to be grounded, but if you are going to be 
 *                touching more than one contact at a time you do need to 
 *                be grounded.
 
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
#define C_KEY 0  // Set pin for c Key
#define B_KEY 2  // Set pin for b Key
#define A_KEY 3 // Set pin for a key

int temp;
int light;
bool leftButtonPressed;
bool rightButtonPressed;

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

  CircuitPlayground.clearPixels();
   
 /*   for (int i=0; i<10; ++i) {
      CircuitPlayground.strip.setPixelColor(i, 0);
    }
 */   
    // Check if any of the cap touch inputs are pressed and turn on those pixels.
    
    
    if (CircuitPlayground.readCap(UP_KEY, CAP_SAMPLES) >= CAP_THRESHOLD) {
      CircuitPlayground.strip.setPixelColor(0, 0xFFFFFF);
      CircuitPlayground.strip.setPixelColor(1, 0xFFFFFF);
      CircuitPlayground.strip.setPixelColor(8, 0xFFFFFF);
      CircuitPlayground.strip.setPixelColor(9, 0xFFFFFF);
      Keyboard.press(0xda);
    }
    else {
      Keyboard.release(0xda);
    }
    

    if (CircuitPlayground.readCap(DOWN_KEY, CAP_SAMPLES) >= CAP_THRESHOLD) {
      CircuitPlayground.strip.setPixelColor(3, 0xFFFFFF);
      CircuitPlayground.strip.setPixelColor(4, 0xFFFFFF);
      CircuitPlayground.strip.setPixelColor(5, 0xFFFFFF);
      CircuitPlayground.strip.setPixelColor(6, 0xFFFFFF);
      Keyboard.press(0xd9);
    }
    else {
      Keyboard.release(0xd9);
    }

  if (CircuitPlayground.readCap(RIGHT_KEY, CAP_SAMPLES) >= CAP_THRESHOLD) {
      CircuitPlayground.strip.setPixelColor(5, 0xFFFFFF);
      CircuitPlayground.strip.setPixelColor(6, 0xFFFFFF);
      CircuitPlayground.strip.setPixelColor(7, 0xFFFFFF);
      CircuitPlayground.strip.setPixelColor(8, 0xFFFFFF);
      CircuitPlayground.strip.setPixelColor(9, 0xFFFFFF);
      Keyboard.press(0xd7);
    }
    else {
      Keyboard.release(0xd7);
    }

  if (CircuitPlayground.readCap(LEFT_KEY, CAP_SAMPLES) >= CAP_THRESHOLD) {
      CircuitPlayground.strip.setPixelColor(0, 0xFFFFFF);
      CircuitPlayground.strip.setPixelColor(1, 0xFFFFFF);
      CircuitPlayground.strip.setPixelColor(2, 0xFFFFFF);
      CircuitPlayground.strip.setPixelColor(3, 0xFFFFFF);
      CircuitPlayground.strip.setPixelColor(4, 0xFFFFFF);
      Keyboard.press(0xd8);
    }
    else {
      Keyboard.release(0xd8);
    }

  if (CircuitPlayground.readCap(SPACE_KEY, CAP_SAMPLES) >= CAP_THRESHOLD) {
      for(int i=0; i<10; ++i){
        CircuitPlayground.strip.setPixelColor(i, 0xFFFFFF);
      }
      Keyboard.press(' ');
    }
    else {
      Keyboard.release(' ');
    }

  if (CircuitPlayground.readCap(A_KEY, CAP_SAMPLES) >= CAP_THRESHOLD) {
      for(int i=0; i<10; ++i){
        CircuitPlayground.strip.setPixelColor(i, 0xFF0000);
      }
      Keyboard.press('a');
    }
    else {
      Keyboard.release('a');
    }  

  if (CircuitPlayground.readCap(B_KEY, CAP_SAMPLES) >= CAP_THRESHOLD) {
      for(int i=0; i<10; ++i){
        CircuitPlayground.strip.setPixelColor(i, 0x00FF00);
      }
      Keyboard.press('b');
    }
    else {
      Keyboard.release('b');
    }  

  if (CircuitPlayground.readCap(C_KEY, CAP_SAMPLES) >= CAP_THRESHOLD) {
      for(int i=0; i<10; ++i){
        CircuitPlayground.strip.setPixelColor(i, 0x0000FF);
      }
      Keyboard.press('c');
    }
    else {
      Keyboard.release('c');
    }  


  // Light up the pixels.
  CircuitPlayground.strip.show();

  temp = int(CircuitPlayground.temperatureF());
  // Uncomment the next line to switch to celsius
  //temp = int(CircuitPlayground.temperature());

  light = int(CircuitPlayground.lightSensor());

  leftButtonPressed = CircuitPlayground.leftButton();
  rightButtonPressed = CircuitPlayground.rightButton();

//if left button pressed, send tempature data
  if(leftButtonPressed) {
    Keyboard.print("t");
    delay(400);
    Keyboard.println(temp);
    Keyboard.write(0xB0);
  }

//if right button pressed send light data (0-1024)
  if(rightButtonPressed) {
    Keyboard.print("l");
    delay(400);
    Keyboard.println(light);
    Keyboard.write(0xB0);
  }
    
  }
