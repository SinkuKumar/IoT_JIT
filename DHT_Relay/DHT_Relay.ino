#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 13     // Digital pin connected to the DHT sensor 
#define DHTTYPE DHT11
#define RELAY 10
#define TEMPERATURE_LIMIT 33.50

DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

void setup() {
  Serial.begin(9600);
  pinMode(RELAY, OUTPUT);
  dht.begin();

  // Set delay between sensor readings based on sensor details.
  sensor_t sensor;
  delayMS = sensor.min_delay / 1000;
}

void loop() {
  // Delay between measurements.
  delay(delayMS);

  // Get temperature event and print its value.
  sensors_event_t event;

  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  }
  else {
    Serial.print(F("Temperature: "));
    Serial.print(event.temperature);
    Serial.println(F("°C"));
    if(event.temperature > TEMPERATURE_LIMIT){
      digitalWrite(RELAY, HIGH);
    }
    if(event.temperature < TEMPERATURE_LIMIT){
      digitalWrite(RELAY, LOW);
    }
    
  }
  // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println(F("Error reading humidity!"));
  }
  else {
    Serial.print(F("Humidity: "));
    Serial.print(event.relative_humidity);
    Serial.println(F("%"));
  }
}
