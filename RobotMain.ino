#include <WiFi.h>
#include "MotorControl.h"
#include "HtmlResponse.h"
#include "WiFiSetup.h"

// Set your Wi-Fi credentials
const char *ssid = "robot";
const char *password = "12345678"; // Make sure to use a strong password

WiFiServer server(80); // Using standard WiFiServer class

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);

    setupMotorPins();
    setupWiFi(ssid, password);

    IPAddress myIP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(myIP);

    server.begin();
    Serial.println("Server started");
}

void loop()
{
    WiFiClient client = server.available(); // Listen for incoming clients

    if (client)
    {
        Serial.println("New Client.");
        String currentLine = "";
        unsigned long timeout = millis();

        while (client.connected() && millis() - timeout < 5000)
        {
            if (client.available())
            {
                char c = client.read();
                timeout = millis(); // Reset timeout after receiving data
                Serial.write(c);    // Output to Serial for debugging

                if (c == '\n')
                { // Newline signifies end of a request
                    if (currentLine.length() == 0)
                    {
                        // Send the HTML response
                        sendHtmlResponse(client);
                        break;
                    }
                    else
                    {
                        currentLine = "";
                    }
                }
                else if (c != '\r')
                {
                    currentLine += c; // Accumulate request data
                }

                // Parse HTTP POST requests for motor control
                if (currentLine.indexOf("POST /forward") >= 0){
                    forward();
                }
                else if (currentLine.indexOf("POST /backward") >= 0){
                    backward();
                }
                else if (currentLine.indexOf("POST /right") >= 0){
                    right();
                }
                else if (currentLine.indexOf("POST /left") >= 0){
                    left();
                }
                else if (currentLine.indexOf("POST /stop") >= 0){
                    stopCar();
                }
                else if (currentLine.indexOf("POST /rightForward") >= 0){
                    rightForward();
                }
                else if (currentLine.indexOf("POST /leftForward") >= 0){
                    leftForward();
                }
                else if (currentLine.indexOf("POST /rightBackward") >= 0){
                    rightBackward();
                }
                else if (currentLine.indexOf("POST /leftBackward") >= 0){
                    leftBackward();
                }
            }
        }
        // Close the connection
        client.stop();
        Serial.println("Client Disconnected.");
    }
}