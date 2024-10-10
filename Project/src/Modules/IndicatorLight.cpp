#include "../lib/Modules/IndicatorLight.h"

/**
 * @brief 构造函数
 * @note 给所有成员变量初始值
 */
IndicatorLightModule::IndicatorLightModule()
{
    //todo LightColor初始化
    cout << "[IndicatorLightModule] Init completed." << endl;
}

/**
 * @brief 指示灯模块的循环体
 * @note 放在loop()里
 */
void IndicatorLightModule::IndicatorLightLoop()
{
    //todo
}

/**
 * @brief 开灯(定时)
 * @param LightColor:灯的颜色,见PublicResource
 * @param Time:开灯时长
 * @note 开启LightOnThread()线程
 */
void IndicatorLightModule::LightOn(int LightColor, int Time)
{
    //todo 
}

/**
 * @brief 开定时灯线程
 * @param LightColor:灯的颜色
 * @param Time:开灯时长
 */
void LightOnThread(int LightColor, int Time)
{
    //todo
}

/**
 * @brief 开灯
 * @param LightColor:灯的颜色,见PublicResource
 */
void IndicatorLightModule::LightOn(int LightColor)
{
    //todo
}

/**
 * @brief 关灯
 * @param LightColor:灯的颜色,见PublicResource
 */
void IndicatorLightModule::LightOff(int LightColor)
{
    //todo
}

/**
 * @brief 关所有灯
 * @note
 */
void IndicatorLightModule::LightOffAll()
{
    //todo
}