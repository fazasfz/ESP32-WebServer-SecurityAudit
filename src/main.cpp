#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

// STEP 2: ESP32 opens port 80 (HTTP)
WebServer server(80);

unsigned long requestCount = 0;

// ===== DEFENSE VARIABLES =====
unsigned long lastRequestTime = 0;
const unsigned long MIN_INTERVAL = 300; // milliseconds (rate limit)

void handleRoot() {
  unsigned long currentTime = millis();

  // ===== STEP 4: DEFENSE – RATE LIMITING =====
  if (currentTime - lastRequestTime < MIN_INTERVAL) {
    Serial.println("⚠️ Too many requests detected!");
    server.send(429, "text/plain", "429 Too Many Requests");
    return;
  }

  lastRequestTime = currentTime;

  // ===== ACCEPTED REQUEST =====
  requestCount++;
  Serial.print("Accepted Request #: ");
  Serial.println(requestCount);

  server.send(200, "text/plain",
              "ESP32 Web Server Running (DEFENDED)\nRequests: " + String(requestCount));
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("Connecting to WiFi...");

  // STEP 1: ESP32 connects to a 2.4 GHz local network
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected!");
  Serial.print("ESP32 IP: ");
  Serial.println(WiFi.localIP());

  // STEP 3: Request handling
  server.on("/", handleRoot);

  // STEP 2: Web server starts
  server.begin();
  Serial.println("HTTP server started (WITH DEFENSE)");
}

void loop() {
  server.handleClient();
}
