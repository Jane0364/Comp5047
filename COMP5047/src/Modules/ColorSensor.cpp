#include "../lib/Modules/ColorSensor.h"

// 定义并初始化TCS34725传感器对象，使用默认的积分时间和增益值
MH_TCS34725 tcs = MH_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

ColorSensorModule::ColorSensorModule()
{
}

ColorSensorModule::~ColorSensorModule()
{
    if (Thread_ColorSensorLoop.joinable())
        ThreadRun = false;
}

void ColorSensorModule::ColorSensorLoop()
{
    Serial.println("Thread alive.");

    // 可以根据需求设置积分时间和增益
    tcs.setIntegrationTime(TCS34725_INTEGRATIONTIME_154MS);
    tcs.setGain(TCS34725_GAIN_16X);

    int LoopCount = 0;
    while(ThreadRun)
    {
        LoopCount++;

        ColorSensor_Red = COLORSENSOR_COLOR_NULL;
        ColorSensor_Green = COLORSENSOR_COLOR_NULL;
        ColorSensor_Blue = COLORSENSOR_COLOR_NULL;
        uint16_t c = COLORSENSOR_COLOR_NULL;

        // 获取RGB和清晰度数据
        tcs.getRGBC(&ColorSensor_Red, &ColorSensor_Green, &ColorSensor_Blue, &c);
        
        //Test打印
        if (LoopCount % 4 == 0)
        {
            Serial.print(" R: "); Serial.print(ColorSensor_Red);
            Serial.print(" G: "); Serial.print(ColorSensor_Green);
            Serial.print(" B: "); Serial.print(ColorSensor_Blue);
            Serial.print(" C: "); Serial.println(c);
        }
        //Test打印

        delay(200);  // 延时0.2秒
    }
    Serial.println("Thread end");
}

void ColorSensorModule::StartColorSensor()
{
  // 初始化TCS34725传感器
  while (!tcs.begin())
  {
    Serial.print("[ColorSensor] Color sensor init failed.");
    delay(1000);  // 初始化失败时1秒后重试
  }
  Serial.print("[ColorSensor] Color sensor init success.");

  //开启传感器线程
  Serial.print("[ColorSensor] Starting thread.");
  ThreadRun = true;
  Thread_ColorSensorLoop = std::thread(&ColorSensorModule::ColorSensorLoop, this);
  Thread_ColorSensorLoop.detach();
}