# Desktop Air Monitoring Light Alarm Device
## About
This device is a prototype for detecting desktop air temperature and PM values. The LED strip can be used in different colors to warn of low humidity or high PM values.
When these values exceed or fall below a threshold, the OLED displays the current value detected by the sensors. 
If you want to view the data detected by the sensor but the humidity and PM values are safe on the desktop, you can press on the touch sensor to activate the OLED display.
## Preparations
### Coding Platform:
* **Arduino IDE**
### Part List:
#### Hardware:
##### Sensor:
* **DHT22 humidity&temperature sensor**
* **PMS5003 particle sensor**
* **Touch Sensor**
##### Actuator:
* **LED Strip**
* **0.96-inch OLED display**
##### Microcontroller:
* **Arduino Uno R3**
#### Connection & Power Supply:
* **prototype PCB**
* **jumper wire**
* **USB-A Male to USB-B Male**
* **Pin Headers**
#### Enclosure:
* **3mm laser-cut wood board**
### Equipment:
* **Soldering iron**
* **Soldering stand**
* **duct tape**
* **sponge double-sided tape**
* **wood glue**

## Processes
### Arduino IDE - Set Up Libraries
* **DHT** [Source](https://github.com/adafruit/DHT-sensor-library/blob/master/DHT.h)
* **PMS** [Source](https://github.com/fu-hsi/PMS)
* **Adafruit NeoPixel** [Source](https://github.com/adafruit/Adafruit_NeoPixel/blob/master/Adafruit_NeoPixel.h)
* **Adafruit GFX** [Source](https://github.com/adafruit/Adafruit-GFX-Library)
* **Adafruit SSD1306** [Source](https://github.com/adafruit/Adafruit_SSD1306)
* **SoftwareSerial** [Source](https://github.com/arduino/ArduinoCore-avr/blob/master/libraries/SoftwareSerial/src/SoftwareSerial.h)
### Arduino IDE - Test Hardware
These code examples for testing the hardware all run within the Arduino IDE just like the main code.
#### DHT22
[Test Code for DHT22](https://github.com/Hypersaki/Desktop-Air-Monitoring-Light-Alarm-Device/blob/main/Test%20Code/DHT22/DHT22.ino)
would help to print out the latest sensed temperature and humidity in the print monitor.
#### PMS5003
[Test Code for PMS5003](https://github.com/Hypersaki/Desktop-Air-Monitoring-Light-Alarm-Device/blob/main/Test%20Code/PMS5003/PMS5003.ino)
would help to read the PM value in the current space as sensed by the PMS5003 and determine if this sensor has read the data correctly. 
#### Touch Sensor
[Test Code for Touch Sensor](https://github.com/Hypersaki/Desktop-Air-Monitoring-Light-Alarm-Device/blob/main/Test%20Code/TouchSensor/TouchSensor.ino)
It prints out whether the status of the Touch Sensor is in the state of being touched or not.
#### LED Strip
[Test Code for LED Strip](https://github.com/Hypersaki/Desktop-Air-Monitoring-Light-Alarm-Device/blob/main/Test%20Code/LED%20Strip/LEDStrip.ino)
After the code is run, the LED Strip will light up red one by one.
#### 0.96-inch OLED display
[Test Code for 0.96-inch OLED display](https://github.com/Hypersaki/Desktop-Air-Monitoring-Light-Alarm-Device/blob/main/Test%20Code/OLED%20display/OLEDdisplayV1.ino)
By using the library of U8g2, it will light up the OLED display. But it is not U8g2 that is used in the main program. This program can only be used to test if the OLED display is working properly.
### Connect the Circuit
Connect the circuit following the breadboard-based circuit diagram:
![circuit diagram](https://github.com/Hypersaki/Desktop-Air-Monitoring-Light-Alarm-Device/blob/main/Image/DesktopAirMonitoring%26LightAlarmDeviceCircuits.jpg "circuit_diagram.jpg")
### Demo Code
After connecting the circuit, upload the demo code [Source](https://github.com/Hypersaki/Desktop-Air-Monitoring-Light-Alarm-Device/tree/main/demo_1) to the Arduino Uno R3 board. Wair for a mininute for warming up the PMS5003 particle sensor. Then the device should be working well.
### Fix hardware into the Enclosure
####
####
####

## Prototype Showcase
### Interior Details
abc
### Overall Showcase
abc
