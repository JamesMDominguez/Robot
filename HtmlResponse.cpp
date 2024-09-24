#include "HtmlResponse.h"

void sendHtmlResponse(WiFiClient &client)
{
    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println();
    client.println(R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Arrow Joystick</title>
    <style>
        body {
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            background-color: #f0f0f0;
            font-family: Arial, sans-serif;
        }
        .joystick {
            display: grid;
            grid-template-areas: 
                "left-backward backward right-backward"
                "left stop right"
                "left-forward forward right-forward";
            gap: 5px;
        }
        .button {
            width: 100px;
            height: 100px;
            display: flex;
            justify-content: center;
            align-items: center;
            background-color: #000000;
            color: white;
            text-decoration: none;
            border-radius: 10px;
            font-size: 24px;
            font-weight: bold;
            border: none;
            cursor: pointer;
            user-select: none;
            -webkit-tap-highlight-color: rgba(0, 0, 0, 0);
            -webkit-user-select: none;
            -khtml-user-select: none;
        }
        .button:hover {
            background-color: #0056b3;
        }
        .stop-button {
            grid-area: stop;
        }
        .left {
            grid-area: left;
        }
        .left-forward {
            grid-area: left-forward;
        }
        .forward {
            grid-area: forward;
        }
        .right-forward {
            grid-area: right-forward;
        }
        .right {
            grid-area: right;
        }
        .right-backward {
            grid-area: right-backward;
        }
        .backward {
            grid-area: backward;
        }
        .left-backward {
            grid-area: left-backward;
        }
    </style>
    <script>
        function sendCommand(command) {
            fetch(command, { method: 'POST' });
        }
    </script>
</head>
<body>
    <div class="joystick">
        <button class="button left-backward" onmousedown="sendCommand('/leftForward')" ontouchstart="sendCommand('/leftForward')" ontouchend="toggleCheckbox('stop');">↖</button>
        <button class="button backward" onmousedown="sendCommand('/forward')" ontouchstart="sendCommand('/forward')" ontouchend="toggleCheckbox('stop');">↑</button>
        <button class="button right-backward" onmousedown="sendCommand('/rightForward')" ontouchstart="sendCommand('/rightForward')" ontouchend="toggleCheckbox('stop');">↗</button>
        <button class="button left" onmousedown="sendCommand('/left')" ontouchstart="sendCommand('/left')" ontouchend="toggleCheckbox('stop');">←</button>
        <button class="button stop-button" onmousedown="sendCommand('/stop')" ontouchstart="sendCommand('/stop')">Stop</button>
        <button class="button right" onmousedown="sendCommand('/right')" ontouchstart="sendCommand('/right')" ontouchend="toggleCheckbox('stop');">→</button>
        <button class="button left-forward" onmousedown="sendCommand('/leftBackward')" ontouchstart="sendCommand('/leftBackward')" ontouchend="toggleCheckbox('stop');">↙</button>
        <button class="button forward" onmousedown="sendCommand('/backward')" ontouchstart="sendCommand('/backward')" ontouchend="toggleCheckbox('stop');">↓</button>
        <button class="button right-forward" onmousedown="sendCommand('/rightBackward')" ontouchstart="sendCommand('/rightBackward')" ontouchend="toggleCheckbox('stop');">↘</button>
    </div>
</body>
</html>
  )rawliteral");
    client.println();
}