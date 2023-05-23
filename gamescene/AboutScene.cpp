#include "AboutScene.h"
#include "ui_aboutscene.h"
#include <QPixmap>
#include <QPalette>

AboutScene::AboutScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AboutScene)
{
    ui->setupUi(this);

    // 设置对象在关闭时自动删除
    setAttribute(Qt::WA_DeleteOnClose);

    // 访问并操作界面元素
    ui->label_5->setText("<html><head/><body><p align=\"center\"><span style=\" font-size:22pt; font-weight:700; color:#ff0000;\">关于游戏</span></p></body></html>");
    ui->label_2->setText("<html><head/><body><p><span style=\" font-size:20pt; font-weight:700; font-style:italic; color:#ffaa7f;\">1.开发成员：LQR&WZY</span></p></body></html>");
    ui->label_4->setText("<html><head/><body><p><span style=\" font-size:18pt; font-weight:700; font-style:italic; color:#ffaa7f;\">2.各种病毒、buff以及鲨鱼图片使用PS软件,以及从必应搜索获得</span></p><p><span style=\" font-size:16pt; font-weight:700; color:#0055ff;\">3.本游戏前8关并未设置过大难度，而是有一个基本的剧情体验，</span></p><p><span style=\" font-size:16pt; font-weight:700; color:#0055ff;\">前8关如果感觉难度过大，可以将饥饿鲨放在最下面（屏幕外），</span></p><p><span style=\" font-size:16pt; font-weight:700; color:#0055ff;\">这样病毒就不会触碰到飞机，可以当成一个简单的消除游戏，好戏从</span></p><p><span style=\" font-size:16pt; font-weight:700; color:#0055ff;\">无尽模式开始。</span></p></body></html>");
    ui->label_3->setText("<html><head/><body><p><span style=\" font-size:12pt; color:#ffffff;\">4.背景简介：地球在经历第三次世界大战后，满目疮痍。在这场战争中，大量核武器的使用使得很多</span></p><p><span style=\" font-size:12pt; color:#ffffff;\">人类的基因产生了变化。而这时，万恶的WoLaLa大魔王从宇宙深处来袭，准备一举拿下地球。不过</span></p><p><span style=\" font-size:12pt; color:#ffffff;\">WoLaLa大魔王生性胆小，不敢亲自进攻，于是它准备不断的向地球投放病毒使人类灭绝，最终一举</span></p><p><span style=\" font-size:12pt; color:#ffffff;\">拿下地球，侵占地球上的所有资源。不过，在基因产生的变化的人群中，有这样一群人，他们的基因</span></p><p><span style=\" font-size:12pt; color:#ffffff;\">与鲨鱼融合，身体产生了极大变化。而在与外星人的抗争中，人们发现这种鲨鱼人发射的光波在击败病</span></p><p><span style=\" font-size:12pt; color:#ffffff;\">毒后，可以吞噬外星人投放的病毒，并且他们的胃口巨大无比，故而被人类称为饥饿鲨。</span></p><p><span style=\" font-size:12pt; color:#ffffff;\">而你现在就是一只饥饿鲨，去吞噬所有的病毒，为人类的命运而战吧！！！</span></p></body></html>");

    // 设置背景
    QPalette pal;
    QPixmap pixmap(":/img/images/bg1.png");  // 加载背景图像
    pal.setBrush(this->backgroundRole(), QBrush(pixmap));  // 将背景图像作为窗口背景
    setPalette(pal);
}


AboutScene::~AboutScene()
{
    delete ui;
}
