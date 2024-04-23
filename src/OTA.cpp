#include "OTA.h"

OTA::OTA(const char *hostName) {
	ArduinoOTA.setPort(8266);
	ArduinoOTA.setHostname(hostName);

	ArduinoOTA.onStart([]() {
		// Serial.println("OTA Update Started...");
	});
	ArduinoOTA.onEnd([]() {
		// Serial.println("\nOTA Update Ended!");
	});
	ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
		// Serial.printf("Progress: %u%%\r\n", (progress / (total / 100)));
	});
	ArduinoOTA.onError([](ota_error_t error) {
		// Serial.printf("Error[%u]: ", error);
		if (error == OTA_AUTH_ERROR) {
			// Serial.println("OTA Auth Failed");
		}
		else if (error == OTA_BEGIN_ERROR) {
			// Serial.println("OTA Begin Failed");
		}
		else if (error == OTA_CONNECT_ERROR) {
			// Serial.println("OTA Connect Failed");
		}
		else if (error == OTA_RECEIVE_ERROR) {
			// Serial.println("OTA Receive Failed");
		}
		else if (error == OTA_END_ERROR) {
			// Serial.println("OTA End Failed");
		}
	});

	ArduinoOTA.begin();
}