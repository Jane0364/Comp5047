#include <iostream>
#include "../PublicResource.h"

#ifndef INDICATORLIGHT_H
#define INDICATORLIGHT_H

class IndicatorLightModule //todo
{
public:
    int IndicatorLightColor;
public:
    IndicatorLightModule();     //构造
public:
    void IndicatorLightLoop();  //循环体
public:
    void LightOn(int LightColor);           //指定灯-开
    void LightOff(int LightColor);          //指定灯-关
    void LightOffAll();                     //所有灯-关
};

#endif //INDICATORLIGHT_H