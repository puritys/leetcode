#include "algorithm.h"

// Adds a number into the data structure.
void MedianFinder::addNum(int num) {
    if (length == 0) {
        nums.insert(nums.begin(), num);
    } else {
        int i = (length - 1) / 2, left = -1, right = length;
        while (true) {
            if (num > nums[i]) {
                left = i;
                i = (i + right) / 2;
                if (left == i) {
                    nums.insert(nums.begin() + left + 1, num);
                    break;
                }
            } else {
                right = i;
                i = (0 + i) / 2;
                if (right == i) {
                    nums.insert(nums.begin() + right, num);
                    break;
                }
            }
        }
    }
    length++;
    //for (int j = 0; j < length; j ++) cout << nums[j] <<" " ;  cout << endl;
}

// Returns the median of current data stream
double MedianFinder::findMedian() {
    double median;
    if (length % 2 == 0) {
        median = ((double)nums[length/2 - 1] + (double)nums[length/2]) / 2;
    } else {
        median = nums[(int)length/2];
    }
    return median;
}

