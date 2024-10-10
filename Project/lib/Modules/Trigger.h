#include <iostream>
#include "../PublicResource.h"

using std::cout, std::endl;

class TriggerModule //todo
{
private:
    TriggerModule();            //构造
public:
    void TriggerModuleLoop();   //循环体
private:
    bool ReadTriggerSignal();   //读取开火信号
    void OpenFire();            //开火
};

/*红外线发射器*/    //可能需要移位置
void InfraredEmitterThread();   //红外线发射线程