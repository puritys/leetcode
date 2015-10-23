// https://leetcode.com/problems/find-median-from-data-stream/
#include "algorithm.h"

int main() {
    MedianFinder *o = new MedianFinder();

    o->addNum(12);
    o->addNum(10);
    o->addNum(13);
    o->addNum(11);
    o->addNum(5);
    o->addNum(15);
    o->addNum(1);
    o->addNum(11);




    //o->addNum(8);


    double ret = o->findMedian();
    cout << "ret = " << ret << endl;
    return 0;
}
