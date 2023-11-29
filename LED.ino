#include <FastLED.h>
 
 
#define LED_PIN     7
#define NUM_LEDS    134
uint8_t colorIndex[NUM_LEDS];

DEFINE_GRADIENT_PALETTE( greenblue_gp ) { 
  0,   0,  255, 245,
  46,  0,  21,  255,
  179, 12, 250, 0,
  255, 0,  255, 245
};
CRGB leds[NUM_LEDS];
CRGBPalette16 greenblue = greenblue_gp;

 
void setup() {
 
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
    Serial.println("Please choose a weather info to be displayed ");

    while (Serial.available() == 0) {
      
  }
  
  int menuChoice = Serial.parseInt();

  Serial.println("Menu : "+ menuChoice);
  if(menuChoice == 1){
    //First 12th hour
      int r_value_array[] = {244,244,244,0,0,0,0,160,160,160,160 ,160};
      int g_value_array[]= {232,232,232,193,193,193,193,193,193,193,193 ,193};
      int b_value_array[] = {193 ,193 ,193 ,185 ,185 ,185 ,185,185 ,185 ,185 ,185 ,185};
      int hour = 0;
      Serial.println("Displaying Temperature Information...");
     for(int i = 0; i < 60 ; i+=5){
      for(int j = 0; j < 5 ; j++){
        leds[i+j] = CRGB(r_value_array[hour],g_value_array[hour], b_value_array[hour]);
        FastLED.show();
      
      }
      delay(100);
     hour++;
      }

    //Second 12th Hour
   
    hour = 0;
     for(int i = 60; i < 134 ; i+=7){
      for(int j = 0; j < 7 ; j++){
        //leds[i+j] = CRGB(r_value_array[hour],g_value_array[hour], b_value_array[hour]);
        leds[i+j] = CRGB(r_value_array[hour],g_value_array[hour], b_value_array[hour]);
        Serial.print(r_value_array[hour]);
        FastLED.show();
      
      }
      delay(100);
     hour++;
      }

      while(Serial.available() == 0){
        // Make the LEDs fade in and out
        fadeToBlackBy(leds,20,1);
        delay(1000);

      }
      
  }
    if(menuChoice == 2){
      /**int  r_value_array_2 [] = {0,0,244,0,0,0,0,160,0,160,0 ,160};
      int  g_value_array_2 []= {0,0,232,193,193,193,193,193,193,193,0 ,255};
      int  b_value_array_2 [] = {193 ,193 ,0 ,0 ,185 ,0 ,185,0 ,185 ,185 ,185 ,255};
      int hour2 = 0;
      Serial.println("Displaying Precipitation Information...");
      for(int i = 0; i < 60 ; i+=5){
        for(int j = 0; j < 5 ; j++){
          leds[i+j] = CRGB(r_value_array_2[hour2],g_value_array_2[hour2], b_value_array_2[hour2]);
          FastLED.show();
        }
      delay(100);
      hour2++;
      }*/

      while(true){
        uint8_t sinBeat   = beatsin8(10, 0, NUM_LEDS - 1, 0, 0);
  uint8_t sinBeat2  = beatsin8(10, 0, NUM_LEDS - 1, 0, 85);
  uint8_t sinBeat3  = beatsin8(10, 0, NUM_LEDS - 1, 0, 170);

  // If you notice that your pattern is missing out certain LEDs, you
  // will need to use the higher resolution beatsin16 instead. In this
  // case remove the 3 lines above and replace them with the following:
  // uint16_t sinBeat   = beatsin16(30, 0, NUM_LEDS - 1, 0, 0);
  // uint16_t sinBeat2  = beatsin16(30, 0, NUM_LEDS - 1, 0, 21845);
  // uint16_t sinBeat3  = beatsin16(30, 0, NUM_LEDS - 1, 0, 43690);

  leds[sinBeat]   = CRGB::Green;
  leds[sinBeat2]  = CRGB::Blue;
  leds[sinBeat3]  = CRGB::Red;

  EVERY_N_MILLISECONDS(1){
    for(int i = 0; i < 4; i++) {
      blur1d(leds, NUM_LEDS, 50);
      
    }
  }
  
  //fadeToBlackBy(leds, NUM_LEDS, 10);
  //delay(100);
  FastLED.show();
      }
      
    }

    if(menuChoice == 3){
      while(true){
        //Creat a sin wave with period of 2 seconds (30bpm) to change the brightness of the strip
  uint8_t sinBeat = beatsin8(30, 100, 255, 0, 0);
  
  // Color each pixel from the palette using the index from colorIndex[]
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = ColorFromPalette(greenblue, colorIndex[i], sinBeat);
  }
  
  EVERY_N_MILLISECONDS(5){
    for (int i = 0; i < NUM_LEDS; i++) {
      colorIndex[i]++;
    }
  }
  delay(10);
  FastLED.show();
      }
    }

    
  }