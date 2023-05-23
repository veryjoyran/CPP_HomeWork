#ifndef FILESAVESCENE_H
#define FILESAVESCENE_H

#include <QWidget>
#include <QVBoxLayout>

namespace Ui
{
class FileSaveScene;
}

class FileSaveScene : public QWidget
{
    Q_OBJECT

public:
    explicit FileSaveScene(QWidget *parent = nullptr);  // 构造函数，可指定父窗口
    ~FileSaveScene();  // 析构函数

private:
    Ui::FileSaveScene* ui;  // 用户界面指针
    QVBoxLayout* layout;  // 垂直布局指针
};

#endif // FILESAVESCENE_H
