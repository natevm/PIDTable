#pragma once
#define MANUAL 0
#define AUTOMATIC 1
 
#define DIRECT 0
#define REVERSE 1
class PIDController {
  /*working variables*/
  public:
    unsigned long lastTime;
    double Input, Output, Setpoint;
    double ITerm, lastInput;
    double kp, ki, kd;
    int SampleTime = 1000; //1 sec
    double outMin, outMax;
    bool inAuto = false;
    int controllerDirection = 0;

  void Compute();
  void SetTunings(double Kp, double Ki, double Kd);
  void SetSampleTime(int NewSampleTime);
  void SetOutputLimits(double Min, double Max);
  void SetMode(int Mode);
  void Initialize();
  void SetControllerDirection(int Direction);
  
  void SetInput(double _input);
  void SetTarget(double _target);
  double GetOutput();
  double GetSummation();
};


