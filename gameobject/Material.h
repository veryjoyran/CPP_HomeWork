#pragma once
#include <QPainter>
#include "Object.h"

class Material : public Object
{
public:
    enum MaterialType { BUFF_ATTACK, BUFF_FRIEND, BUFF_SHOOT, BUFF_SPEED }; // 枚举类型，表示物品的类型
    MaterialType materialType; // 物品类型
    Material(float x = 0, float y = 1, float speed = -0.005, float radius = 0.15); // 构造函数
    void updatePos(); // 更新物品位置
    float speed; // 物品速度
    QString imgPath; // 图片路径
    float getRotation(); // 获取旋转角度

private:
    float rotation; // 旋转角度
    int lastTime; // 上次更新时间
};
