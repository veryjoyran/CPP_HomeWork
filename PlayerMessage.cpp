#include "PlayerMessage.h"

//初始化
PlayerMessage::PlayerMessage(QString nickname):nickname(nickname)
{

}

//获取玩家昵称
QString PlayerMessage::getNickname()
{
    return nickname;
}


//设置玩家通关数
void PlayerMessage::setProgress(int progress)
{
    this->progress=progress;
}

//获取玩家通关数
int PlayerMessage::getProgress()
{
    return progress;
}

//从文件读取
std::ifstream& operator>>(std::ifstream& is, PlayerMessage& pmsg)
{
    int version;
    std::string temp;

    // 检查输入流是否有效
    if (!is)
        return is;


    is >> temp;

    if (temp != "version")
        return is;

    is >> version;

    // 循环读取数据直到流结束
    while (is)
    {
        is >> temp;

        // 根据关键字进行数据读取
        if (temp == "nickname")
        {
            // 读取昵称并转换为QString类型
            is >> temp;
            pmsg.nickname = QString::fromUtf8(temp);
        }
        else if (temp == "progress")
        {
            // 读取进度
            is >> pmsg.progress;
        }
    }

    return is;
}


//写入文件
std::ofstream& operator<<(std::ofstream& os, PlayerMessage& pmsg)
{
    std::string temp;

    // 检查输出流是否有效
    if (!os)
        return os;

    // 写入版本信息
    os << "version" << " " << "01" << std::endl;

    // 写入昵称
    os << "nickname" << " " << pmsg.nickname.toUtf8().data() << std::endl;

    // 写入进度
    os << "progress" << " " << pmsg.progress << std::endl;

    return os;
}
