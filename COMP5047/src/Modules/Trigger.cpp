#include "../lib/Modules/Trigger.h"

/**
 * @brief 构造函数
 * @note 给所有成员变量初始值
 */
TriggerModule::TriggerModule()
{
    Serial.println("[TriggerModule] Init completed.");
}

/**
 * @brief 扳机模块的循环体
 * @note 放在loop()里
 */
void TriggerModule::TriggerModuleLoop()
{
    if(ReadTriggerSignal())
        OpenFire();
}

/**
 * @brief 读取开火信号
 * @return true:有按下扳机 false:没信号
 * @note
 */
bool TriggerModule::ReadTriggerSignal()
{
    //todo
    if(Lock_Fire.try_lock())
        OpenFire();
    else
        Serial.println("[TriggerModule][ReadTriggerSignal] Already firing.");

    return false;
}

/**
 * @brief 开火
 * @note 开启线程，让红外发射器工作
 */
void TriggerModule::OpenFire()
{
    Lock_Fire.lock();
    //todo
}

/**
 * @brief 红外线发射线程
 * @note 一次性线程；让红外发射器工作
 */
void InfraredEmitterThread()
{
    //开始
    Serial.println("[InfraredEmitterThread] Fire start.");
    //1.打开红外灯
//todo
    //2.等待X秒
    std::this_thread::sleep_for(std::chrono::seconds(FIRE_TIME));
    //3.关闭红外灯
//todo
    //4.备弹-1
    Ammo -= 1;
    //5.开火锁定解除
    Lock_Fire.unlock();
    //结束
    Serial.println("[InfraredEmitterThread] Fire stop.");
}