
#include <WiFi.h>
#include "ThingSpeak.h"
#include <DHT.h>

// DHT22 Sensor
DHT sensorDHT(15, DHT22);

// LED
const int ledPin = 23;

// WiFi
const char* WIFI_Name = "Wokwi-GUEST";
const char* WIFI_Pass = "";

// ThingSpeak
const unsigned long channelNumber = 3549623;
const char* apiKey = "L39WCBLHK8A5A74N";

WiFiClient clientObject;

void setup() {
  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);

  // Start DHT22
  sensorDHT.begin();

  // Connect to WiFi
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_Name, WIFI_Pass);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Status: Not Connected");
    delay(1000);
  }

  Serial.println("Status: Connected");

  // Start ThingSpeak
  ThingSpeak.begin(clientObject);
}

void loop() {

  // Read sensor
  float temperature = sensorDHT.readTemperature();
  float humidity = sensorDHT.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read DHT22");
    delay(2000);
    return;
  }

  Serial.print("Temperature: ");
  Serial.println(temperature);

  Serial.print("Humidity: ");
  Serial.println(humidity);

  // LED control
  if (temperature > 30) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  // Send data to ThingSpeak
  ThingSpeak.setField(1, temperature);
  ThingSpeak.setField(2, humidity);

  int stat = ThingSpeak.writeFields(channelNumber, apiKey);

  if (stat == 200) {
    Serial.println("Data Sent to ThingSpeak");
  } else {
    Serial.print("Error: ");
    Serial.println(stat);
  }

  // University ID
  Serial.println("University ID:12324682");

  // Wait 20 seconds
  delay(20000);
}

