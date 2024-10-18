#include "../lib/Modules/Color.h"

/**
 * @brief 构造函数
 * @note 给所有成员变量初始值
 */
ColorModule::ColorModule()
{
    Serial.println("[ColorModule] Init completed.");
}

/**
 * @brief 颜色模块的循环体
 * @note 放在loop()里
 */
void ColorModule::ColorModuleLoop()
{
    ColorGenerate();
    ColorCheck();
}

/**
 * @brief 生成需求颜色
 * @note 如果Ammo模块的空弹锁定(Lock_AmmoEmpty)为True，就要生成颜色
 */
void ColorModule::ColorGenerate()
{
    if(!Lock_AmmoEmpty.try_lock() && ColorNeeded == COLOR_NULL)
    {
        Serial.println("Color generating.");
        //用随机数生成一种颜色
        ColorNeeded = RandomNumberGenerate(1, 3);
        if (ColorNeeded != COLOR_RED && ColorNeeded != COLOR_GREEN && ColorNeeded != COLOR_BLUE)
        {
            Serial.println("[ColorModule][ColorGenerate] Color generate error, using default color.");
            ColorNeeded = COLOR_NULL + 1;
        }

        //Test打印
        std::string printstr = "";
        if (ColorNeeded == COLOR_RED)
            Serial.println("[Test] ColorNeeded = Red");
        else if (ColorNeeded == COLOR_GREEN)
            Serial.println("[Test] ColorNeeded = Green");
        else if (ColorNeeded == COLOR_BLUE)
            Serial.println("[Test] ColorNeeded = Blue");
        else
            Serial.println("[Test] ColorNeeded = ERROR");
        //Test打印
    }
}

/**
 * @brief 检查传感器的颜色
 * @note 
 */
void ColorModule::ColorCheck()
{
    //如果没有需求颜色，跳过
    if (ColorNeeded == COLOR_NULL)
    {
        delay(200);
        return;
    }
    //如果传感器没颜色，跳过
    if (ColorSensor_Red == COLORSENSOR_COLOR_NULL ||
        ColorSensor_Green == COLORSENSOR_COLOR_NULL ||
        ColorSensor_Blue == COLORSENSOR_COLOR_NULL)
    {
        delay(200);
        return;
    }

    //调用传感器颜色(65535)
    int SensorRGB_R = ColorSensor_Red;
    int SensorRGB_G = ColorSensor_Green;
    int SensorRGB_B = ColorSensor_Blue;

    //对比是否满足颜色
    if (ColorNeeded == ColorCompare(SensorRGB_R, SensorRGB_G, SensorRGB_B) &&
        ColorNeeded != COLOR_NULL)
    {
        Lock_AmmoEmpty.unlock();
        Flag_AmmoAdd = true;
        ColorNeeded = COLOR_NULL;
        Serial.println("Color correct!");
    }
}

int ColorModule::ColorCompare(int R, int G, int B)
{
    double Value[3] = {-1, -1, -1};
    int MaxValue = COLOR_NULL;

    if (R > G && R > B)
    {
        MaxValue = COLOR_RED;
        Value[0] = R;
        Value[1] = G;
        Value[2] = B;
    }
    else if (G > R && G > B)
    {
        MaxValue = COLOR_GREEN;
        Value[0] = G;
        Value[1] = R;
        Value[2] = B;
    }
    else if (B > R && B > G)
    {
        MaxValue = COLOR_BLUE;
        Value[0] = B;
        Value[1] = R;
        Value[2] = G;
    }
    else
        goto END;
    
    if (Value[0] < 0 || Value[1] < 0 || Value[2] < 0 ||
        MaxValue == COLOR_NULL)
        goto END;

    if (Value[0] >= Value[1] + Value[0]*0.2 &&
        Value[0] >= Value[2] + Value[0]*0.2)
        return MaxValue;

END:
    return COLOR_NULL;
}

int RandomNumberList[] = {2, 3, 2, 1, 3, 2, 1, 2, 1, 2, 3, 2, 1, 3, 1, 3, 2, 1, 3, 1, 3};
int RandomLoop = 0;

int ColorModule::RandomNumberGenerate(int min, int max)
{
    RandomLoop ++;
    if (RandomLoop == 20)
        RandomLoop = 0;
    return RandomNumberList[RandomLoop];
}