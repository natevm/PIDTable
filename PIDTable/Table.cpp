#include "PIDController.h"
#include "Table.h"
#include <SPI.h>

Table::Table() : touchScreen(A0,A1,A2,A3)
{
  xPID.SetTunings(1.0,1.0,1.0);
  yPID.SetTunings(1.0,1.0,1.0);

  xPID.SetSampleTime(1);
  yPID.SetSampleTime(1);

  xPID.SetMode(AUTOMATIC);
  yPID.SetMode(AUTOMATIC);

  xPID.SetControllerDirection(DIRECT);
  yPID.SetControllerDirection(DIRECT);

  xPID.SetInput(50);
  xPID.SetTarget(50);
  xPID.Initialize();

  yPID.SetInput(50);
  yPID.SetTarget(50);
  yPID.Initialize();

  xPID.SetOutputLimits(-100,100);
  yPID.SetOutputLimits(-100,100);
}

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
void Table::rotate(double horizontalPercent, double verticalPercent){
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
void Table::setPIDConstants(){
  //Serial.println("KP: " + String(kp));
  xPID.SetTunings(.1250,2.0,30);
  yPID.SetTunings(.1250,2.0,30);
}


//Using the coordinates from the touch screen, this moves the ball to a particular location.
void Table::balanceBall(){
  setPIDConstants();
  setDesiredCoordinates(50, 50);
  
  actualX = touchScreen.getXCoordinate();
  actualY = touchScreen.getYCoordinate();

  //Error ranges from -100 to 100
  xPID.SetInput(actualX);
  yPID.SetInput(actualY);
  
  xPID.Compute();
  yPID.Compute();

  double horizontalOutput;
  double verticalOutput;
  horizontalOutput=(xPID.GetOutput()/50);
  verticalOutput=(yPID.GetOutput()/50);
  
  Serial.println(String(verticalOutput));
  rotate(horizontalOutput, -verticalOutput);
 // rotate(0,0);
}
