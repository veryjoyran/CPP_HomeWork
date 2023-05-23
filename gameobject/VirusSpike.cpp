#include "VirusSpike.h"

VirusSpike::VirusSpike(float x, float y, int blood, float radius) :Virus(x, y, Virus::VirusType::SpikeVirus, blood, radius)
{
    // VirusSpike类的构造函数，调用基类Virus的构造函数进行初始化
    // 参数x和y为初始位置坐标
    // 参数blood为初始血量
    // 参数radius为病毒半径
}

void VirusSpike::updateVXY(float &vx, float &vy)
{
    // 更新病毒的速度（vx和vy）

    Virus::updateVXY(vx, vy); // 调用基类Virus的updateVXY函数，更新速度

    vx += (rand() % 3 - 1) / 500.0; // 根据随机值调整病毒的水平速度vx

    bool back = false;
    if (rand() % 5 > 3)
        back = true;

    if (vy <= 0 && back)
        vy += 0.1; // 当垂直速度vy小于等于0且随机条件满足时，增加垂直速度vy
    else if (vy > 0 && back)
        vy = 0.1; // 当垂直速度vy大于0且随机条件满足时，将垂直速度vy设为0.1
    else
    {
        vy = -(rand() % 9 - 1) / 5.0; // 随机生成一个垂直速度vy
        if (vy > 0)
            vy = 0; // 如果垂直速度vy大于0，则将其设为0
    }
}
