#pragma once

class TouchScreen {
  private:
    int x1Pin;
    int x2Pin;
    int y1Pin;
    int y2Pin;
    int xResolution = 100;
    int yResolution = 100;
  public:
    TouchScreen(int x1Pin, int x2Pin, int y1Pin, int y2Pin);
    double getXCoordinate();
    double getYCoordinate();
};

