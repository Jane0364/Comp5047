#include "../lib/main.h"
#include <Arduino.h>

void setup()
{
    //初始化公共资源
    Lock_AmmoEmpty.unlock();
    Lock_Fire.unlock();

    ColorNeeded = COLOR_NULL;   //初始颜色-空
    Ammo = MAX_AMMO;            //初始备弹-最大
    Health = 0;                 //血量-0
}

void loop()
{
    AM.AmmoModuleLoop();
    CM.ColorModuleLoop();
    ILM.IndicatorLightLoop();
    TM.TriggerModuleLoop();
}