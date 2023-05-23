#pragma once

#include <QLabel>
//实现了一个具有自定义绘制外观、显示文本、设置进度值的进度条控件。
class RProgressBar : public QLabel
{
public:
    explicit RProgressBar(QWidget* parent = nullptr); // 构造函数

    void paintEvent(QPaintEvent*); // 重写绘制事件函数
    void setText(QString text); // 设置显示的文本
    void setImg(QPixmap img); // 设置进度条的图片
    void setProgress(int progress); // 设置当前的进度值
    void setMaxProgress(int max); // 设置进度条的最大值

private:
    int maxProgress; // 进度条的最大值
    int progress; // 当前进度值
    QPixmap bg; // 进度条的背景图片
    QPixmap img; // 进度条的图片
    QString text; // 显示的文本
    QList<QPointF> points; // 进度曲线的顶点数组
};
