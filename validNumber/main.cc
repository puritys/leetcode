//  https://leetcode.com/problems/valid-number/
#include "algorithm.h"


bool cpp() {
    bool ret = false;
    Solution *obj = new Solution();
//    ret = obj->isNumber("23123.4e45.2");
    ret = obj->isNumber(" 005047e+6");


    return ret;
}

int main () {
    bool b;
    b = cpp();
    printf("result  = %d \n", b);
    return 0;
}
