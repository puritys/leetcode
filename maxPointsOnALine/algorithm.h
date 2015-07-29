#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <typeinfo>

using namespace std;

struct Point {
    int x;
    int y;
};

int maxPoints(struct Point* points, int pointsSize);
struct Point* createData(int x[], int y[], int size);
void print(struct Point *point, int size);


class Solution {
public:
    int maxPoints(vector<Point>& points);
};

