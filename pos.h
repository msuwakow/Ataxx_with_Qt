#ifndef _ATAXX_POS_H_
#define _ATAXX_POS_H_

#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <utility>

namespace Pos
{
    // 不用 extern 会报错 redefinition，加了 #ifndef 也没用
    // 只能把 .hpp 拆成 .h 和 .cpp
    extern unsigned long long p[64], q[64];

    inline int Chebyshev(std::pair<int, int> a, std::pair<int, int> b)
    {
        return std::max(a.first < b.first ? b.first - a.first : a.first - b.first, a.second < b.second ? b.second - a.second : a.second - b.second);
    }


    void Init(void);
}

#endif
