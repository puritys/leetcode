#include "solution.h"

bool SolutionShortestPath::isConnected(string str1, string str2) {
    int unMatchedNum = 0;
    int length = str1.length();
    for (int i = 0; i < length; i++) {
        if (str1.at(i) != str2.at(i)) {
            unMatchedNum++;
            if (unMatchedNum > 1) return false;
        }
    }
    if (unMatchedNum == 1) return true;
    return false;
}

void SolutionShortestPath::countPath(string str, map<string, vector<string> > *paths, map<string, int> *minDistance) {
    auto p = paths->find(str);
    if (p != paths->end()) {
        int tmpDistance = 0;
        auto strInDistance = minDistance->find(str);
        if (strInDistance != minDistance->end()) {
            tmpDistance = strInDistance->second;
        }
        vector<string> v = p->second;
        for (auto it = v.begin(); it != v.end(); it++) {
            auto m2 = minDistance->find(*it);
            if (m2 != minDistance->end()) {
                if (m2->second > (tmpDistance + 1))
                    (*minDistance)[*it] = tmpDistance + 1;
            } else {
                (*minDistance)[*it] = tmpDistance + 1;
            }
            paths->erase(str);
            countPath(*it, paths, minDistance);

        }
    }
}

int SolutionShortestPath::ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    map<string, int> minDistance;
    minDistance[beginWord] = 1;
    map<string, vector<string> > paths;
    wordList.insert(beginWord);
    wordList.insert(endWord);

    unordered_set<string>::iterator str1;
    unordered_set<string>::iterator str2;
    for (str1 = wordList.begin(); str1 != wordList.end(); str1++) {
        for (str2 = str1, str2++; str2 != wordList.end(); str2++) {

            if (isConnected(*str1, *str2)) {
                auto p = paths.find(*str1);
                if (p != paths.end()) {
                    vector<string> *v = &p->second;
                    v->push_back(*str2);
                } else {
                    vector<string> v;
                    v.push_back(*str2);
                    paths.insert(paths.begin(), pair<string, vector<string> >(*str1, v));
                }
                p = paths.find(*str2);
                if (p != paths.end()) {
                    auto *v = &p->second;
                    v->push_back(*str1);
                } else {
                    vector<string> v;
                    v.push_back(*str1);
                    paths.insert(paths.begin(), pair<string, vector<string> >(*str2, v));

                }

            }
        }
    }

    string str = beginWord;
    countPath(beginWord, &paths, &minDistance);
    //printDistance(minDistance);
    auto m = minDistance.find(endWord);
    if (m != minDistance.end()) return m->second;
    return 0;
}


void printMap(map<string, vector<string> > paths) {
    for (auto it = paths.begin(); it != paths.end(); it++) {
        cout << it->first << endl;
        for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
            cout << "v = " << *it2 << endl;
        }
    }
}

void printDistance(map<string, int> paths) {
    for (auto it = paths.begin(); it != paths.end(); it++) {
        cout << it->first << ":" << it->second << endl;
    }
}
