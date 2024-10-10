#include <iostream>
#include "../PublicResource.h"

using std::cout, std::endl;

class ColorModule
{
private:
    ColorModule();              //构造
public:
    void ColorModuleLoop();     //循环体
private:
    void ColorGenerate();       //生成需求颜色 //todo
    void ColorCheck();          //检查传感器的颜色
};