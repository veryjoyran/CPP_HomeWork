#include "StageData.h"
#include "gameobject/Cell.h"
#include "gameobject/Virus.h"
#include "gameobject/VirusDefensive.h"
#include "gameobject/VirusSpike.h"
#include "gameobject/VirusSwell.h"
#include "gameobject/Material.h"

//初始化
GStageData::GStageData()
{
    void tempStage01(GStageData& gsdata,int which);
    tempStage01(*this,6);
    it=messages.begin();
    setAll();
    at=0;
}

GStageData::GStageData(int stage)
{
    void tempStage01(GStageData& gsdata,int which);
    tempStage01(*this,stage);
    it=messages.begin();
    setAll();
    at=0;
    this->stage=stage;
}

int interval=500;
//根据参数which的不同决定不同的逻辑
void tempStage01(GStageData& gsdata,int which){
    switch(which){
    case 0:
        // 第一阶段，生成病毒和物品
        for(int i=1;i<=900;i++){
            int timeControl = 1000 - i*2;// 根据循环计算时间控制值
            srand(time(NULL)+i);// 根据循环值设置随机数种子，确保每次生成的随机数不同
            switch(rand()%5){// 生成一个随机数并根据余数进行分支选择
                 // 生成普通病毒，并将其添加到 gsdata 中
            case 0:
                gsdata<<Message(interval*i+timeControl,new Virus((rand()%21-10)/10.0,1.1f,Virus::VirusType(0),10+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
                // 生成膨胀病毒，并将其添加到 gsdata 中
            case 1:
                gsdata<<Message(interval*i+timeControl,new VirusSwell((rand()%21-10)/10.0,1.1f,10+i+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
                // 生成尖刺病毒，并将其添加到 gsdata 中
            case 2:
                gsdata<<Message(interval*i+timeControl,new VirusSpike((rand()%21-10)/10.0,1.1f,10+i+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
                // 生成防御病毒，并将其添加到 gsdata 中
            case 3:
                gsdata<<Message(interval*i+timeControl,new VirusDefensive((rand()%21-10)/10.0,1.1f,10+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
                //同case 3
            case 4:
                gsdata<<Message(interval*i+timeControl,new VirusDefensive((rand()%21-10)/10.0,1.1f,10+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            }
        }

        for(int i=1;i<=600;i++){
            srand(time(NULL)+i);
            if(rand()%15==0) // 生成物品（材料），并将其添加到 gsdata 中
                gsdata<<Message(interval*i/2+3000-i,new Material(),Message::DROPBUFF);
        }
        //添加提示信息
        gsdata<<Message(1000,"指挥中心：无尽模式", Message::TIP);
        gsdata<<Message(3000,"", Message::TIP);

        //添加游戏内容中的警告信息

        for(int i=0;i<10;i++){
            if(i%2==0){
                Message msg0(900*i+10000,"大量病毒入侵！", Message::WARN);
                gsdata<<msg0;
            }
            else{
                Message msg0(900*i+10000,"", Message::WARN);
                gsdata<<msg0;
            }
        }
    //对生成的信息进行排序
        gsdata.sort();


        break;

    case 01:
        // 第二阶段，生成病毒和提示信息
        for(int i=1;i<=30;i++){
            srand(time(NULL)+i);
            // 生成病毒，并将其添加到 gsdata 中
            Virus* v=new Virus((rand()%21-10)/10.0,1.1f,Virus::VirusType(0),10+rand()%30,0.1f+rand()%20/100.);
            gsdata<<Message(500*i,v,Message::VIRUS);
        }
        gsdata<<Message(1000,"指挥中心：你好，新出生的保卫细胞", Message::TIP);
        gsdata<<Message(2000,"指挥中心：守护这里是你的使命", Message::TIP);
        gsdata<<Message(3000,"指挥中心：现在，为了这个身体......", Message::TIP);
        gsdata<<Message(4000,"指挥中心：不顾一切地！！！", Message::TIP);
        gsdata<<Message(5000,"指挥中心：前进吧！！！", Message::TIP);
        gsdata<<Message(7000,"", Message::TIP);
        gsdata.sort();
        break;

    case 02:
        for(int i=1;i<=50;i++){
            srand(time(NULL)+i);
            switch(rand()%3){
            case 0:
                gsdata<<Message(500*i,new Virus((rand()%21-10)/10.0,1.1f,Virus::VirusType(0),10+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 1:break;
            case 2:
                gsdata<<Message(500*i,new VirusSwell((rand()%21-10)/10.0,1.1f,10+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            }
        }
        gsdata<<Message(500,"指挥中心：发现了膨胀病毒", Message::TIP);
        gsdata<<Message(1500,"指挥中心：请注意防范", Message::TIP);
        gsdata<<Message(3500,"", Message::TIP);
        gsdata.sort();
        break;
    case 03:
        for(int i=1;i<=50;i++){
            srand(time(NULL) + i);
            switch(rand()%4){
            case 0:
                gsdata<<Message(500*i,new Virus((rand()%21-10)/10.0,1.1f,Virus::VirusType(0),10+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 1:
                gsdata<<Message(500*i,new VirusSwell((rand()%21-10)/10.0,1.1f,10+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 2:
            case 3:
                gsdata<<Message(800*i,new VirusSpike((rand()%21-10)/10.0,1.1f,10+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            }
        }
        gsdata<<Message(500,"指挥中心：发现了变速病毒", Message::TIP);
        gsdata<<Message(1500,"指挥中心：请注意防范", Message::TIP);
        gsdata<<Message(3500,"", Message::TIP);
        gsdata.sort();
        break;
    case 04:
        for(int i=1;i<=40;i++){
            srand(time(NULL)+i);
            switch(rand()%5){
            case 0:
                gsdata<<Message(800*i,new Virus((rand()%21-10)/10.0,1.1f,Virus::VirusType(0),10+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 1:
                gsdata<<Message(800*i,new VirusSwell((rand()%21-10)/10.0,1.1f,10+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 2:
                gsdata<<Message(800*i,new VirusSpike((rand()%21-10)/10.0,1.1f,10+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 3:
            case 4:
                gsdata<<Message(800*i,new VirusDefensive((rand()%21-10)/10.0,1.1f,10+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            }
        }
        gsdata<<Message(500,"指挥中心：发现了防御病毒", Message::TIP);
        gsdata<<Message(1500,"指挥中心：请注意防范", Message::TIP);
        gsdata<<Message(3500,"", Message::TIP);
        gsdata.sort();
        break;
    case 05:
        for(int i=1;i<=10;i++){
            srand(time(NULL)+i);
            switch(rand()%4){
            case 0:
                gsdata<<Message(1000*i,new Virus((rand()%21-10)/10.0,1.1f,Virus::VirusType(0),10+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 1:
                gsdata<<Message(1000*i,new VirusSwell((rand()%21-10)/10.0,1.1f,10+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 2:
                gsdata<<Message(1000*i,new VirusSpike((rand()%21-10)/10.0,1.1f,10+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 3:
                gsdata<<Message(1000*i,new VirusDefensive((rand()%21-10)/10.0,1.1f,10+rand()%30,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            }
        }
        for(int i=0;i<6;i++){
            if(i%2==0){
                Message msg0(500*i+5000,"大量病毒入侵！", Message::WARN);
                gsdata<<msg0;
            }
            else{
                Message msg0(500*i+5000,"", Message::WARN);
                gsdata<<msg0;
            }
        }
        for(int i=1;i<=40;i++){
            srand(time(NULL)+i);
            switch(rand()%5){
            case 0:
                gsdata<<Message(8000+300*i,new Virus((rand()%21-10)/10.0,1.1f,Virus::VirusType(0),10+rand()%20,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 1:
                gsdata<<Message(8000+300*i,new VirusSwell((rand()%21-10)/10.0,1.1f,10+rand()%20,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 2:
                gsdata<<Message(8000+300*i,new VirusSpike((rand()%21-10)/10.0,1.1f,10+rand()%20,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 3:
            case 4:
                gsdata<<Message(8000+300*i,new VirusDefensive((rand()%21-10)/10.0,1.1f,10+rand()%40,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            }
        }
        gsdata<<Message(10000,"指挥中心：病毒越来越多了，\n"
                             "试试升级后的弹药吧", Message::TIP);
        gsdata<<Message(13000,"", Message::TIP);
        gsdata<<Message(12000,Cell::Buff::ShootBuff);
        //gsdata<<Message(12000,Cell::Buff::SpeedBuff);
        gsdata.sort();
        break;
    case 06:
        for(int i=0;i<6;i++){
            if(i%2==0){
                Message msg0(1000+500*i,"大量病毒入侵！", Message::WARN);
                gsdata<<msg0;
            }
            else{
                Message msg0(1000+500*i,"", Message::WARN);
                gsdata<<msg0;
            }
        }
        for(int i=1;i<=120;i++){
            srand(time(NULL)+i);
            switch(rand()%5){
            case 0:
                gsdata<<Message(300*i,new Virus((rand()%21-10)/10.0,1.1f,Virus::VirusType(0),10+rand()%20,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 1:
                gsdata<<Message(300*i,new VirusSwell((rand()%21-10)/10.0,1.1f,10+rand()%20,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 2:
                gsdata<<Message(300*i,new VirusSpike((rand()%21-10)/10.0,1.1f,10+rand()%20,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 3:
            case 4:
                gsdata<<Message(300*i,new VirusDefensive((rand()%21-10)/10.0,1.1f,10+rand()%40,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            }
        }
        gsdata<<Message(10,"指挥中心：为你提高了弹药杀伤力", Message::TIP);
        gsdata<<Message(2000,"", Message::TIP);
        gsdata<<Message(0,Cell::Buff::ShootBuff);
        gsdata<<Message(0,Cell::Buff::AttackBuff);
        gsdata.sort();
        break;
    case 07:
        for(int i=0;i<6;i++){
            if(i%2==0){
                Message msg0(1000+500*i,"大量病毒入侵！", Message::WARN);
                gsdata<<msg0;
            }
            else{
                Message msg0(1000+500*i,"", Message::WARN);
                gsdata<<msg0;
            }
        }
        for(int i=1;i<=250;i++){
            srand(time(NULL)+i);
            switch(rand()%5){
            case 0:
                gsdata<<Message(200*i,new Virus((rand()%21-10)/10.0,1.1f,Virus::VirusType(0),10+rand()%20,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 1:
                gsdata<<Message(200*i,new VirusSwell((rand()%21-10)/10.0,1.1f,10+rand()%20,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 2:
                gsdata<<Message(200*i,new VirusSpike((rand()%21-10)/10.0,1.1f,10+rand()%20,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 3:
            case 4:
                gsdata<<Message(200*i,new VirusDefensive((rand()%21-10)/10.0,1.1f,10+rand()%40,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            }
        }
        gsdata<<Message(0,Cell::Buff::ShootBuff);
        gsdata<<Message(0,Cell::Buff::AttackBuff);
        gsdata<<Message(3000,"未知的声音:要顶不住了吗？", Message::TIP);
        gsdata<<Message(4000,"未知的声音:我来帮你！", Message::TIP);
        gsdata<<Message(5000,"", Message::TIP);
        gsdata<<Message(5000,Cell::Buff::FriendBuff);
        gsdata.sort();
        break;
    case 8:
        for(int i=0;i<6;i++){
            if(i%2==0){
                Message msg0(500*i+10000,"大量病毒入侵！", Message::WARN);
                gsdata<<msg0;
            }
            else{
                Message msg0(500*i+10000,"", Message::WARN);
                gsdata<<msg0;
            }
        }
        for(int i=1;i<=120;i++){
            srand(time(NULL)+i);
            switch(rand()%4){
            case 0:
                gsdata<<Message(500*i,new Virus((rand()%21-10)/10.0,1.1f,Virus::VirusType(0),rand()%10,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 1:
                gsdata<<Message(500*i,new VirusDefensive((rand()%21-10)/10.0,1.1f,rand()%10,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 2:
                gsdata<<Message(500*i,new VirusSpike((rand()%21-10)/10.0,1.1f,rand()%10,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 3:
                gsdata<<Message(500*i,new VirusSwell((rand()%21-10)/10.0,1.1f,rand()%10,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            }
        }
        for(int i=1;i<=300;i++){
            srand(time(NULL)+i*i);
            switch(rand()%4){
            case 0:
                gsdata<<Message(500*i,new Virus((rand()%21-10)/10.0,1.1f,Virus::VirusType(0),rand()%10,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 1:
                gsdata<<Message(500*i,new VirusDefensive((rand()%21-10)/10.0,1.1f,rand()%10,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 2:
                gsdata<<Message(500*i,new VirusSpike((rand()%21-10)/10.0,1.1f,rand()%10,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            case 3:
                gsdata<<Message(500*i,new VirusSwell((rand()%21-10)/10.0,1.1f,rand()%10,0.1f+rand()%20/100.),Message::VIRUS);
                break;
            }
        }
        gsdata<<Message(3000,"???:要顶不住了吗？", Message::TIP);
        gsdata<<Message(4000,"???:我来帮你！", Message::TIP);
        gsdata<<Message(5000,"", Message::TIP);
        gsdata<<Message(6000,Cell::Buff::FriendBuff);
        gsdata.sort();
        break;
    }

}

//读取一条消息

bool GStageData::operator>>(Message &msg)
{
    if (it != messages.end()) // 如果迭代器没有到达消息列表的末尾
    {
        msg = *it; // 将迭代器指向的消息赋值给传入的消息对象
        it++;     // 将迭代器向后移动一位，指向下一个消息
        at++;     // 增加消息的计数器
        return true; // 返回操作成功的标志
    }
    else
    {
        return false; // 如果迭代器已经到达消息列表的末尾，表示没有更多的消息可供获取，返回操作失败的标志
    }
}

//向消息表加入消息
void GStageData::operator<<(const Message &msg)
{
    messages.push_back(msg); // 将传入的消息对象添加到消息列表的末尾
    all = messages.size();   // 更新消息的计数器
}


Message &GStageData::getMessage()
{
    return *it;
}
//将信息表迭代器下一一位，若已至列表尾部，返回false
bool GStageData::next()
{
    if((++it)!=messages.end()){
        return true;
    }
    else{
        it=messages.begin();
        return false;
    }
}

//获取Message表中类型为Virus的总数（即敌人总数）
int GStageData::getAllNum()
{
    return all;
}

//将所有Message按mills排序
void GStageData::sort()
{
    messages.sort([=](Message m1,Message m2){
        return m1.mills<m2.mills;
    });
}


//至少调用一次setAll之后才能调用下面的getAllNum
void GStageData::setAll()
{
    all=0;
    for(std::list<Message>::iterator it=messages.begin();it!=messages.end();it++)
        if(it->type==Message::VIRUS)
            ++all;
}


//获取关卡等级（第几关）
int GStageData::getStage()
{
    return stage;
}

//赋值
Message::Message(int mills, Object* pObject,MessageType type):mills(mills),pObject(pObject),type(type)
{
}

Message::Message(int mills, QString tip, MessageType type):mills(mills),tip(tip),type(type)
{
}

Message::Message(int mills, int buff):mills(mills),buff(buff),type(BUFF)
{
}


