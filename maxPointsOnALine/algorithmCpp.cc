#include "algorithm.h"


int Solution::maxPoints(vector<Point>& points) {
    int len;
    len = points.size();
    if (len <= 2) return len;
    float x1, x2, y1, y2, slope, infinite;
    int max = 0, samePointNum;
    infinite = (float)INT_MAX;
    map<float, int>::iterator cit;
    vector<Point>::iterator i, j;
    for (i = points.begin(); i != points.end(); ++i) {
        x1 = i->x; y1 = i->y; samePointNum = 1;
        map<float, int> counts;
        for (j = i +1; j != points.end(); j++) {
            x2 = j->x; y2 = j->y;
            if (x1 == x2 && y1 == y2) {
                samePointNum++;
                continue;
            } else if (x1 == x2) {
                //slope is infinite
                slope = infinite;
            } else {
                slope = ((float)y2 - (float)y1) / ((float)x2 - (float)x1);
            }
            counts[slope]++;
        }
        for (cit = counts.begin(); cit != counts.end(); cit++) {
            max = std::max(max, (cit->second + samePointNum));
        }
        max = std::max(max, samePointNum);

    }
    return max;
}

