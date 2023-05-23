#include <QDateTime>
#include <QDir>
#include <QStandardPaths>
#include <fstream>
#include "gameconfig/Config.h"
#include "gameobject/Object.h"

int Config::fps = 60;
int Config::WIDTH = 500;
int Config::HEIGHT = 700;
PlayerMessage* Config::playerMessage = nullptr;


// 帧率计数，应每绘制一帧调用一次
void Config::fpsCount()
{
    static long long lastTime = 0;
    static int count = 0;
    int interval = 500;
    long long t = Config::getMills();
    ++count;
    if (lastTime == 0) {
        lastTime = t;
        count = 0;
    } else if (lastTime > 0 && (t - lastTime) > interval) {
        int last = fps;
        fps = count * 1000 / (t - lastTime);
        if (abs(fps - last) <= 1)
            fps = last;
        count = 0;
        lastTime = t;
    }
}


// 窗口大小更改时调用，传入新的窗口宽高
void Config::updateWH(int w, int h)
{
    WIDTH = w;
    HEIGHT = h;
    Object::ey = static_cast<float>(h) / w;
}


// 获取当前存储的窗口宽度
int Config::getW()
{
    return WIDTH;
}

// 获取当前存储的窗口高度
int Config::getH()
{
    return HEIGHT;
}


// 获取当前帧率（根据调用fpsCount()的频率计算）
int Config::getFps()
{
    return fps;
}

 // 坐标映射
float Config::mapping(float v, float startOld, float endOld, float startNew, float endNew)
{
    float result = startNew + (v - startOld) * (endNew - startNew) / (endOld - startOld);
    return result;
}

 // 设置玩家信息
void Config::setPlayerMessage(PlayerMessage* playerMessage)
{
    if (Config::playerMessage != nullptr)
        delete Config::playerMessage;
    Config::playerMessage = playerMessage;
}

 // 获取玩家信息
PlayerMessage* Config::getPlayerMessage()
{
    return playerMessage;
}


//从文件初始化玩家信息
void Config::initPlayerMessage(QString nickname)
{
    qDebug() << "path=" << (QString(getDataFileDir()) + nickname);
    std::ifstream is((QString(getDataFileDir()) + "/" + nickname).toLocal8Bit().data(), std::ios::binary);
    PlayerMessage* pmsg = new PlayerMessage("");
    is >> *pmsg;
    setPlayerMessage(pmsg);
    is.close();
}

//储存玩家信息到文件
void Config::savePlayerMessage()
{
    qDebug() << "nickname=" << playerMessage->getNickname();
    QString path = getDataFileDir() + "/" + playerMessage->getNickname() + ".p";
    // 判断文件夹是否存在，不存在则创建
    QDir dir(getDataFileDir());
    qDebug() << "PATH=" << dir.absolutePath();
    if (!dir.exists()) {
        bool ismkdir = dir.mkpath(".");
        if (!ismkdir)
            qDebug() << "Create path fail";
        else
            qDebug() << "Create fullpath success";
    } else {
        qDebug() << "fullpath exist";
    }

    std::ofstream os(path.toLocal8Bit().data(), std::ios::binary);//path.toLocal8Bit().data()转换为C风格，std::ios::binary以二进制模式打开文件
    if (!os)
        qDebug() << "error";
    os << *playerMessage;
    os.close();
    qDebug() << "SAVE" << path;
}

// 获取文件存储路径（结尾不含"/"）
QString Config::getDataFileDir()
{
#ifdef Q_OS_ANDROID
    return QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
#else
    return QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/消灭病毒/";
#endif
}


// 获取时间戳，即当前的毫秒数
int Config::getMills()
{
    return QDateTime::currentMSecsSinceEpoch() % 1000000000;
}
