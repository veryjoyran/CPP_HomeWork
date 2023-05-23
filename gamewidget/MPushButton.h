#ifndef MPUSHBUTTON_H
#define MPUSHBUTTON_H
#include <QPushButton>


/*
MPushButton相比于QBushButton新添加的功能
构造函数：MPushButton添加了一个自定义的构造函数，可以接受正常显示图片路径和按下后显示图片路径作为参数，并提供了设置按钮宽度和高度的可选参数。

缩放效果：MPushButton定义了两个成员函数zoom1()和zoom2()，用于实现按钮的缩放效果。这是MPushButton特有的功能。

成员属性：MPushButton添加了两个成员属性normalImgPath和pressImgPath，用于保存用户传入的默认图片路径和按下后的图片路径。
*/
class MPushButton:public QPushButton
{
    Q_OBJECT
public:
    //构造函数 参数1正常显示的图片路径 参数2按下后显示的图片路径
    MPushButton(QString normalImg="", QString pressImg = "",int width=20,int height=20);

    void zoom1();

    void zoom2();

    //成员属性 保存用户传入的默认图片路径 和 按下后的路径
    QString normalImgPath;

    QString pressImgPath;

    ~MPushButton();
signals:

public slots:
};

#endif // MPUSHBUTTON_H


