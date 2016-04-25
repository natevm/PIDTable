#include "TouchScreen.h"
#include <Arduino.h>
TouchScreen::TouchScreen(int _x1Pin, int _x2Pin, int _y1Pin, int _y2Pin){
 x1Pin = _x1Pin;
 x2Pin = _x2Pin;
 y1Pin = _y1Pin;
 y2Pin = _y2Pin;
}
int TouchScreen::getXCoordinate(){
   pinMode(y1Pin,INPUT);
   pinMode(y2Pin,INPUT);  
   digitalWrite(y2Pin,LOW);
   pinMode(x1Pin,OUTPUT);
   digitalWrite(x1Pin,HIGH);
   pinMode(x2Pin,OUTPUT);
   digitalWrite(x2Pin,LOW);
   return (analogRead(y1Pin))/(1024/xResolution); //Reads X axis touch position
}
int TouchScreen::getYCoordinate(){
   pinMode(x1Pin,INPUT);
   pinMode(x2Pin,INPUT);
   digitalWrite(x2Pin,LOW);
   pinMode(y1Pin,OUTPUT);
   digitalWrite(y1Pin,HIGH);
   pinMode(y2Pin,OUTPUT);
   digitalWrite(y2Pin,LOW);
   return (analogRead(x1Pin))/(1024/yResolution); //Reads Y axis touch position
}

