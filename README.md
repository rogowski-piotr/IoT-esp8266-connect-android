# ESP8266 Connect Aplication
Module ESP8266 Wemos r1 d1 create WiFi access point witch allow [Android application](https://github.com/rogowski-piotr/IoT-android-connect-esp8266) to connect and send HTTP request. The module response data from measurements of distances. It has an ultrasonic distance sensor HC-SR04 with its help performs a series of measurements and returns the average value of them.

## Hardware Requirements
- Module D1 R2 WiFi ESP8266
- Sensor HC-SR04

## Software Requirements
- Arduino IDE
- [Arduino ESP8266 library](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi)
- [Android application](https://github.com/rogowski-piotr/IoT-android-connect-esp8266)

## Setup
Open the .ino file in Arduino IDE. Install [ESP8266 library](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi). Setup sensor like an below diagram.

![schema](https://github.com/rogowski-piotr/IoT-esp8266-connect-android/blob/master/scema.png)

- Set network access in one of the first lines of code:

```cpp
const char* ssid = " **here ";
const char* password = " **here";
```

