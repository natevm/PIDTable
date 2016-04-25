#include "Table.h"
#include <SPI.h>

//Attaches servos to pins, 
void Table::attachServos(int horizontalPin, int verticalPin)
{
  horizontalServo.attach(horizontalPin);
  verticalServo.attach(verticalPin);
}

//Sets the maximum and minimum ranges of both the vertical and horizontal servos.
void Table::setServoRanges(double _minHorizontalAngle, double _maxHorizontalAngle, double _minVerticalAngle, double _maxVerticalAngle){
  minHorizontalAngle = _minHorizontalAngle;
  maxHorizontalAngle = _maxHorizontalAngle;
  minVerticalAngle = _minVerticalAngle;
  maxVerticalAngle = _maxVerticalAngle;
}

//Rotates the table servos, where 0 is minimum and 255 is maximum.
void Table::rotate(double verticalPercent, double horizontalPercent){
  horizontalAngle = ((maxHorizontalAngle + minHorizontalAngle)*.5) + (horizontalPercent*(maxHorizontalAngle - minHorizontalAngle)*.5);
  verticalAngle = ((maxVerticalAngle + minVerticalAngle)*.5) + (verticalPercent*(maxVerticalAngle - minVerticalAngle)*.5);
  
  horizontalServo.write(horizontalAngle);
  verticalServo.write(verticalAngle);
}

//Sets the target location for the ball to move to.
void Table::setDesiredCoordinates(double x, double y){
  //TODO: get max and min X and Y coordinates
  desiredX = x;
  desiredY = y;
}

//Sets the proportional, integral, and derivative constants in the PID.
void Table::setPIDConstants(double kp, double ki, double kd){
  proportionConstant = kp;
  integralConstant = ki;
  derivativeConstant = kd;
}

//Returns true if the table should balance the ball. 
bool Table::shouldBalance(){
  return false;
}

//Using the coordinates from the touch screen, this moves the ball to a particular location.
void Table::balanceBall(){
  
}
