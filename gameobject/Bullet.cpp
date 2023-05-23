#include "Bullet.h"

Bullet::Bullet(float openglX,float openglY, int attack, float speed,float openglW,float openglH):Object(openglX,openglY,openglW,openglH), speed(speed),  attack(attack)
{
}
  // 更新子弹位置
void Bullet::updatePos() {
    openglY += speed;
    if (openglX < -1)openglX = -openglX;
}
 // 获取子弹的攻击力
int Bullet::getAttack()const
{
    return attack;
}
