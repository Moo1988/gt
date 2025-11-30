#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>

void setup() {
  Serial.begin(115200);
  WiFi.begin("Vodafone", "Wl");

  Serial.print("WLAN...");
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("FAIL");
    return;
  }
  Serial.println("OK");
  Serial.println(WiFi.localIP());

  WiFiClientSecure client;
  client.setInsecure();
  HTTPClient http;

  if (!http.begin(client, "https://raw.githubusercontent.com/")) {
    Serial.println("begin fail");
    return;
  }
  http.setUserAgent("ESP32-TEST");
  int code = http.GET();
  Serial.printf("TEST GET = %d\n", code);
}

void loop() {}
