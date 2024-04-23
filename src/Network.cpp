#include "Network.h"

Network::Network(char *ssid, char *password) {

	Serial.println("Setting WiFi mode to WIFI_STA");
    WiFi.mode(WIFI_STA);

	Serial.println("Connecting to: " + String(ssid));
    WiFi.begin(ssid, password);

	Serial.println("Waiting for connection...");
	if	(WiFi.waitForConnectResult(10000) != WL_CONNECTED) {
		Serial.println("Connection Failed! Rebooting...\n");
		ESP.restart();
	}
	else {
		Serial.println("Connected to WiFi");
		Serial.print("IP Address: ");
		Serial.println(WiFi.localIP());
		Serial.println(""); // for new line
	}
}