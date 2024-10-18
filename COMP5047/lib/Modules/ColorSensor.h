#include <Wire.h>
#include "../PublicResource.h"
#include "../lib/MH_TCS34725/MH_TCS34725.h"

#ifndef COLORSENSOR_H
#define COLORSENSOR_H

class ColorSensorModule
{
public:
    std::thread Thread_ColorSensorLoop;
    bool ThreadRun;
public:
    ColorSensorModule();        //构造
    ~ColorSensorModule();       //析构
public:
    void ColorSensorLoop();     //循环体
public:
    void StartColorSensor();
};

#endif //COLORSENSOR_H