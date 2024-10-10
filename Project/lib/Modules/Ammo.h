#include <iostream>
#include "../PublicResource.h"

using std::cout, std::endl;

class AmmoModule
{
private:
    bool Flag_AmmoAdd;      //弹药增加标志  true:弹药要增加

private:
    AmmoModule();               //构造
public:
    void AmmoModuleLoop();      //循环体
private:
    void AmmoAddFlagCheck();    //检查弹药增加标志
    void AmmoCheck();           //检查弹药量
};





