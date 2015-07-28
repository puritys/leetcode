//https://leetcode.com/problems/max-points-on-a-line/
#include "algorithm.h"


int maxPoints(struct Point* points, int pointsSize) {
    int result[pointsSize], slopeTmpCount[pointsSize], countIndex, max = 0,
        c, samePointNum;
    if (pointsSize == 1) return 1;
    float slope, slopeTmp[pointsSize];
    struct Point p1, p2;
    for (int i = 0; i < pointsSize; i++) {
        p1.x = (points+i)->x;
        p1.y = (points+i)->y;
        countIndex = -1;
        samePointNum = 0;
        for (int j = i + 1; j < pointsSize; j++) {
            p2.x = (points+j)->x;
            p2.y = (points+j)->y;
            if (p2.y == p1.y && p2.x == p1.x) {
                samePointNum++;
                continue;
            }
            if (((float)p2.x - (float)p1.x) == 0) slope = (float)INT_MAX;
            else slope = ((float)p2.y - (float)p1.y) / ((float)p2.x - (float)p1.x);
//printf("p2.x %d p2.y %d  p1.x %d  p1.y %d  slope = %f\n", p2.x, p2.y, p1.x, p1.y, slope);
            c = 0;
            while(slopeTmp[c] != slope && c <= countIndex) { 
                // The slope is in slopeCount, then that slopeCount will plus one.
                c++;
            }
            if (c <= countIndex) {
                // get the same slope
                slopeTmpCount[c]++;
            } else {
                countIndex++;
                slopeTmp[countIndex] = slope;
                slopeTmpCount[countIndex] = 2;
            }
        }
        if (countIndex == -1 && samePointNum > max) max = samePointNum + 1;
        //get the max slopeCount
        for (c = 0; c <= countIndex; c++) {
//printf("slope Tmpcount = %d slope = %f \n", slopeTmpCount[c], slopeTmp[c]);
            if ((slopeTmpCount[c] + samePointNum) > max) {
                max = slopeTmpCount[c] + samePointNum;
            }
        }
//printf("== max = %d \n", max);
    } 
    return max;
}
