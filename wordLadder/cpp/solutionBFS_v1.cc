#include "solution.h"

bool SolutionBFS_v1::isConnected(string str1, string str2) {
    int unMatchedNum = 0;
    int length = str1.length();
    for (int i = 0; i < length; i++) {
        if (str1.at(i) != str2.at(i)) {
            if (++unMatchedNum > 1) return false;
        }
    }
    if (unMatchedNum == 1) return true;
    return false;
}

int SolutionBFS_v1::ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    unordered_set<string> pathLevel, tmp;
    pathLevel.insert(beginWord);
    wordList.insert(endWord);
    int pathLength = 0; 
    while(!pathLevel.empty()) {
        pathLength++;
        tmp.clear();
        for (auto str1 = pathLevel.begin(); str1 != pathLevel.end(); str1++) {
            for (auto str2 = wordList.begin(); str2 != wordList.end();) {
                if (isConnected(*str1, *str2)) {
                    if (*str2 == endWord) {
                        return ++pathLength;
                    }
                    tmp.insert(*str2);
                    str2 = wordList.erase(str2);
                } else {
                    str2++;
                }
            }
        }
        swap(pathLevel, tmp);
    }
    return 0;
}


