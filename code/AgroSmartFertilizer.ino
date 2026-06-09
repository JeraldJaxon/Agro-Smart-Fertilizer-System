#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#include <DHTesp.h>

DHTesp dht;

// Blynk Credentials
char auth[] = "YOUR_BLYNK_TOKEN";
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

// Pin Definitions
#define DHTPIN 0
#define MOISTUREPIN A0
#define RELAYPIN 16
#define SOLENOID1 5
#define SOLENOID2 12
#define SOLENOID3 15

// Variables
float temperature = 0;
float humidity = 0;
float moistureValue = 0;
float moisture_percentage = 0;

int relayState = LOW;
int solenoid1State = LOW;
int solenoid2State = LOW;
int solenoid3State = LOW;

BlynkTimer timer;

// Function Declaration
void sendSensorData();

void setup()
{
  Serial.begin(9600);

  pinMode(MOISTUREPIN, INPUT);
  pinMode(RELAYPIN, OUTPUT);
  pinMode(SOLENOID1, OUTPUT);
  pinMode(SOLENOID2, OUTPUT);
  pinMode(SOLENOID3, OUTPUT);

  digitalWrite(RELAYPIN, LOW);
  digitalWrite(SOLENOID1, LOW);
  digitalWrite(SOLENOID2, LOW);
  digitalWrite(SOLENOID3, LOW);

  dht.setup(DHTPIN, DHTesp::DHT11);

  Blynk.begin(auth, ssid, password);

  timer.setInterval(2000L, sendSensorData);
}

void loop()
{
  Blynk.run();
  timer.run();
}

void sendSensorData()
{
  humidity = dht.getHumidity();
  temperature = dht.getTemperature();

  moistureValue = analogRead(MOISTUREPIN);

  moisture_percentage =
      100.0 - ((moistureValue / 1023.0) * 100.0);

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C");

  Serial.print(" | Humidity: ");
  Serial.print(humidity);
  Serial.print(" %");

  Serial.print(" | Moisture: ");
  Serial.print(moisture_percentage);
  Serial.println(" %");

  // Send Data to Blynk
  Blynk.virtualWrite(V1, temperature);
  Blynk.virtualWrite(V2, humidity);
  Blynk.virtualWrite(V3, moisture_percentage);

  // Sync Button States
  Blynk.syncVirtual(V4);
  Blynk.syncVirtual(V10);
  Blynk.syncVirtual(V15);
  Blynk.syncVirtual(V20);
}

// Fertilizer Pump Control
BLYNK_WRITE(V4)
{
  relayState = param.asInt();

  digitalWrite(RELAYPIN, relayState);

  Serial.print("Pump State: ");
  Serial.println(relayState);
}

// Solenoid Valve 1
BLYNK_WRITE(V10)
{
  solenoid1State = param.asInt();

  digitalWrite(SOLENOID1, solenoid1State);

  Serial.print("Solenoid 1: ");
  Serial.println(solenoid1State);
}

// Solenoid Valve 2
BLYNK_WRITE(V15)
{
  solenoid2State = param.asInt();

  digitalWrite(SOLENOID2, solenoid2State);

  Serial.print("Solenoid 2: ");
  Serial.println(solenoid2State);
}

// Solenoid Valve 3
BLYNK_WRITE(V20)
{
  solenoid3State = param.asInt();

  digitalWrite(SOLENOID3, solenoid3State);

  Serial.print("Solenoid 3: ");
  Serial.println(solenoid3State);
}
