/*
 *  Algorithm: BFS + DFS
 */ 
#include "solution.h"

/*
 * Use BFS to find all level point which connect to each others.
 * Two BFS in start point and end point
 */
unordered_map<string, vector<string>> Solution::getConnectedPoints(string beginWord, string endWord, unordered_set<string> &wordList) {
    unordered_map<string, vector<string>> ret;
    unordered_map<string, vector<string>> tmpConnected;


    int strLength = beginWord.size();
    unordered_set<string> BFS1;
    unordered_set<string> BFS2;
    unordered_set<string> next;

    BFS1.insert(beginWord);
    BFS2.insert(endWord);
    unordered_set<string> *BFS1Ptr;
    unordered_set<string> *BFS2Ptr;

    bool isBFS1;
    bool isConnected = false;
    while (!BFS1.empty()) {
        next.clear();
        tmpConnected.clear();
        for (auto t = BFS1.begin(); t != BFS1.end(); ++t) wordList.erase(*t);
        for (auto t = BFS2.begin(); t != BFS2.end(); ++t) wordList.erase(*t);

        if (!BFS2.empty() && 
            BFS1.size() > BFS2.size()
           ) {
            BFS1Ptr = &BFS2;
            BFS2Ptr = &BFS1;
            isBFS1 = false;
        } else {
            BFS1Ptr = &BFS1;
            BFS2Ptr = &BFS2;
            isBFS1 = true;
        }
        for (auto str = BFS1Ptr->begin(); str != BFS1Ptr->end(); str++) {
            for (int i = 0; i < strLength; i++) {
                string tmp = *str;
                char ch = (*str)[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    tmp[i] = c;
                    if (tmp[i] == ch) continue;
                    if (BFS2Ptr->find(tmp) != BFS2Ptr->end()) {
                        // two bfs have connected by this point
                        isConnected = true;
                        if (isBFS1 == true) {
                            ret[*str].push_back(tmp);
                        } else {
                            ret[tmp].push_back(*str);
                        }
                    } else if (isConnected == false) {
                        // if isConnected is true then the points in this level must connect to the second bfs points,because the shortest path have be gotten. 
                        if (wordList.find(tmp) != wordList.end()) {
                            if (isBFS1 == true) {
                                tmpConnected[*str].push_back(tmp);
                            } else {
                                tmpConnected[tmp].push_back(*str);
                            }
                            next.insert(tmp);
                        }
                    }
                }
            }
        }
        if (true == isConnected) return ret;
        else for (auto t = tmpConnected.begin(); t != tmpConnected.end(); t++) ret[t->first] = t->second;
        *BFS1Ptr = next;
    }
    return ret;
}

void Solution::findFullPaths(string str, unordered_map<string, vector<string>> &pointsInLevel, string endWord, vector<vector<string>> &ret, vector<string> &tmp) {

    if (str == endWord) {
        ret.insert(ret.begin(), tmp);
    } else {
        for (auto child = pointsInLevel[str].begin(); child != pointsInLevel[str].end(); ++child) {
            tmp.push_back(*child);
            findFullPaths(*child, pointsInLevel, endWord, ret, tmp);
            tmp.pop_back();
        }
    }
}

vector<vector<string>> Solution::findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
    vector<vector<string>> v;
    vector<string> tmp;
    wordList.insert(endWord);
    wordList.erase(beginWord);

    if (beginWord == endWord) {
        vector<std::string> ret(1, beginWord);
        v.push_back(ret);
        return v;
    }

    unordered_map<string, vector<string>> pointsInLevel;
    pointsInLevel = getConnectedPoints(beginWord, endWord, wordList);
    tmp.push_back(beginWord);
    findFullPaths(beginWord, pointsInLevel, endWord, v, tmp);
    //printMap(pointsInLevel);
    return v;
}

void printSequence(vector<string> t) {
    cout << "ret = ";
    auto it = t.begin();
    cout << *it;
    for (it++; it != t.end(); it++) {
        cout << " -> " <<*it; 
    }
    cout << endl;
}

void printSequence(string a, unordered_set<string> t) {
    cout << a << ":  = ";
    auto it = t.begin();
    cout << *it;
    for (it++; it != t.end(); it++) {
        cout << " -> " <<*it; 
    }
    cout << endl;
}
void printMap(unordered_map<string, vector<string>> pointsInLevel) {
    for (auto it = pointsInLevel.begin(); it != pointsInLevel.end(); it++) {
        cout << "key = " << it->first << " child  = " ;
        for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
            cout << *it2 << " ";
        }
        cout << endl;
    }

}

void readFile (string filename, string &start, string &end, unordered_set<string> &wordList) {
    string str;
    FILE *f;
    f = fopen(filename.c_str(), "r");
    str = "";
    while(!feof(f)) {
        char c = fgetc(f);
        if (c == '"') {
            while(!feof(f)) {
                c = fgetc(f);
                if (c == '"') {
                    c = fgetc(f);
                    break;
                }
                str += c;
            }
            break;
        }
    }
    start = str;
    str = "";
    while(!feof(f)) {
        char c = fgetc(f);
        if (c == '"') {
            while(!feof(f)) {
                c = fgetc(f);
                if (c == '"') {
                    c = fgetc(f);
                    break;
                }
                str += c;
            }
            break;
        }
    }
    end = str;
    str = "";

    while(!feof(f)) {
        char c = fgetc(f);
        if (c == '"') {
            str = "";
            while(!feof(f)) {
                c = fgetc(f);
                if (c == '"') {
                    c = fgetc(f);
                    break;
                }
                str += c;
            }
            wordList.insert(str);
        }
    }

    fclose(f);
}


// Simgle BFS
//unordered_map<string, vector<string>> Solution::getConnectedPoints(string beginWord, string endWord, unordered_set<string> &wordList) {
//    int strLength = beginWord.size() + 2;
//    unordered_set<string> untracedPoints;
//    unordered_set<string> nextUntracedPoints;
//
//    untracedPoints.insert(beginWord);
//    unordered_map<string, vector<string>> ret;
//    int maxLevel = 0;
//    while (!untracedPoints.empty()) {
//        maxLevel++;
//        nextUntracedPoints.clear();
//        for (auto traceStr = untracedPoints.begin(); traceStr != untracedPoints.end(); traceStr++) {
//            for (int i = 0; i < strLength; i++) {
//                string tmp = *traceStr;
//                for (int c = 0; c < 26; c++) {
//                    tmp[i] = 'a' + c;
//                    auto connectedStr = wordList.find(tmp);
//                    if (connectedStr != wordList.end()) {
//                        ret[*traceStr].push_back(*connectedStr);
//                        if (*connectedStr == endWord) {
//
//cout << "max level = " << maxLevel << endl;
//                            return ret;
//                        }
//
//                        nextUntracedPoints.insert(*connectedStr);
//                        wordList.erase(*connectedStr);
//                    }
//                }
//            }
//        }
//        swap(untracedPoints, nextUntracedPoints);
//    }
//    return ret;
//}



