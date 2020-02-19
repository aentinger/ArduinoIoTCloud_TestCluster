/******************************************************************************
   INCLUDE
 ******************************************************************************/

#include "arduino_secrets.h"
#include "thingProperties.h"

/******************************************************************************
   SETUP/LOOP
 ******************************************************************************/

void setup()
{
  Serial.begin(9600);
  while(!Serial) { }

  pinMode(LED_BUILTIN, OUTPUT);

  initProperties();

  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  setDebugMessageLevel(DBG_INFO);
  ArduinoCloud.printDebugInfo();
}

void loop()
{
  ArduinoCloud.update();
  seconds = millis() / 1000;
}

/******************************************************************************
   FUNCTIONS
 ******************************************************************************/

void onLedChange()
{
  Serial.print("led = ");
  Serial.println(led);
  digitalWrite(LED_BUILTIN, led);
}

void onSecondsChange()
{
  Serial.print("seconds = ");
  Serial.println(seconds);
}
