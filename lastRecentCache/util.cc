#include "algorithm.h"

void printMap2(map<int, pair<int, int> > m) {
    map<int, pair<int, int> >::iterator it;
    for (it = m.begin(); it != m.end(); ++it) {
        cout << it->first << " " << it->second.first << "  " << it->second.second <<endl;
    }
    cout << endl;
}

void printMap(map<int, int> m) {
    map<int, int>::iterator it;
    for (it = m.begin(); it != m.end(); ++it) {
        cout << it->first << " " << it->second <<endl;
    }
}
