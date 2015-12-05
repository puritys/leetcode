#include "solution.h"

int main () {
    string filename = "testData/case2";
    string start, end;
    unordered_set<string> wordList;
    readFile(filename, start, end, wordList);

    Solution *obj = new Solution();
//    //vector<string> v = {"hot","dot","dog","lot","log"};
//    vector<string> v = {"a","b","c"};
//
//    unordered_set<string> wordList;
//    for (auto it = v.begin(); it != v.end(); it++) {
//        wordList.insert(*it);
//    }

    //unordered_map<string, vector<string>> ret = obj->findLadders("hit", "cog", wordList);
    auto ret = obj->findLadders(start, end, wordList);

 //   cout << endl << "-----------" << endl;
 //   readFile(filename, start, end, wordList);
 //   Solution2 *obj2 = new Solution2();
 //   auto ret2 = obj2->findLadders(start, end, wordList);

    for (auto it = ret.begin(); it != ret.end(); it++) {
        cout << " ret  = " ;
        for (auto it2 = it->begin(); it2 != it->end(); it2++) {
            cout << *it2 << " ";
        }
        cout << endl;
    }

    return 0;
}
