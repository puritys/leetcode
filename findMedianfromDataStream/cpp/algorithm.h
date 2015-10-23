#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MedianFinder {

public:
    int length = 0;
    vector<int> nums;
    void addNum(int num);
    double findMedian();
};
