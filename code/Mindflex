#include <SoftwareSerial.h>
#include <Brain.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "bitmaps.h"

#define RX 2
#define TX 3

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET       -1
#define SCREEN_ADDRESS 0x3D

int attention = 0;
int Signal = 0;

int w = 128;
int l = 64;
int WhiteonBlack = 1;

Brain brain(Serial);
SoftwareSerial sws(RX, TX);

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup(){
  sws.begin(9600);
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SS1306 allocation failed"));
    for(;;);
  }
  display.display();
  display.clearDisplay();
}

void loop(){
  if(brain.update()){
    Signal = brain.readSignalQuality();
    attention = brain.readAttention();
    if(Signal > 200){
      Serial.println(F("Signal quality is low, re-adjust headset\n"));
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0, 22);
      display.println(F("Signal quality is low, re-adjust headset"));
      display.display();
    }
    else if((attention > 0) && (attention < 20)){
      Serial.print(F("eSense state: "));
      Serial.println(F("strongly lowered\n"));
      sws.println('1');
      display.clearDisplay();
      display.drawBitmap(1, 0, focus_meter1, w, l, WhiteonBlack);
      display.display();
    }
    else if((attention >= 20) && (attention < 40)){
      Serial.print(F("eSense state: "));
      Serial.println(F("reduced\n"));
      sws.println('2');
      display.clearDisplay();
      display.drawBitmap(1, 0, focus_meter2, w, l, WhiteonBlack);
      display.display();
    }
    else if((attention >= 40) && (attention < 60)){
      Serial.print(F("eSense state: "));
      Serial.println(F("neutral\n"));
      sws.println('3');
      display.clearDisplay();
      display.drawBitmap(1, 0, focus_meter3, w, l, WhiteonBlack);
      display.display();
    }
    else if((attention >= 60) && (attention < 80)){
      Serial.print(F("eSense state: "));
      Serial.println(F("slightly elevated\n"));
      sws.println('4');
      display.clearDisplay();
      display.drawBitmap(1, 0, focus_meter4, w, l, WhiteonBlack);
      display.display();
    }
    else if((attention >= 80) && (attention < 100)){
      Serial.print(F("eSense state: "));
      Serial.println(F("elevated\n"));
      sws.println('5');
      display.clearDisplay();
      display.drawBitmap(1, 0, focus_meter5, w, l, WhiteonBlack);
      display.display();
    }
    else{
      Serial.print(F("eSense state: "));
      Serial.println(F("unable to calculate an eSense level\n"));
      sws.println('0');
      display.clearDisplay();
      display.drawBitmap(1, 0, brain_disconnected, w, l, WhiteonBlack);
      display.display();
    }
  }
}
