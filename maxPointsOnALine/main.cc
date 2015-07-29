//https://leetcode.com/problems/max-points-on-a-line/
#include "algorithm.h"


int c() {
    int size = 9;
    int x[10] = {0, 1,2,3,2,2, 3,4,5};//,6,7,8,9,10};
    int y[10] = {0, 1,2,3,1,0, 1,1,1};//,6,7,8,9,10};
    struct Point *point = createData(x, y, size);
    int max = maxPoints(point, size);
    return max;
}

int cpp() {
    int size = 9;
    int x[10] = {0, 1,2,3,2,2, 3,4,5};//,6,7,8,9,10};
    int y[10] = {0, 1,2,3,1,0, 1,1,1};//,6,7,8,9,10};
    Solution *obj = new Solution();
    vector<struct Point> points;
    vector<struct Point>::iterator it;
    for (int i = 0; i < size; i++) {
        struct Point point = {x[i], y[i]};
        points.push_back(point);
    }
    int max = obj->maxPoints(points);

    return max;
}

int main () {
    int max;
//    max = c();
    max = cpp();
    printf("result  = %d \n", max);
    return 0;
}
