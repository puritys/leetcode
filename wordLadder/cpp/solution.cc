#include "solution.h"

int Solution::ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    unordered_set<string> pathLevel, tmp;
    pathLevel.insert(beginWord);
    wordList.insert(endWord);
    int pathLength = 0; 
    int wordLength = beginWord.size();

    while(!pathLevel.empty()) {
        pathLength++;
        tmp.clear();
        for (auto str1 = pathLevel.begin(); str1 != pathLevel.end(); str1++) {
            for (int wIndex = 0; wIndex < wordLength ; wIndex++) {
                string str = *str1;
                for (int a = 0 ; a < 26 ; a++) {
                    str[wIndex] = 'a' + a;
                    if (str == endWord) return ++pathLength;
                    auto foundIt = wordList.find(str);
                    if (foundIt != wordList.end()) {
                        tmp.insert(*foundIt);
                        wordList.erase(foundIt);
                    }
                }

            }
        }
        swap(pathLevel, tmp);
    }
    return 0;
}


