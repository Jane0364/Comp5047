#include "../lib/PublicResource.h"

int ColorNeeded = COLOR_NULL;   //需求颜色
int Ammo = MAX_AMMO;            //当前备弹
int Health = 0;                 //受击次数
bool Flag_AmmoAdd = false;      //弹药增加标志  true:弹药要增加

uint16_t ColorSensor_Red;               //颜色传感器拿到的红色(65535)
uint16_t ColorSensor_Green;             //颜色传感器拿到的绿色(65535)
uint16_t ColorSensor_Blue;              //颜色传感器拿到的蓝色(65535)

std::mutex Lock_AmmoEmpty;  //空弹锁定  锁上:备弹空
std::mutex Lock_Fire;       //开火锁定  锁上:开火中