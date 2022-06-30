#ifndef FILE_H
#define FILE_H

#include <QList>
#include <QDir>
#include "gamestate.h"

class File {

public:
    // 找到存档文件所在的文件夹，如果没有就创建
    // 如果创建失败就紫砂（assert)
    QDir getSavedataPath();
    // 读取所有人的数据
    QVector<GameState> readAllProfiles();
    // 读取特定用户的数据
    GameState readSingleProfile(QString);
    // 将特定用户的数据写入存档
    void writeSingleProfile(GameState);
};

extern File IO;

#endif // FILE_H
