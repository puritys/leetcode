#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

#include "math.h"
#include "limits.h"
#include "stdio.h"

using namespace std;
void printMap(map<string, vector<string> > paths);
void printDistance(map<string, int> paths);

class Solution {
    public:
        int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList);

};

class SolutionBFS_v1 {
    public:
        bool isConnected(string str1, string str2);
        int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList);

};


class SolutionShortestPath {
    public:
        int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList);
        bool isConnected(string str1, string str2);
        void countPath(string str, map<string, vector<string> > *paths, map<string, int> *minDistance);

};

