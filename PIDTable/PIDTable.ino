#include "Table.h"
#include "TouchScreen.h"
#include "BlynkStuff.h"

TouchScreen touchScreen(A0, A1, A2, A3);
Table table;

double x, y;
int xSign, ySign;
void setup() {
  table.setServoRanges(45, 125, 45, 125);
  table.attachServos(2,3);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
  //table.rotate(joystickX, joystickY);
  x = touchScreen.getXCoordinate()/100.0;
  //x = x*x;
  y = touchScreen.getYCoordinate()/100.0;
  //y = y * y;
  
  table.rotate((y-.5)*2.0, (x-.5)*2.0);
  //Blynk.virtualWrite(1, "X: " + String(touchScreen.getXCoordinate()) + "\n");
  //Blynk.virtualWrite(1, "Y: " + String(touchScreen.getYCoordinate()) + "\n\n");
  delay(15);
}
