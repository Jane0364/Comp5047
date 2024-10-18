#include "../lib/main.h"

//开启特殊模块(自带线程)
ColorSensorModule CSM;

void setup()
{
    Serial.begin(9600);
//test
Serial.println("ColorSensor Starting");
    
}

void loop()
{
    if(!CSM.ThreadRun)
        CSM.StartColorSensor();

    //AM.AmmoModuleLoop();
    CM.ColorModuleLoop();
    ILM.IndicatorLightLoop();
    //TM.TriggerModuleLoop();

delay(500);
}