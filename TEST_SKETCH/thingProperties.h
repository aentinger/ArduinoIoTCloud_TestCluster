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

#ifdef ARDUINO_SAMD_MKRWIFI1010
const char THING_ID[] = "2cfad7de-ae22-47c8-b0c4-a95db6b5572c"; /* CL-WIFI-1010-PROD */
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

#ifdef ARDUINO_SAMD_MKRWIFI1010
WiFiConnectionHandler ArduinoIoTPreferredConnection(SECRET_SSID, SECRET_PASS);
#endif

#endif /* THING_PROPERTIES_H_ */
