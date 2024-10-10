#include <iostream>
#include "../PublicResource.h"

using std::cout, std::endl;

class IndicatorLightModule //todo
{
private:
    IndicatorLightModule();     //构造
public:
    void IndicatorLightLoop();  //循环体
public:
    void LightOn(int LightColor, int Time); //指定灯，开n秒
    void LightOn(int LightColor);           //指定灯-开
    void LightOff(int LightColor);          //指定灯-关
    void LightOffAll();                     //所有灯-关
};

void LightOnThread(int LightColor, int Time);   //开定时灯线程
//todo 开灯线程开启时，所有其他开灯方法上锁