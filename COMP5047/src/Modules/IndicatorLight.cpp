#include "../lib/Modules/IndicatorLight.h"

/**
 * @brief 构造函数
 * @note 给所有成员变量初始值
 */
IndicatorLightModule::IndicatorLightModule()
{
    IndicatorLightColor = COLOR_NULL;
    pinMode(INDICATOR_LIGHT_RED, OUTPUT);
    pinMode(INDICATOR_LIGHT_GREEN, OUTPUT);
    pinMode(INDICATOR_LIGHT_BLUE, OUTPUT);
    Serial.println("[IndicatorLightModule] Init completed.");
}

/**
 * @brief 指示灯模块的循环体
 * @note 放在loop()里
 */
void IndicatorLightModule::IndicatorLightLoop()
{
    IndicatorLightColor = ColorNeeded;
    if (IndicatorLightColor != COLOR_NULL)
    {
        //Serial.println("Color needed found. Ready to light");
        if (IndicatorLightColor == COLOR_RED)
        {
            LightOff(COLOR_GREEN);
            LightOff(COLOR_BLUE);
            LightOn(COLOR_RED);
        }
        if (IndicatorLightColor == COLOR_GREEN)
        {
            LightOff(COLOR_RED);
            LightOff(COLOR_BLUE);
            LightOn(COLOR_GREEN);
        }
        if (IndicatorLightColor == COLOR_BLUE)
        {
            LightOff(COLOR_RED);
            LightOff(COLOR_GREEN);
            LightOn(COLOR_BLUE);
        }
    }
}


/**
 * @brief 开灯
 * @param LightColor:灯的颜色,见PublicResource
 */
void IndicatorLightModule::LightOn(int LightColor)
{
    if (LightColor == COLOR_RED)
        digitalWrite(INDICATOR_LIGHT_RED, HIGH);
    else if (LightColor == COLOR_GREEN)
        digitalWrite(INDICATOR_LIGHT_GREEN, HIGH);
    else if (LightColor == COLOR_BLUE)
        digitalWrite(INDICATOR_LIGHT_BLUE, HIGH);
}

/**
 * @brief 关灯
 * @param LightColor:灯的颜色,见PublicResource
 */
void IndicatorLightModule::LightOff(int LightColor)
{
    if (LightColor == COLOR_RED)
        digitalWrite(INDICATOR_LIGHT_RED, LOW);
    else if (LightColor == COLOR_GREEN)
        digitalWrite(INDICATOR_LIGHT_GREEN, LOW);
    else if (LightColor == COLOR_BLUE)
        digitalWrite(INDICATOR_LIGHT_BLUE, LOW);
}

/**
 * @brief 关所有灯
 * @note
 */
void IndicatorLightModule::LightOffAll()
{
    LightOff(COLOR_RED);
    LightOff(COLOR_GREEN);
    LightOff(COLOR_BLUE);
}