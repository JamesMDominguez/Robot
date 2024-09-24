#include <WiFi.h>
#include "WiFiSetup.h"

void setupWiFi(const char *ssid, const char *password)
{
    Serial.println("Configuring access point...");
    if (!WiFi.softAP(ssid, password))
    {
        Serial.println("Error creating access point");
        while (1)
            ; // Stop if AP creation fails
    }
}