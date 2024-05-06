#include "SSD1306_minimal.h"
#include <avr/pgmspace.h>
#include "FileForOLED.h"

SSD1306_Mini oled;

void setup(){
  oled.init(0x3c);
  oled.clear();
  oled.startScreen();
}

/*
In case I come back to this later and forgot how display works:

This SSD1306 is 128x64px, it draws vertically in pages of 8 (8px each page).
drawImage() takes a bitmap, either is hex or binary. b00010001 would display as:
black
black
black
white
black
black
black
white
*/

// the drawImage() function takes 4 parameters:
// the starting x coord in pixels
// the starting y coord in pages (it draws vertically in 8 pages)
// width in pixels
// height in pages

// i dont think this library has a function to clear just a certain section of the oled screen,
// so i just create an all black bitmap, and draw over the section i want to clear with that. couple different
// sized black bitmaps.

void drawNormalFace(){
  oled.drawImage(black30x8, 49, 2, 30, 1);
  oled.drawImage(normal_eyebrow, 39, 1, 10, 1);
  oled.drawImage(normal_eyebrow, 79, 1, 10, 1);
  oled.drawImage(normal_eye, 34, 2, 20, 4);
  oled.drawImage(normal_eye, 74, 2, 20, 4);
  oled.drawImage(normal_mouth, 50, 7, 28,  1);
}
void drawMadFace(){
  oled.drawImage(black30x8, 50, 7, 30, 1);
  oled.drawImage(mad_eyebrows, 49, 2, 29, 1);
  oled.drawImage(mad_eyes2, 34, 3, 60, 3);
  oled.drawImage(mad_mouth, 51, 7, 23, 1);
}

void drawTransitionFace1(){
  oled.drawImage(black10x8, 39, 1, 10, 1);
  oled.drawImage(black10x8, 79, 1, 10, 1);
  oled.drawImage(black70x8, 30, 2, 70, 1);
  oled.drawImage(neutral_eyebrow, 39, 2, 10, 1);
  oled.drawImage(neutral_eyebrow, 79, 2, 10, 1);
  oled.drawImage(neutral_eye, 34, 3, 20, 3);
  oled.drawImage(neutral_eye, 74, 3, 20, 3);
  oled.drawImage(mouth_transition2, 50, 7, 29, 1);
}

void drawTransitionFace2(){
  oled.drawImage(neutral_eyebrow, 39, 2, 10, 1);
  oled.drawImage(neutral_eyebrow, 79, 2, 10, 1);
  oled.drawImage(neutral_eye, 34, 3, 20, 3);
  oled.drawImage(neutral_eye, 74, 3, 20, 3);
  oled.drawImage(transition_mouth4, 50, 7, 29, 1);
}

void drawTransitionFace3(){
  oled.drawImage(black30x8, 49, 2, 30, 1);
  oled.drawImage(neutral_eyebrow, 39, 2, 10, 1);
  oled.drawImage(neutral_eyebrow, 79, 2, 10, 1);
  oled.drawImage(neutral_eye, 34, 3, 20, 3);
  oled.drawImage(neutral_eye, 74, 3, 20, 3);
  oled.drawImage(transition_mouth3, 50, 7, 28, 1);
}

void drawTransitionFace4(){
  oled.drawImage(black10x8, 39, 2, 10, 1);
  oled.drawImage(black10x8, 79, 2, 10, 1);
  oled.drawImage(eyebrow_transition1, 49, 2, 29, 1);
  oled.drawImage(neutral_eye, 34, 3, 20, 3);
  oled.drawImage(neutral_eye, 74, 3, 20, 3);
  oled.drawImage(black30x8, 50, 7, 30, 1);
  oled.drawImage(mouth_transition1, 50, 7, 28, 1);
}

void drawNeutralFace(){
  oled.drawImage(neutral_eyebrow, 39, 2, 10, 1);
  oled.drawImage(neutral_eyebrow, 79, 2, 10, 1);
  oled.drawImage(neutral_eye, 34, 3, 20, 3);
  oled.drawImage(neutral_eye, 74, 3, 20, 3);
  oled.drawImage(neutral_mouth, 50, 7, 29, 1);
}

void cycleAllFaces(){
    drawNormalFace();
    delay(1000);
    drawTransitionFace1();
    delay(1000);
    drawTransitionFace2();
    delay(1000);
    drawNeutralFace();
    delay(1500);
    drawTransitionFace3();
    delay(1000);
    drawTransitionFace4();
    delay(1000);
    drawMadFace();
    delay(1000);
  }

void loop() {
  cycleAllFaces();
}
