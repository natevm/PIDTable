#pragma once
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
    double horizontalAngle;
    double verticalAngle;
    double minHorizontalAngle;
    double maxHorizontalAngle;
    double minVerticalAngle;
    double maxVerticalAngle;

    double proportionConstant;
    double integralConstant;
    double derivativeConstant;
    double desiredX;
    double desiredY;
    
  //----METHODS----//
  public:
    void attachServos(int horizontalPin, int verticalPin);
    void setServoRanges(double _minHorizontalAngle, double _maxHorizontalAngle, double _minVerticalAngle, double _maxVerticalAngle);
    void rotate(double verticalPercent, double horizontalPercent);
    void setDesiredCoordinates(double x, double y);
    void setPIDConstants(double kp, double ki, double kd);
    bool shouldBalance();
    void balanceBall();
};

