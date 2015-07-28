#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Point {
    int x;
    int y;
};

int maxPoints(struct Point* points, int pointsSize);
struct Point* createData(int x[], int y[], int size);
void print(struct Point *point, int size);

