#include "VirusDefensive.h"

VirusDefensive::VirusDefensive(float x, float y, int blood, float radius):Virus(x, y, Virus::VirusType::DefensiveVirus, blood*2, radius)
{
    // VirusDefensive类的构造函数，调用基类Virus的构造函数进行初始化
    // 参数x和y为初始位置坐标
    // 参数blood为初始血量
    // 参数radius为病毒半径
    // 将病毒类型设置为DefensiveVirus，血量乘以2以增加防御能力
}

void VirusDefensive::updateVXY(float &vx, float &vy)
{
    // 更新病毒的速度（vx和vy）

    Virus::updateVXY(vx, vy); // 调用基类Virus的updateVXY函数，更新速度
}

