#define BLYNK_TEMPLATE_ID "<BLYNK_TEMPLATE_ID>"
#define BLYNK_TEMPLATE_NAME "<BLYNK_TEMPLATE_NAME>"
#define BLYNK_AUTH_TOKEN "<BLYNK_AUTH_TOKEN>"

#include <BlynkSimpleStream.h>


int sensorPin = A0;
int ledPin = 9;
int sensorValue = 1;
char auth[] = "<Author ID>";

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Blynk.begin(auth, Serial);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

BLYNK_WRITE(V1) {
  int pinData = param.asInt();
  if (pinData == 1) {
    digitalWrite(11, HIGH);
  } else {
    digitalWrite(11, LOW);
  }
}

void loop() {
  sensorValue = analogRead(sensorPin);

  if (sensorValue <= 450) {
    digitalWrite(ledPin, HIGH);
    delay(sensorValue); // Pause for sensorValue milliseconds
  } else {
    digitalWrite(ledPin, LOW);
    delay(sensorValue); // Pause for sensorValue milliseconds
  }

  Blynk.run();
}
