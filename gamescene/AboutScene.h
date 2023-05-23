#ifndef ABOUTSCENE_H
#define ABOUTSCENE_H

#include <QWidget>

namespace Ui
{
class AboutScene;
}

class AboutScene : public QWidget
{
    Q_OBJECT

public:
    explicit AboutScene(QWidget *parent = nullptr);  // 构造函数，可指定父窗口
    ~AboutScene();  // 析构函数

private:
    Ui::AboutScene *ui;  // 用户界面指针
};

#endif // ABOUTSCENE_H
