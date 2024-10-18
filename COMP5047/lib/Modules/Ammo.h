#include <iostream>
#include "../PublicResource.h"

#ifndef AMMO_H
#define AMMO_H

class AmmoModule
{
public:
    AmmoModule();               //构造
public:
    void AmmoModuleLoop();      //循环体
private:
    void AmmoAddFlagCheck();    //检查弹药增加标志
    void AmmoCheck();           //检查弹药量
};

#endif //AMMO_H