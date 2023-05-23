#pragma once
#include <list>
#include <QPoint>
#include <QPixmap>
#include <QPainter>
#include <QMouseEvent>
#include "Object.h"
#include "Bullet.h"
class Cell: public Object, QObject
{
public slots:
    void speedBuff();//发射子弹间隔
    void shootBuff();//发射子弹数量
    void attackBuff();//子弹杀伤力
    void friendBuff();//召唤僚机
    void cancelSpeedBuff();//发射子弹间隔
    void cancelShootBuff();//发射子弹数量
    void cancelAttackBuff();//子弹杀伤力
    void cancelFriendBuff();//召唤僚机
public:
    enum Buff{SpeedBuff, ShootBuff, AttackBuff, FriendBuff};  // 增益类型枚举

    Cell(float x = 0, float y = -0.8, float radius = 0.15, int interval = 100, int onceNum = 5, int attack = 1);
    // 构造函数用于创建细胞对象

    void shoot();                  // 发射子弹
    void updatePos();              // 更新细胞位置的函数
    void mouseMoveEvent(QMouseEvent* E);    // 鼠标移动事件处理函数
    void keyPressEvent(QKeyEvent* E);       // 键盘按下事件处理函数
    void keyReleaseEvent(QKeyEvent* E);     // 键盘释放事件处理函数

    std::list<Bullet> cBullets;    // 存储细胞发射的子弹对象

public:
    float friendX;                 // 僚机的 X 坐标
    float friendY;                 // 僚机的 Y 坐标
    bool fightWithFriend;          // 是否和僚机一起作战
    bool gameWin;                  // 是否获得游戏胜利
    bool friengAtLeft;             // 僚机是否在左侧

private:
    int interval;                  // 发射子弹的间隔时间（毫秒）
    int onceNum;                   // 单次发射的子弹数量
    int attack;                    // 子弹的攻击力
    int blood;                     // 细胞的血量
    QPixmap friendImg;             // 僚机的图片
};

