#ifndef ResourceEngine_H
#define ResourceEngine_H

#include <QString>
#include <QImage>
#include <map>

class ResourceEngine
{
public:
    ResourceEngine(); // 构造函数

    static void initRes(); // 初始化资源
    static const QImage& getRes(QString name); // 获取资源图像

private:
    static std::map<QString, QImage> imgMap; // 图像资源映射表，用于存储图像资源
};

#endif // ResourceEngine_H
