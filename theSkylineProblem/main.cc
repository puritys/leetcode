// https://leetcode.com/problems/the-skyline-problem/

#include "algorithm.h"

int main () {
    string data ("2 9 10, 3 7 15, 5 12 12, 15 20 10, 19 24 8");

    vector<vector<int> > v = createVector(data); 
//    printVector(v); cout << endl;

    Solution *o = new Solution();
    vector<pair<int, int>> points = o->getSkyline(v);
    printPairVector(points);

    return 0;
}


