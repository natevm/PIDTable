#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <WiFi101.h>
#include <BlynkSimpleWiFiShield101.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
//char auth[] = "8d98bb6ddcdb4a0d9f50acdb68ecb477";
char auth[] = "1cee2740e069430698eb8547bafefb3f";

// Your WiFi credentials
char ssid[] = "optix";
char pass[] = "onmyhonor";        // Set to "" for open networks

double joystickX = 0;
double joystickY = 0;

//Attach joystick to V0. It will write to joystickX and joystickY when moved.
BLYNK_WRITE(V0)
{
  joystickX = (param[0].asInt()/128.0) - 1.0; 
  joystickY = (param[1].asInt()/128.0) - 1.0; 
}
