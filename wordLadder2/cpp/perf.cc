#include "solution.h"
#include "smartPerf.h"


void test1(string file) {
    string start, end;
    unordered_set<string> wordList;
    readFile(file, start, end, wordList);

    Solution *obj = new Solution();
    auto ret = obj->findLadders(start, end, wordList);
}
//void test2(string file) {
//    string start, end;
//    unordered_set<string> wordList;
//    readFile(file, start, end, wordList);
//
//    Solution2 *obj = new Solution2();
//    auto ret = obj->findLadders(start, end, wordList);
//}


int main () {
    int max = 10;
    string file = "testData/case2";
    smartPerf::start("test1");
    for (int i = 0; i < max; i++) test1(file);
    smartPerf::end();

//    smartPerf::start("test2");
//    for (int i = 0; i < max; i++) test2(file);
//    smartPerf::end();
//    smartPerf::print();
//

    return 0;
}
