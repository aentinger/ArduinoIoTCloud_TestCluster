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
const char THING_ID[] = "2cfad7de-ae22-47c8-b0c4-a95db6b5572c"; /* CL-WIFI-1010-PROD */
#elif defined(ARDUINO_SAMD_MKR1000)
const char THING_ID[] = "71eb0f3a-2212-4b67-86d4-07d957e9f3cb"; /* CL-1000-PROD */
#elif defined(ARDUINO_SAMD_MKRGSM1400)
const char THING_ID[] = "a51e12e4-ee51-4b9e-907b-47b70fc80726"; /* CL-GSM-1400-PROD */
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
  ArduinoCloud.setThingId(THING_ID);
  ArduinoCloud.addProperty(led, READWRITE, ON_CHANGE, onLedChange);
  ArduinoCloud.addProperty(seconds, READWRITE, ON_CHANGE, onSecondsChange);
}

#if defined(ARDUINO_SAMD_MKRWIFI1010) || defined(ARDUINO_SAMD_MKR1000)
WiFiConnectionHandler ArduinoIoTPreferredConnection(SECRET_SSID, SECRET_PASS);
#elif defined(ARDUINO_SAMD_MKRGSM1400)
GSMConnectionHandler ArduinoIoTPreferredConnection(SECRET_PIN, SECRET_APN, SECRET_USERNAME, SECRET_PASSWORD);
#endif

#endif /* THING_PROPERTIES_H_ */
