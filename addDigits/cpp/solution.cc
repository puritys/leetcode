#include "solution.h"

int Solution::addDigits(int num) {
    int ret = 0;
    for (int i = num; i > 0; i/=10) {
        ret += i % 10;
        if (ret >= 10) ret -= 9;
    }
    return ret;
}
