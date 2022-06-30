#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <utility>
#include "pos.h"

namespace Pos
{
    unsigned long long p[64], q[64];

    void Init(void)
    {
        int i, j, x, y;

        srand((unsigned int)time(NULL));
        for(i = 0; i < 7; i ++)
            for(j = 0; j < 7; j ++)
                for(x = 0; x < 7; x ++)
                    for(y = 0; y < 7; y ++)
                        if(Chebyshev(std::make_pair(i, j), std::make_pair(x, y)) == 1)
                            p[i << 3 | j] |= 1ULL << (x << 3 | y);
                        else if(Chebyshev(std::make_pair(i, j), std::make_pair(x, y)) == 2)
                            q[i << 3 | j] |= 1ULL << (x << 3 | y);

        return;
    }
}
