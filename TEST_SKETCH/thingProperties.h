#ifndef THING_PROPERTIES_H_
#define THING_PROPERTIES_H_

/******************************************************************************
   INCLUDE
 ******************************************************************************/

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

/******************************************************************************
   GLOBAL CONSTANTS
 ******************************************************************************/

#if defined(ARDUINO_SAMD_MKRWIFI1010)
/* CL-WIFI-1010-PROD-THING */
const char THING_ID[] = "2cfad7de-ae22-47c8-b0c4-a95db6b5572c";
#elif defined(ARDUINO_SAMD_MKR1000)
/* CL-1000-PROD-THING */
const char THING_ID[] = "71eb0f3a-2212-4b67-86d4-07d957e9f3cb";
#elif defined(ARDUINO_SAMD_MKRGSM1400)
/* CL-GSM-1400-PROD-THING */
const char THING_ID[] = "a51e12e4-ee51-4b9e-907b-47b70fc80726";
#elif defined(ARDUINO_SAMD_MKRWAN1300) || defined(ARDUINO_SAMD_MKRWAN1310)
/* CL-WAN-1310-PROD-THING */
const char THING_ID[] = "2ae809a8-b0cf-44d0-b967-0328e2db8f68";
#elif defined(ARDUINO_SAMD_MKRNB1500)
/* CL-NB-1500-PROD-THING */
const char THING_ID[] = "428f7878-cb28-4891-8d58-5ab6806f88ed";
#elif defined(BOARD_ESP8266)
/* CL-ESP8266-PROD-THING */
const char THING_ID[]          = "1572045a-b9f7-499f-8554-6be03cb35ea4";
const char DEVICE_LOGIN_NAME[] = "a44a0b7e-b598-4996-b90b-cbf21a0ff873";
#endif

/******************************************************************************
   FUNCTION DECLARATION
 ******************************************************************************/

void onLedChange();
void onSecondsChange();

/******************************************************************************
   GLOBAL VARIABLES
 ******************************************************************************/

bool led;
int seconds;

/******************************************************************************
   FUNCTION DEFINITION
 ******************************************************************************/

void initProperties()
{
#if defined(BOARD_ESP8266)
  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(SECRET_DEVICE_KEY);
#endif
  ArduinoCloud.setThingId(THING_ID);
  ArduinoCloud.addProperty(led, READWRITE, ON_CHANGE, onLedChange);
  ArduinoCloud.addProperty(seconds, READWRITE, 5 * SECONDS, onSecondsChange);
}

#if defined(ARDUINO_SAMD_MKRWIFI1010) || defined(ARDUINO_SAMD_MKR1000) || defined(BOARD_ESP8266)
WiFiConnectionHandler ArduinoIoTPreferredConnection(SECRET_SSID, SECRET_PASS);
#elif defined(ARDUINO_SAMD_MKRGSM1400)
GSMConnectionHandler ArduinoIoTPreferredConnection(SECRET_PIN, SECRET_APN, SECRET_USERNAME, SECRET_PASSWORD);
#elif defined(ARDUINO_SAMD_MKRWAN1300) || defined(ARDUINO_SAMD_MKRWAN1310)
LoRaConnectionHandler ArduinoIoTPreferredConnection(SECRET_APP_EUI, SECRET_APP_KEY);
#elif defined(ARDUINO_SAMD_MKRNB1500)
NBConnectionHandler ArduinoIoTPreferredConnection("", NB_SECRET_APN, "", "");
#endif

#endif /* THING_PROPERTIES_H_ */
