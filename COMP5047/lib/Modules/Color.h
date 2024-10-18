#include <iostream>
#include "../PublicResource.h"

#ifndef COLOR_H
#define COLOR_H

class ColorModule
{
public:
    ColorModule();              //构造
public:
    void ColorModuleLoop();     //循环体
private:
    void ColorGenerate();       //生成需求颜色
    void ColorCheck();          //检查传感器的颜色

    int ColorCompare(int R, int G, int B);     //颜色比较
    int RandomNumberGenerate(int min, int max);
};

#include <random>
#include <ctime>

#endif //COLOR_H