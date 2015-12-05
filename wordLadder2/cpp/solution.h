#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <stack>

#include "math.h"
#include "limits.h"
#include "stdio.h"

using namespace std;
class Solution {
    public:
        unordered_map<string, vector<string>> getConnectedPoints(string beginWord, string endWord, unordered_set<string> &wordList);
        vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList);
        void findFullPaths(string untracedStr, unordered_map<string, vector<string>> &pointsInLevel, string endWord, vector<vector<string>> &ret, vector<string> &tmp);
       
};

void printSequence(string name, unordered_set<string> t);
void printSequence(vector<string> t);
void printMap(unordered_map<string, vector<string>> pointsInLevel);
void readFile (string filename, string &start, string &end, unordered_set<string> &wordList);

