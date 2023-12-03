#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    134
uint8_t colorIndex[NUM_LEDS];

/**
Green Blue: Rain
Red Yellow: Sunny


*/
DEFINE_GRADIENT_PALETTE(redorange_gp) {
  0,    255, 0,   0,     // Red
  128,  255, 69,  0,     // Red-Orange
  255,  255, 165, 120      // Orange
};
CRGBPalette16 redorange = redorange_gp;




DEFINE_GRADIENT_PALETTE(blueshades_gp) {
  0,    0,   0,   255,  // Deep Blue
  64,   0,   128, 255,  // Medium Blue
  128,  0,   200, 255,  // Light Blue
  192,  173, 216, 230,  // Light Sky Blue
  255,  135, 206, 250   // Light Steel Blue
};



CRGBPalette16 blueshades = blueshades_gp;

DEFINE_GRADIENT_PALETTE(purpleblue_gp) {
  255,  255, 255, 255,  // White
  46,   75,  0,   130,  // Indigo
  179,  138, 43,  226,  // Blue Violet
  255,  255, 255, 255,   // White
};



CRGBPalette16 purpleblue = purpleblue_gp;

DEFINE_GRADIENT_PALETTE(greenshades_gp) {
  0,    0,   128, 0,     // Dark Green
  64,   0,   255, 0,     // Green
  128,  50,  205, 50,    // Lime Green
  192,  144, 238, 144,   // Light Green
  255,  173, 255, 47     // Green Yellow
};

CRGBPalette16 greenshades = greenshades_gp;


CRGB leds[NUM_LEDS];


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);
  Serial.println("Welcome to DaySphere! Please select a city");
  Serial.println("1. Honolulu, HI");
  Serial.println("2. Seattle, WA");
  Serial.println("3. Los Angeles, CA");



  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(255);
  
  for (int i = 0; i < NUM_LEDS; i++) {
    colorIndex[i] = random8();
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Welcome to DaySphere! Please select a city");

    while (Serial.available() == 0) {
      
  }
  
  int menuChoice = Serial.parseInt();
  int flag = false;

    if(menuChoice == 1){
      int loop = 0;
      while(loop < 2000){
        uint8_t sinBeat = beatsin8(30, 0, 255, 0, 0);


        for (int i = 0; i < 40; i++) {
          leds[i].setRGB(255,0,0);
          if(!flag){
            delay(20);
            FastLED.show();
          }
        }

        for (int i = 40; i < 50; i++) {
          leds[i].setRGB(255,165,120);
          if(!flag){
            delay(20);
            FastLED.show();
          }
        }


        for(int j = 50; j < 55; j++){
          leds[j] = ColorFromPalette(redorange, colorIndex[j], sinBeat);
          if(!flag){
            delay(20);
            FastLED.show();
          }
        }

        for (int i = 55; i < 110; i++) {
          leds[i].setRGB(255,165,120);
          if(!flag){
            delay(20);
            FastLED.show();
          }
        }

        for (int i=110; i <NUM_LEDS; i++){
          leds[i].setRGB(255,0,0);
          if(!flag){
            delay(20);
            FastLED.show();
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


        for (int i = 0; i < 45; i++) {
          leds[i].setRGB(0,0,255);
          if(!flag){
            delay(20);
            FastLED.show();
          }
        }

        for (int i = 45; i < 59; i++) {
        leds[i].setRGB(0,0,255);

          if(!flag){
            delay(20);
            FastLED.show();
          }
        }
         for (int i = 59; i < 65; i++) {
          leds[i] = ColorFromPalette(blueshades, colorIndex[i],sinBeat);
          if(!flag){
            delay(20);
            FastLED.show();
          }
        }

           for (int i = 65; i < 100; i++) {
          leds[i].setRGB(255,0,255);

          if(!flag){
            delay(20);
            FastLED.show();
          }
        }

        for (int i = 100; i < NUM_LEDS; i++) {
        leds[i].setRGB(0,0,255);

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
      delay(10);
      flag = true;
      if(flag){
        FastLED.show();
      }
      loop++;
      }
      
  }

      if(menuChoice == 3){
        int loop  = 0;
      while(loop < 2000){
        uint8_t sinBeat = beatsin8(30, 0, 255, 0, 0);


        for (int i = 0; i < 45; i++) {
          leds[i].setRBG(0,255,0);
          if(!flag){
            delay(20);
            FastLED.show();
          }
        }

        for (int i = 45; i < 100; i++) {
        leds[i].setRGB(255,255,0);

          if(!flag){
            delay(20);
            FastLED.show();
          }
        }
         for (int i = 100; i <105; i++) {
          leds[i] = ColorFromPalette(greenshades, colorIndex[i],sinBeat);
          if(!flag){
            delay(20);
            FastLED.show();
          }
        }

           for (int i = 105; i < NUM_LEDS; i++) {
         leds[i].setRGB(0,255,0);;

          if(!flag){
            delay(20);
            FastLED.show();
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

}
