#include <iostream>
#include <array>
using namespace std;

const int COLSIZE = 6;  // 行数
const int ROWSIZE = 7;  // 列数

bool isConsecutiveFour(array<array<int, ROWSIZE>, COLSIZE> &m) {
    // 水平 →
    for (int i = 0; i < COLSIZE; ++i) {
        for (int j = 0; j <= ROWSIZE - 4; ++j) {
            int val = m[i][j];
            if (val != 0 && val == m[i][j+1] && val == m[i][j+2] && val == m[i][j+3])
                return true;
        }
    }

    // 垂直 ↓
    for (int j = 0; j < ROWSIZE; ++j) {
        for (int i = 0; i <= COLSIZE - 4; ++i) {
            int val = m[i][j];
            if (val != 0 && val == m[i+1][j] && val == m[i+2][j] && val == m[i+3][j])
                return true;
        }
    }

    // 对角线 ↘
    for (int i = 0; i <= COLSIZE - 4; ++i) {
        for (int j = 0; j <= ROWSIZE - 4; ++j) {
            int val = m[i][j];
            if (val != 0 && val == m[i+1][j+1] && val == m[i+2][j+2] && val == m[i+3][j+3])
                return true;
        }
    }

    // 对角线 ↙
    for (int i = 0; i <= COLSIZE - 4; ++i) {
        for (int j = 3; j < ROWSIZE; ++j) {
            int val = m[i][j];
            if (val != 0 && val == m[i+1][j-1] && val == m[i+2][j-2] && val == m[i+3][j-3])
                return true;
        }
    }

    return false;
}
