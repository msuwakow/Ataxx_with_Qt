#include "level.h"

std::pair<int, QString> LEVEL::findLevel(int rating) {
    std::pair<int, QString> ret;
    for (int i = 0; i < level.size(); ++i) {
        if (rating >= level[i].first)
            ret.first = i, ret.second = level[i].second;
    }
    return ret;
}
