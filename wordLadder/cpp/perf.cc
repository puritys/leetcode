#include "solution.h"
#include "smartPerf.h"

void testShortestPath() {
    int len = 0;
    Solution *obj = new Solution();
    unordered_set<string> list;
    vector<string> s = {"hot","dot","dog","lot","log"};
    reverse(s.begin(), s.end());
    for (vector<string>::iterator it = s.begin(); it != s.end(); it++) {
        list.insert(*it);
    }
    len = obj->ladderLength("hit", "cog", list);
}

void testBFS_v1() {
    int len = 0;
    SolutionBFS_v1 *obj = new SolutionBFS_v1();
    unordered_set<string> list;
    vector<string> s = {"hot","dot","dog","lot","log"};
    reverse(s.begin(), s.end());
    for (vector<string>::iterator it = s.begin(); it != s.end(); it++) {
        list.insert(*it);
    }
    len = obj->ladderLength("hit", "cog", list);
}

void testBFS() {
    int len = 0;
    Solution *obj = new Solution();
    unordered_set<string> list;
    vector<string> s = {"hot","dot","dog","lot","log"};
    reverse(s.begin(), s.end());
    for (vector<string>::iterator it = s.begin(); it != s.end(); it++) {
        list.insert(*it);
    }
    len = obj->ladderLength("hit", "cog", list);
}


int main() {
    int max = 3000;
    smartPerf::start("testShortestPath");
    for (int i = 0; i < max; i++) {
        testShortestPath();
    }
    smartPerf::end();

    smartPerf::start("testBFS_v1");
    for (int i = 0; i < max; i++) {
        testBFS_v1();
    }
    smartPerf::end();

    smartPerf::start("testBFS");
    for (int i = 0; i < max; i++) {
        testBFS();
    }
    smartPerf::end();


    smartPerf::print();
    return 0;
}

