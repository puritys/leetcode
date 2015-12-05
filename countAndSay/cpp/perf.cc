#include "solution.h"
#include "smartPerf.h"

void test () {
    Solution *obj = new Solution();
    string s = obj->countAndSay(9);
//31131211131221
}

int main () {
    int max = 9000;
    smartPerf::start("test1");
    for (int i = 0; i < max; i++) test();
    smartPerf::end();
    smartPerf::print();
}
