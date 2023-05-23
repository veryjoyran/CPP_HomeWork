#pragma once
#include <list>
#include <QPoint>
#include <QPixmap>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QOpenGLTexture>
#include "Object.h"
#include "Bullet.h"

class Virus : public Object
{
public:
    enum VirusType { SimpleVirus, SwellVirus, DefensiveVirus, SpikeVirus }; // 病毒类型枚举
    enum VirusColor { Purple, Cyan, Yellow, Pink, Blue, Green, Red, DarkPurple, DarkBlue }; // 病毒颜色枚举

    Virus(float x = 0, float y = 1, VirusType virusType = SimpleVirus, int blood = 10, float radius = 0.1); // 构造函数
    virtual void updatePos(); // 更新位置
    virtual void updateVXY(float& vx, float& vy); // 更新速度
    virtual void onAttacked(const Bullet& bullet); // 受到攻击时的处理
    int getRotation(); // 获取旋转角度
    int getColor(); // 获取颜色
    int getType(); // 获取类型
    int getBlood(); // 获取血量
    bool destroyed; // 是否被销毁
    float bombIndex; // 爆炸指数

private:
    float vx; // x轴速度
    float vy; // y轴速度
    int rotation; // 旋转角度
    float rOnAttacked; // 被攻击时的半径
    float rOnNormal; // 正常状态下的半径
    int blood; // 血量
    VirusType virusType; // 病毒类型
    VirusColor virusColor; // 病毒颜色
};
