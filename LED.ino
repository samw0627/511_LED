#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    134
uint8_t colorIndex[NUM_LEDS];

/**
Green Blue: Rain
Red Yellow: Sunny


*/
DEFINE_GRADIENT_PALETTE( greenblue_gp ) { 
  0,   0,  255, 245,
  46,  0,  21,  255,
  179, 12, 250, 0,
  255, 0,  255, 245
};
CRGBPalette16 greenblue = greenblue_gp;


 DEFINE_GRADIENT_PALETTE(purpleorange_gp) {
  0,    0,   0,   125,  // Blue
  46,   75,  0,   130,  // Indigo
  179,  138, 43,  226,  // Blue Violet
  255,  128, 0,   128   // Purple
};



CRGBPalette16 purpleorange = purpleorange_gp;

DEFINE_GRADIENT_PALETTE(purpleblue_gp) {
  255,  255, 255, 255,  // White
  46,   75,  0,   130,  // Indigo
  179,  138, 43,  226,  // Blue Violet
  255,  255, 255, 255,   // White
};



CRGBPalette16 purpleblue = purpleblue_gp;

DEFINE_GRADIENT_PALETTE(yellowgreen_gp) {
  0,    255, 255, 0,   // Yellow
  128,  0,   255, 0,   // Green
  255,  255, 255, 0,    // Yellow
  //255,  255, 255, 255,   // White

};

CRGBPalette16 yellowgreen = yellowgreen_gp;


DEFINE_GRADIENT_PALETTE(yellow_gp) {
  0,    255, 255, 0,   // Yellow
};

CRGBPalette16 yellow = yellow_gp;

DEFINE_GRADIENT_PALETTE(green_gp) {
  128,  0,   255, 0,   // Green
};

CRGBPalette16 green = green_gp;

CRGB leds[NUM_LEDS];


void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
  delay(200);
  Serial.println("1. Temperature");
  Serial.println("2. Precipitation");
  Serial.println("3. Wind(Changing lights)");



  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(255);
  
  for (int i = 0; i < NUM_LEDS; i++) {
    colorIndex[i] = random8();
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Please choose a weather info to be displayed ");

    while (Serial.available() == 0) {
      
  }
  
  int menuChoice = Serial.parseInt();
  int flag = false;

    if(menuChoice == 1){
      int loop = 0;
      while(loop < 2000){
        uint8_t sinBeat = beatsin8(30, 0, 255, 0, 0);

        for (int i = 0; i < 20; i++) {
          leds[i] = ColorFromPalette(green, colorIndex[i]);
          if(!flag){
            delay(20);
            FastLED.show();
          }
        }

        for (int i = 20; i < 25; i++) {
          leds[i] = ColorFromPalette(yellowgreen, colorIndex[i]);
          if(!flag){
            delay(20);
            FastLED.show();
          }
        }

        for(int j = 25; j < 55; j++){
          leds[j] = ColorFromPalette(yellow, colorIndex[j]);
          if(!flag){
            delay(20);
            FastLED.show();
          }
        }

        for (int i = 55; i < 60; i++) {
          leds[i] = ColorFromPalette(yellow, colorIndex[i], sinBeat);
          if(!flag){
            delay(20);
            FastLED.show();
          }
        }

        for (int i = 60; i < NUM_LEDS; i++) {
          leds[i] = ColorFromPalette(green, colorIndex[i]);
          if(!flag){
            delay(20);
            FastLED.show();
          }
        }

         EVERY_N_MILLISECONDS(5){
      for (int i = 55; i < 60; i++) {
        colorIndex[i]++;
      }
    }
      delay(10);
      flag = true;
      if(flag){
        FastLED.show();
      }
      loop++;
      }
      
  }

      if(menuChoice == 2){
        int loop  = 0;
      while(loop < 2000){
        uint8_t sinBeat = beatsin8(30, 0, 255, 0, 0);


        for (int i = 0; i < 5; i++) {
          leds[i].setRGB(75,  0,   130);
          //leds[i] = ColorFromPalette(purpleblue, colorIndex[i]);


          if(!flag){
            delay(20);
            FastLED.show();
          }
        }

         for (int i = 5; i < 45; i++) {
          leds[i].setRGB(75,  0,   130);
          //leds[i] = ColorFromPalette(purpleblue, colorIndex[i]);


          if(!flag){
            delay(20);
            FastLED.show();
          }
        }

        for (int i = 45; i < 59; i++) {
          leds[i].setRGB(75,  0,   130);
        //leds[i] = ColorFromPalette(purpleblue, colorIndex[i]);

          if(!flag){
            delay(20);
            FastLED.show();
          }
        }
         for (int i = 59; i < 65; i++) {
          leds[i] = ColorFromPalette(purpleblue, colorIndex[i],sinBeat);
          if(!flag){
            delay(20);
            FastLED.show();
          }
        }

        for (int i = 65; i < NUM_LEDS; i++) {
          leds[i].setRGB(75,  0,   130);
          //leds[i] = ColorFromPalette(purpleblue, colorIndex[i]);

          if(!flag){
            delay(20);
            FastLED.show();
          }
        }

        EVERY_N_MILLISECONDS(1){
      for (int i = 59; i < 65; i++) {
        colorIndex[i]++;
      }
    }

      flag = true;
      if(flag){
        FastLED.show();
      }
      loop++;
      }
      
  }

}