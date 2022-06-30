#include "file.h"
#include "gamestate.h"

#include <QVector>
#include <QDir>
#include <QCoreApplication>
#include <QDebug>
#include <cassert>
#include <QString>

QDir File::getSavedataPath() {
    QString path(QCoreApplication::applicationDirPath());
    QDir dir(path);

    assert(dir.exists());

    path.append("/savedata");
    dir.setPath(path);
    if (dir.exists() == 0) {
        dir.mkdir(path);
    }

    assert(dir.exists());
    return dir;
}

QVector<GameState> File::readAllProfiles() {
    QDir dir = getSavedataPath();
    dir.setFilter(QDir::Files);
    QFileInfoList infoList = dir.entryInfoList();
    QVector<GameState> ret;
    for (auto &v : infoList) {
        QString suffix = v.suffix();
        if (QString::compare(suffix, QString("sav"), Qt::CaseInsensitive) == 0) {
            GameState tmp;
            FILE *f = fopen(v.absoluteFilePath().toStdString().c_str(), "rb");
            tmp.Read(f);
            ret.push_back(tmp);
            fclose(f);
        }
    }
    return ret;
}

GameState File::readSingleProfile(QString username) {
    QDir dir = getSavedataPath();
    dir.setFilter(QDir::Files);
    QFileInfoList infoList = dir.entryInfoList();
    for (auto &v : infoList) {
        QString suffix = v.suffix();
        QString base = v.baseName();
        if (QString::compare(suffix, QString("sav"), Qt::CaseInsensitive) == 0 &&
            QString::compare(base, username, Qt::CaseSensitive) == 0) {
            GameState ret;
            FILE *f = fopen(v.absoluteFilePath().toStdString().c_str(), "rb");
            ret.Read(f);
            fclose(f);
            return ret;
        }
    }
    return GameState();
}

void File::writeSingleProfile(GameState x) {
    if (x.username == "") return;
    QDir dir = getSavedataPath();
    FILE *f = fopen((dir.absolutePath().toStdString() + "/" + x.username + ".sav").c_str(), "wb");
    x.Write(f);
    fclose(f);
    return;
}

File IO;
