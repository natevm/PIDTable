#include "Table.h"
#include "BlynkStuff.h"

Table table;

double x, y;

void setup() {
  //first number is for leveling the table
  //add 40 for min
  //subtract 40 for max
  table.setServoRanges(105 + 40, 105 - 40, 84-40, 84+40); // x,y 
  table.attachServos(2,3);
  Serial.begin(9600);
  //Blynk.begin(auth, ssid, pass);  
}

void loop() {
  //Blynk.run();
 
  table.setDesiredCoordinates(50.0,50.0);
  //old kp = 2.18535
  //ku = 4.3707
  //new kp = .6 * 4.3707 = 2.62242
  //tu = .825
  double tu = .825;
  //table.setPIDConstants(0,0,0.0808);
  //table.setPIDConstants(2.18535,.00,0.0);
  table.balanceBall();
  //delay(1);
  //for (int i = 0; i < 100; i++)
  //Serial.println();
}
