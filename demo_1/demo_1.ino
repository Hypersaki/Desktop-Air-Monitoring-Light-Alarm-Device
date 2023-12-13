#include <DHT.h>
#include <PMS.h>
#include <Adafruit_NeoPixel.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SoftwareSerial.h>

#define DHTPIN 2          // DHT22 pin
#define DHTTYPE DHT22     // DHT sensor type
#define LED_PIN 4         // LED strip pin
#define Touch_PIN 6       // Touch pin
#define NUM_LEDS 8        // number of LEDs
#define PMS_RX_PIN 8      // PMS5003 RX pin
#define PMS_TX_PIN 9      // PMS5003 TX pin

DHT dht(DHTPIN, DHTTYPE);
Adafruit_SSD1306 display(128, 64, &Wire);
Adafruit_NeoPixel pixels(NUM_LEDS, LED_PIN);
SoftwareSerial pmsSerial(PMS_RX_PIN, PMS_TX_PIN); // RX, TX

PMS pms(pmsSerial);
PMS::DATA data;

float humidity;
int pm25, pm10;

void setup() {
  Serial.begin(9600);
  pmsSerial.begin(9600);
  dht.begin();
  pixels.begin();
  pinMode(Touch_PIN, INPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();delay(2000);
  display.clearDisplay();
}

void loop() {
  int TouchState = 0;
  TouchState = digitalRead(Touch_PIN);
  //Serial.println(TouchState);//test
  humidity = dht.readHumidity();  // read humidity
  
  pm25 = data.PM_AE_UG_2_5; //give pm2.5 a value from pms5003
  pm10 = data.PM_AE_UG_10_0; //give pm10 a value from pms5003
  
  Serial.println(humidity);
  Serial.println(pm25);
  Serial.println(pm10);
  // Update LED colors based on conditions
  if ((pm25 > 35 || pm10 > 154) && (humidity < 40)) {// satisfy both conditions below
    colorWipe(pixels.Color(128, 0, 0), 50);//led red
    displayDataOnOLED();
    delay(2000);
  } else if (pm25 > 35 || pm10 > 154) {// PM2.5 greater than 35 OR PM10 greater than 154
    colorWipe(pixels.Color(128, 32, 0), 50);//led orange
    displayDataOnOLED();
    delay(2000);  
  } else if (humidity < 40) {// Humidity less than 40%
    colorWipe(pixels.Color(0, 0, 128), 50);//led blue
    displayDataOnOLED();
    delay(2000);
  } else {
    // No special conditions: Set LED pixels to off
    colorWipe(pixels.Color(0, 0, 0), 50);
    delay(2000);
  } 
  if (TouchState == HIGH) {// Touch detected
    displayDataOnOLED();
    delay(5000);  // Keep OLED display on for 5 seconds
  } else {
    display.clearDisplay();
    display.display();
  }
}

void displayDataOnOLED() {//display PM, HR data
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("PM2.5: ");
  display.println(pm25);//pms5003
  display.print("PM10: ");
  display.println(pm10);//pms5003
  display.print("HR: ");
  display.print(humidity);//dht22
  display.println("%");
  display.display();
}

void colorWipe(uint32_t color, int wait) {//light the led strip
  pixels.clear();
  for (int i = 0; i < pixels.numPixels(); i++) {
    pixels.setPixelColor(i, color);
    pixels.show();
    delay(wait);
  }
}
