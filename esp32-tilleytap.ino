#include <OneWire.h>
#include <DallasTemperature.h>

const int TEMPERATURE_DATA = 5;

OneWire oneWire(TEMPERATURE_DATA);
DallasTemperature ds18b20Client(&oneWire);

void setup() {
  ds18b20Client.begin();
}

void loop() {
  String temperature = getTemperature();
  Serial.print("temp: ");
  Serial.println(temperature);

  delay(60000);
}

char* getTemperature() {
  char* tempFString;
  ds18b20Client.requestTemperatures();
  float tempF = ds18b20Client.getTempFByIndex(0);
  dtostrf(tempF, 3, 1, tempFString);
  return tempFString;
}


