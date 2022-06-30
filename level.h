#ifndef LEVEL_H
#define LEVEL_H

#include <QVector>
#include <utility>
#include <QString>

namespace LEVEL {

const QVector<std::pair<int, QString>> level = {
    std::make_pair(0, QString("newbie")),
    std::make_pair(1200, QString("pupil")),
    std::make_pair(1400, QString("specialist")),
    std::make_pair(1600, QString("expert")),
    std::make_pair(1900, QString("candidate master")),
    std::make_pair(2100, QString("master")),
    std::make_pair(2300, QString("international master")),
    std::make_pair(2400, QString("grandmaster")),
    std::make_pair(2600, QString("international grandmaster")),
    std::make_pair(3000, QString("legendary grandmaster"))
};

std::pair<int, QString> findLevel(int rating);

}

#endif // LEVEL_H
