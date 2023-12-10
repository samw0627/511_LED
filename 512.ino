#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Adafruit_VEML7700.h"
#include "DHT.h"

#define DHTPIN 3     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11
#define SENSOR_PIN 2 //Analigue pin to photoresistor

/*#include <SPI.h>
#define BME_SCK 18
#define BME_MISO 19
#define BME_MOSI 23
#define BME_CS 5*/

//#define SEALEVELPRESSURE_HPA (1013.25)

//Adafruit_BME280 bme; // I2C
//Adafruit_BME280 bme(BME_CS); // hardware SPI
//Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK); // software SPI
//Adafruit_VEML7700 veml = Adafruit_VEML7700();
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &Wire);
DHT dht(DHTPIN, DHTTYPE);
int LEDbrightness;

unsigned long delayTime;
int value = 0;
int photocellReading;
char bright[] = "Bright";
char dark[] = "Dark";



void setup() {
  Serial.begin(9600);
  /**Set Up Temperature Sensor*/
  Serial.println(F("DHTxx test!"));
  dht.begin();  
  

  
  pinMode(6,OUTPUT);
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x64)
   // init done
  display.display();
  delay(2000);
  display.clearDisplay();
  display.display();
  display.setTextSize(1.2);
  display.setTextColor(WHITE);
  
  
}


void loop() { 
  
  display.setCursor(0,0);

  display.clearDisplay();
  
  // Wait a few seconds between measurements.
  delay(1000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    display.println(F("Failed to read from DHT sensor!"));
      display.display();

    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  //read Photoresistor value
  value = analogRead(SENSOR_PIN);
  if(value > 200){
    digitalWrite(6,HIGH);
  }
  if(value < 200){
    digitalWrite(6,LOW);

  }
 
  delay(100);
  
  int photocellReading = 1023 - value;

  display.print(F("Humidity: "));
  display.print(h);
  display.println("%");
  display.print(F("Temperature: "));
  display.print(t);
  display.println(F("*C "));
  display.print("Brightness: ");
  display.print(photocellReading);
    if (photocellReading < 10) {
    display.println(" - Dark");
  } else if (photocellReading < 200) {
    display.println(" - Dim");
  } else if (photocellReading < 500) {
    display.println(" - Light");
  } else if (photocellReading < 800) {
    display.println(" - Bright");
  } else {
    display.println(" - Very bright");
  }
  delay(100);

  //display.print(F("°F  Heat index: "));
  //display.print(hic);
  //display.print(F("°C "));
  //display.print(hif);
  //display.println(F("°F"));
    display.display();






  /**Serial.print("Temperature = "); Serial.print(bme.readTemperature()); Serial.println(" *C");
  display.print("Temperature: "); display.print(bme.readTemperature()); display.println(" *C");

  Serial.print("Pressure = "); Serial.print(bme.readPressure() / 100.0F); Serial.println(" hPa");
  display.print("Pressure: "); display.print(bme.readPressure() / 100.0F); display.println(" hPa");

  Serial.print("Humidity = "); Serial.print(bme.readHumidity()); Serial.println(" %");
  display.print("Humidity: "); display.print(bme.readHumidity()); display.println(" %");

  float luxValue = veml.readLux();

  Serial.print("Lux "); Serial.println(luxValue);
  display.print("Lux "); display.println(luxValue);
  digitalWrite(6,HIGH);
  if(luxValue < 300){
    digitalWrite(6,LOW);
  }

  Serial.println();
  display.display();

  
  
  delay(1000);
  */

}
