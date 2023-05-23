#include "Cell.h"
#include <QTimer>
#include <QDateTime>
#include "gameconfig/Config.h"
//发射子弹间隔
void Cell::speedBuff()
{
    interval /= 2;
}
//发射子弹数量
void Cell::shootBuff()
{
    onceNum *= 2;
}
//子弹杀伤力
void Cell::attackBuff()
{
    attack *= 2;
    qDebug()<<"attack="<<attack;
}

//召唤僚机
void Cell::friendBuff()
{
    fightWithFriend = true;
}

//发射子弹间隔
void Cell::cancelSpeedBuff()
{
    interval *= 2;
}

//发射子弹数量
void Cell::cancelShootBuff()
{
    onceNum /= 2;
    qDebug()<<"cancel oncenum="<<onceNum;
}

//子弹杀伤力
void Cell::cancelAttackBuff()
{
    attack/=2;
    qDebug()<<"attack="<<attack;
}

//召唤僚机
void Cell::cancelFriendBuff()
{
    fightWithFriend = false;
}

//构造
Cell::Cell(float x,float y,float radius,int interval,int onceNum,int attack) :Object(x, y, radius), interval(interval), onceNum(onceNum), attack(attack)
{
    friendX = 0;
    friendY = -1.5;
    fightWithFriend = false;
    gameWin=false;
}

 // 更新细胞位置的函数
void Cell::updatePos()
{
    // 如果游戏胜利，向上移动细胞和僚机的位置
    if (gameWin) {
        openglY += 0.05f;
        if (fightWithFriend) friendY += 0.05f;
    }

    // 如果与僚机战斗
    if (fightWithFriend) {
        // 根据僚机和细胞的位置关系，确定僚机是否在细胞的左侧
        if (friendX - openglX > 0)
            friengAtLeft = false;
        else
            friengAtLeft = true;

        // 当僚机与细胞的水平距离超过细胞半径的两倍时，进行平滑移动
        if (friendX - openglX > getOpenglR() * 2) {
            friendX += (openglX - friendX + getOpenglR() * 2) / 5;
        }
        else if (friendX - openglX < -getOpenglR() * 2) {
            friendX += (openglX - friendX - getOpenglR() * 2) / 5;
        }

        // 使用线性插值方式平滑移动僚机的纵向位置
        friendY += (openglY - friendY) / 10.0;
    }
    // 如果不与僚机战斗且僚机的纵向位置高于 -1.5
    else if (friendY > -1.5) {
        // 向下移动僚机的纵向位置
        friendY += -0.01f;
    }
}


void Cell::mouseMoveEvent(QMouseEvent* E)
{
    int ex = E->x();
    int ey = E->y();
    if (ex > 0 && ex < Config::getW())
        setOpenglX(Config::mapping(ex,0, Config::getW(),-1,1)+openglR);
    if (ey > 0 && ey < Config::getH())
        setOpenglY(Config::mapping(ey,0, Config::getH(),1,-1)+openglR);
}

QTimer keyTimer;
void Cell::keyPressEvent(QKeyEvent *E)
{
    if(!E->isAutoRepeat()){
        keyTimer.setInterval(10);
        float step=0.03f;
        switch(E->key()){
        case Qt::Key_W:
            connect(&keyTimer,&QTimer::timeout,this,[=]{openglY+=step;});
            break;
        case Qt::Key_S:
            connect(&keyTimer,&QTimer::timeout,this,[=]{openglY-=step;});
            break;
        case Qt::Key_A:
            connect(&keyTimer,&QTimer::timeout,this,[=]{openglX-=step;});
            break;
        case Qt::Key_D:
            connect(&keyTimer,&QTimer::timeout,this,[=]{openglX+=step;});
            break;
        }
        keyTimer.start();
    }
}

void Cell::keyReleaseEvent(QKeyEvent *E)
{
    if(!E->isAutoRepeat()){
        keyTimer.stop();
        disconnect(&keyTimer, 0, 0, 0);
    }
}

// 发射子弹
void Cell::shoot()
{
    static int lastTime = 0;       // 上次发射子弹的时间
    static float shootNum = 1;     // 当前发射的子弹数量

    if ((int)shootNum < (int)onceNum)
        shootNum += 0.05f;          // 增加发射子弹数量
    else if ((int)shootNum > (int)onceNum)
        shootNum -= 0.05f;          // 减少发射子弹数量

    int t = Config::getMills();     // 获取当前时间

    qDebug() << "lasttime=" << lastTime << " " << "t=" << t;

    if (lastTime > 0 && (t - lastTime) < interval) {
        return;                     // 若未到发射间隔时间，则退出函数
    }

    lastTime = t;                   // 更新上次发射时间

    float firstBulletX;
    float bulletInterval = 0.05f;

    if ((int)shootNum % 2 == 0)
        firstBulletX = openglX - ((int)shootNum + 1) / 2 * bulletInterval - bulletInterval / 2;
    else
        firstBulletX = openglX - ((int)shootNum + 1) / 2 * bulletInterval;

    for (int i = 0; i < (int)shootNum; i++) {
        float x = firstBulletX += bulletInterval;

        // 若与僚机一起作战，则在细胞和僚机之间发射子弹
        if (fightWithFriend)
            cBullets.push_back(Bullet(x + friendX - this->openglX, friendY - 0.01, attack));

        // 在细胞位置发射子弹
        if (x < -1)
            continue;               // 若子弹超出屏幕范围，则跳过该子弹
        cBullets.push_back(Bullet(x, openglY - 0.01, attack));
    }
}
