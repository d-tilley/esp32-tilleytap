#include <OneWire.h>
#include <DallasTemperature.h>
#include <HX711_ADC.h>

const int TEMPERATURE_DATA_PIN = 4;
const int WEIGHT_DATA_PIN = 5;
const int WEIGHT_SCK_PIN = 18;

OneWire oneWire(TEMPERATURE_DATA_PIN);
DallasTemperature temperatureClient(&oneWire);
HX711_ADC weightClient(WEIGHT_DATA_PIN, WEIGHT_SCK_PIN);

void setup() {
  Serial.begin(115200);
  
  temperatureClient.begin();

  weightClient.begin();
  weightClient.start(10);
}

void loop() {
  // get temperature reading
  temperatureClient.requestTemperatures(); 
  float tempF = temperatureClient.getTempFByIndex(0);

  // get weight reading
  weightClient.update();
  float weight = weightClient.getData();

  //print the results
  Serial.print("Temperature: ");
  Serial.print(tempF);
  Serial.println("F");

  Serial.print("Weight: ");
  Serial.println(weight);

  delay(5000);
}
