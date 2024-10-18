#include <thread>
#include <mutex>
#include <chrono>
#include <Arduino.h>

#ifndef PUBLICRESOURCE_H
#define PUBLICRESOURCE_H

/*常数*/
#define MAX_AMMO 5          //Ammo模块 最大备弹
#define FIRE_TIME 2         //Trigger模块 开火时长
#define MAX_HEALTH 5        //最大受击次数(血量)

/*公共变量*/
extern int ColorNeeded;            //需求颜色
extern int Ammo;                   //当前备弹
extern int Health;                 //受击次数
extern bool Flag_AmmoAdd;          //弹药增加标志  true:弹药要增加

/*颜色传感器*/
#define COLORSENSOR_COLOR_NULL -1       //颜色传感器_颜色_空
extern uint16_t ColorSensor_Red;               //颜色传感器拿到的红色(65535)
extern uint16_t ColorSensor_Green;             //颜色传感器拿到的绿色(65535)
extern uint16_t ColorSensor_Blue;              //颜色传感器拿到的蓝色(65535)

/*公共锁*/
extern std::mutex Lock_AmmoEmpty;  //空弹锁定  锁上:备弹空
extern std::mutex Lock_Fire;       //开火锁定  锁上:开火中

/*颜色*/
enum Color_t                //各种颜色
{
    COLOR_NULL,
    COLOR_RED,
    COLOR_GREEN,
    COLOR_BLUE,
};

/*接口号*/
#define COLOR_SENSOR_PIN 25     //颜色传感器接口
#define INDICATOR_LIGHT_RED 2      //红灯接口
#define INDICATOR_LIGHT_GREEN 13    //绿灯接口
#define INDICATOR_LIGHT_BLUE 14     //蓝灯接口

#endif //PUBLICRESOURCE_H