#include "algorithm.h"
 
vector<vector<int> > createVector(string data) {
    vector<vector<int> > v;
    string str = "", tmp;
    vector<int> d;
    int length = data.size();
    for (int i = 0; i < length; i++) {
        tmp = data.substr(i, 1);
        if (tmp == " " || tmp == ",") {
            if (!str.empty()) {
                d.push_back(atoi(str.c_str()));
            }
            if (tmp == ",") {
                v.push_back(d);
                d = vector<int>(0, 0);
            }
            str = "";
            continue;
        } else if (tmp != " " && tmp != ",") {
            str += tmp;
        }
    }
    if (!d.empty()) {
        d.push_back(atoi(str.c_str()));
        v.push_back(d); 
    }
    return v;
}

void printVector(vector<vector<int> > v) {
    for (auto vit:v) {
        for (auto dit:vit) {
            cout << dit << " ";
        }
        cout << endl;
    }

}

void printPairVector(vector<pair<int, int> > v) {
    for (auto vit:v) {
        cout << vit.first << " " << vit.second << endl;
    }

}
