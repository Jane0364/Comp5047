#include "ArduinoJson.h"
#include <thread>
#include <mutex>
#include <chrono>

/*常数*/
#define MAX_AMMO 5          //Ammo模块 最大备弹
#define FIRE_TIME 2         //Trigger模块 开火时长
#define MAX_HEALTH 5        //最大受击次数(血量)

/*公共变量*/
int ColorNeeded;            //需求颜色
int Ammo;                   //当前备弹
int Health;                 //受击次数

/*公共锁*/
std::mutex Lock_AmmoEmpty;  //空弹锁定  锁上:备弹空
std::mutex Lock_Fire;       //开火锁定  锁上:开火中

/*颜色*/
enum Color_t                //各种颜色
{
    COLOR_NULL,
    COLOR_RED,
    COLOR_YELLOW,
    COLOR_GREEN,
};