#include <Arduino.h>
#include <Wifi.h>
#include <PubSubClient.h>
#include "secrets.h"

const char* ssid = SECURE_SSID;
const char* password = SECURE_PASSWORD;
const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);

const char* topic = "IoT-IF-Undip";
const int ledPin = 2;

void setup_wifi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  if ((char)payload[0] == '1') {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}

void reconnect() {
  while(!client.connected()) {
    if (client.connect("esp32-client")) {
      client.subscribe(topic);
    } else {
      delay(500);
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!client.connected()) {
    reconnect();
  }

  client.loop();
}
