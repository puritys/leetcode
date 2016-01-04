#include "solution.h"

int Solution::largestRectangleArea(vector<int>& height) {
    vector<int> hRet, posRet;
    int n, lastHeight = INT_MAX, maxArea = 0;
    height.push_back(0);
    n = height.size();
    for (int i = 0; i < n; i++) {
        int h = height[i];
        // calculate the max area
        while (!hRet.empty() && h < hRet.back()) {
            int number = hRet.back();
            int pos = posRet.back();
            int area;
            hRet.pop_back(); posRet.pop_back();
            if (hRet.empty()) {
                area = number * i;
            } else {
                area = number * (i - posRet.back() - 1);
            }
//cout << "area = " << area  << " : " << number  << " x  "<< (i - posRet.back() - 1) << " i = " << i << " ret = " << posRet.back()<<endl;
            if (area > maxArea) maxArea = area;
        }
        hRet.push_back(h);
        posRet.push_back(i);
    }
    return maxArea;
}

// Time Limit Exceeded
//int Solution::largestRectangleArea(vector<int>& height) {
//    map<int, int> ret;
//    int n, lastHeight = INT_MAX, maxArea = 0;
//    height.push_back(0);
//    n = height.size();
//    for (int i = 0; i < n; i++) {
//        int h = height[i];
//        if (!ret.empty() && h <= lastHeight) {
//            // calculate the max area
//            map<int, int> next;
//            for (auto r = ret.begin(); r != ret.end(); r++) {
//                int number = r->first;
//                int width = r->second;
//                if (number < h) {
//                    next.insert(pair<int, int>(number, width));
//                    break;
//                }
//                int area = number * width;
////cout << "area = " << area  << " : " << number << "x"<<width<<endl;
//                if (area > maxArea) maxArea = area;
//            }
//            ret = next; 
//        } else {
//            // all number in ret add one
//            for (auto r = ret.begin(); r != ret.end(); r++) {
//                r->second++;
//            }
////cout << "insert  = " << h << endl;
//            ret.insert(pair<int, int>(h, 1));
//            lastHeight = h;
//        }
//    }
//    return maxArea;
//}
