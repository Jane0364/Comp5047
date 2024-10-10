#include "../lib/Modules/Color.h"

/**
 * @brief 构造函数
 * @note 给所有成员变量初始值
 */
ColorModule::ColorModule()
{
    cout << "[ColorModule] Init completed." << endl;
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
    if(Lock_AmmoEmpty.try_lock())
    {
        //todo
        //用随机数生成一种颜色
    }
}

/**
 * @brief 检查传感器的颜色
 * @note 
 */
void ColorModule::ColorCheck()
{
    //todo
    //调用传感器颜色
}