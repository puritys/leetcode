//https://leetcode.com/problems/max-points-on-a-line/
#include "algorithm.h"


int main () {
    int size = 9;
    int x[10] = {0, 1,2,3,2,2, 3,4,5};//,6,7,8,9,10};
    int y[10] = {0, 1,2,3,1,0, 1,1,1};//,6,7,8,9,10};
    struct Point *point = createData(x, y, size);
    int max = maxPoints(point, size);
    //print(point, size);
    printf("result  = %d \n", max);
    return 0;
}
