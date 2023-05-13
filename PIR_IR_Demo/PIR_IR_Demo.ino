/*
 * ESP8266 code for connecting IR or PIR sensor, It displays
 * the status on the serial monitor.
 * Connection: 
 * OUT: Connect the OUT pin of IR or PIR sensor on the 
 * pin you've mentioned in the MACRO
 * VCC: VIN or 3v3 pin of ESP8266
 * GND: GND pin of ESP8266
 * Author: Sinku Kumar
 * Date: May 13, 2023
 * Note: PIR sensor has sentivity and rest time, it takes some time(~30 secs) for resting.
 * Sensitivity and rest time can be adjusted with potentimeter present on the sensor.
 */


#define SENSOR 10 // Sensor can be IR or PIR

void setup() {
  // put your setup code here, to run once:
  pinMode(SENSOR, INPUT);
  Serial.begin(115200);
  delay(2000); // Just to make microcontroller stable
  Serial.println("PIR/IR Sensor demo")
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(SENSOR)){
    Serial.println("Presense Detected");
  }

}
