#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <WiFi101.h>
#include <BlynkSimpleWiFiShield101.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
//char auth[] = "8d98bb6ddcdb4a0d9f50acdb68ecb477";
//char auth[] = "1cee2740e069430698eb8547bafefb3f";
char auth[] = "e50e3a50092c4a2f91237cc834b7289b";

// Your WiFi credentials
char ssid[] = "DeviceNet";
char pass[] = "icmjn3tx25";        // Set to "" for open networks

double joystickX = 50;
double joystickY = 50;
double sliderKP = 0;
double sliderKI = 0;
double sliderKD = 0;

//Attach joystick to V0. It will write to joystickX and joystickY when moved.
BLYNK_WRITE(V0)
{
  joystickX = map(param[0].asInt(),0,255,0,100); 
  joystickY = map(param[1].asInt(),0,255,0,100); 
}
//Attach slider to V1. It will write to sliderKP when moved.  
BLYNK_WRITE(V1)
{
  sliderKP = param.asInt()/100.0; 
}
//Attach slider to V2. It will write to sliderKI when moved. defined as a %
BLYNK_WRITE(V2)
{
  sliderKI = param.asInt()/100.0;
}
//Attach slider to V3. It will write to sliderKD. defined as a %
BLYNK_WRITE(V3)
{
  sliderKD = param.asInt()/100.0;
}
