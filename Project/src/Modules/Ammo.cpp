#include "../lib/Modules/Ammo.h"

/**
 * @brief 构造函数
 * @note 给所有成员变量初始值
 */
AmmoModule::AmmoModule()
{
    Flag_AmmoAdd = false;
    cout << "[AmmoModule] Init completed." << endl;
}

/**
 * @brief 发射模块的循环体
 * @note 放在loop()里
 */
void AmmoModule::AmmoModuleLoop()
{
    AmmoAddFlagCheck();
    AmmoCheck();
}

/**
 * @brief 检查弹药增加标志
 * @note 检查True后，增加Ammo
 */
void AmmoModule::AmmoAddFlagCheck()
{
    if(Flag_AmmoAdd)
    {
        Ammo = MAX_AMMO;
        Flag_AmmoAdd = false;
        Lock_AmmoEmpty.unlock();
        cout << "[AmmoModule][AmmoAddFlagCheck] Ammo added." << endl;
    }
}

/**
 * @brief 检查弹药量
 * @note 弹药为0后添加空弹锁定
 */
void AmmoModule::AmmoCheck()
{
    if(Ammo <= 0)
    {
        Ammo = 0;
        if(Lock_AmmoEmpty.try_lock())
            Lock_AmmoEmpty.lock();
        cout << "[AmmoModule][Check] Ammo is empty." << endl;
    }
}