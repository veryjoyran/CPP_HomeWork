#include <QtWidgets/QApplication>
#include <QFile>
#include <QIcon>
#include <thread>
#include "gamescene/GameScene.h"
#include "gamescene/FileSaveScene.h"
#include "gameobject/ResourceEngine.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setWindowIcon(QIcon(":img/images/icon.png"));
    // 设置应用程序的窗口图标为指定的图标文件

    // 设置全局样式表
    QFile file(":qss/style/global.qss");
    file.open(QFile::ReadOnly);
    if (file.isOpen())
    {
        QString styleSheet = (file.readAll()); // 读取样式表文件的内容
        a.setStyleSheet(styleSheet); // 将样式表应用到应用程序
        file.close();
    }

    /*
    原本根据教程使用了多线程以达到加快程序执行速度、提高响应性和资源利用率的目的，但是在
多线程的使用中会经常抛出底层异常，然后某个线程错误，因此改为了单线程，不过仍然存在部分错误
     std::thread initThread([=]{
        ResourceEngine::initRes();
    });
    initThread.detach();




    */

     ResourceEngine::initRes();
    // 创建并显示存档界面
    (new FileSaveScene())->show();

    return a.exec();
}
