#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "NAMA_WIFI";
const char* password = "PASSWORD_WIFI";

WebServer server(80);
const int ledPin = 2;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connected");
  Serial.println(WiFi.localIP());

  server.on("/led/on", []() {
    digitalWrite(ledPin, HIGH);
    server.send(200, "text/plain", "LED ON");
  });

  server.on("/led/off", []() {
    digitalWrite(ledPin, LOW);
    server.send(200, "text/plain", "LED OFF");
  });

  server.begin();
}

void loop() {
  server.handleClient();
}
