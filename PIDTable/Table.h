#pragma once
#include "PIDController.h"
#include "TouchScreen.h"
#include <Arduino.h>
/*
 * Table
 *  -Contains methods for balancing a ball using a touch screen
 *    and two servos.
 *    
 *    Nate Vollmer. 4/24/2016
 */

 #include <Servo.h>
class Table
{
    //----VARIABLES----//
  private:
    Servo horizontalServo;
    Servo verticalServo;
    double horizontalPercent;
    double verticalPercent;
    double horizontalAngle;
    double verticalAngle;
    double minHorizontalAngle;
    double maxHorizontalAngle;
    double minVerticalAngle;
    double maxVerticalAngle;

    double proportionConstant = 0.0;
    double integralConstant = 0;
    double derivativeConstant = 0.0;
    double desiredX = 50;
    double desiredY = 50;
    double actualX;
    double actualY;
    double xOutput;
    double yOutput;
    double xError;
    double yError;
    double sign;
    TouchScreen touchScreen;
    PIDController xPID;
    PIDController yPID;
  //----METHODS----//
  public:
    Table();
    void initPID();
    void attachServos(int horizontalPin, int verticalPin);
    void setServoRanges(double _minHorizontalAngle, double _maxHorizontalAngle, double _minVerticalAngle, double _maxVerticalAngle);
    void rotate(double verticalPercent, double horizontalPercent);
    void rotate();
    void setDesiredCoordinates(double x, double y);
    void setPIDConstants();
    bool shouldBalance();
    void balanceBall();
};

