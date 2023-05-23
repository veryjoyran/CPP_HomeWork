#ifndef VIRUSSWELL_H
#define VIRUSSWELL_H

#include "Virus.h"

class VirusSwell : public Virus
{
public:
    VirusSwell(float x, float y, int blood, float radius); // 构造函数
    void updateVXY(float& vx, float& vy); //改变大小从而实现膨胀的效果
};

#endif // VIRUSSWELL_H
