#include "algorithm.h"
    

vector<pair<int, int>> SolutionOld::getSkyline(vector<vector<int>>& buildings) {
    vector<vector<int> > rectangles; // {left, right, x1, x1', h1, x2, x2', h2}
    int left, right, height, height2, index, c;
//if the left position of building(x1) is exist in the rangle of rectangles (rectangle[0]), 
    for (auto vit:buildings) {
        left = vit[0];
        right = vit[1];
        height = height2 = vit[2];
        index = findIndexInRectangles(left, rectangles);
//cout << "find index = " << index  << "  left = " << left<< endl;
        if (index >= 0) {
//then 
//    1. Enlarge the range, x and x' , of rectangle[0]
//    2. Check the height(h) if it is in the consective horizontal line of rectangle[0].
//       if yes, skip
//       if not, add the new height into rectangle[0]
            if (right > rectangles[index][1]) rectangles[index][1] = right;
            c = findLeftOutlinePoint(&left, &right, &height, &height2, &rectangles[index]);
            if (c >= 0) { // New point
//cout << "add new point " << left << endl; 
                rectangles[index].push_back(left);
                rectangles[index].push_back(right);
                rectangles[index].push_back(height);
                if (c != 1) height2 = -1;
//if (height2 >= 0) cout << "add right height2 = " << height2  << endl;
                rectangles[index].push_back(height2);

            } else if (c == -2) {
//cout << "replace point , new = " << left << endl; 

                rectangles[index].pop_back();
                rectangles[index].pop_back();
                rectangles[index].pop_back();
                rectangles[index].pop_back();
                rectangles[index].push_back(vit[0]);
                rectangles[index].push_back(vit[1]);
                rectangles[index].push_back(height);
                rectangles[index].push_back(-1);

            }
        } else {
//else
//  Add a new range into rectangle, such as rectangle[1].
            vector<int> p = vector<int> (6, 0);
            p[0] = p[2] = left; p[1] = p[3] = right; p[4] = height;
            p[5] = -1;

            rectangles.push_back(p);
        }
    //cout << "----" << endl;printVector(rectangles); cout << endl;

printVector(rectangles);
    }
//At the end, return the points

    vector<pair<int, int>> ret;

    int preHeight = -1; int maxRight;
    for (auto vit:rectangles) {
        vector<int>::iterator it;
        it = vit.begin();
        maxRight = *(++it);
        for (it++; it != vit.end(); it++) {
            left = *it;
            right = *(++it);
            height  = *(++it);
            height2  = *(++it);
            if (height >= 0 && height != preHeight)
                ret.push_back(make_pair(left, height));
            if (height2 >= 0 && height2 != height)
                ret.push_back(make_pair(right, height2));
            preHeight = height;
        }
        ret.push_back(make_pair(maxRight, 0));
    }

    return ret;
}

int Solution::findIndexInRectangles(int left, vector<vector<int> > ret) {
    int index = 0;
    for (auto vit:ret) {
        if (left >= vit[0] && left <= vit[1]) return index;
        index++;
    }
    return -1;

}

int Solution::findLeftOutlinePoint(int *left, int *right, int *height, int *height2, vector<int> *ret) {
    int orgLeft = *left;
    int tLeft, tRight, tHeight, tHeight2, re = 0;
    vector<int>::iterator it;
    vector<int>::iterator end;
    end = ret->begin();end++;
    it = ret->end();
    it--;
    tHeight = *(--it);
    tRight = *(--it);
    tLeft = *(--it);
    if (*height > tHeight && *left == tLeft && *right == tRight) {
        return -2;
    }

    while(1) {
cout << "left right " << *left <<" " << *right << " " << *height  << "  tLeft tRight " <<  tLeft << " " << tRight << " " << tHeight<< endl;
        if (*left < tRight) {
//cout << "in" << endl;
            if (*height < tHeight) {
                if (*right <= tRight) {
                    return -1;
                    // This building is too short and covered by others
                } else {
cout << "change left " << tRight << endl;
                    *left = tRight;
                }
            } 
        }
        it--;
        if (it == end) break;
        tHeight = *(--it);
        tRight = *(--it);
        tLeft = *(--it);
    }
    // right point
    it = ret->end();
    for (it--; it != end; it--) {
        tHeight2 = *(it);
        tHeight = *(--it);
        tRight = *(--it);
        tLeft = *(--it);
cout << "right --  left right " << *left <<" " << *right << " " << *height2  << "  tLeft tRight " <<  tLeft << " " << tRight << " " << tHeight<< " tHeight2 " << tHeight2 << endl;

        if (*right < tRight) {
            if ( *height2 > tHeight) {
cout << "in right " << endl;
                *height2 = tHeight;
                re = 1;
            }
        } else {
            if (tHeight2 < *height) {
cout << "clear right tHeight = " << tHeight << endl;
                if (tHeight > *height) *(it + 3) = *height;
                else  *(it + 3)  = -1;
            }
        }
        if (tLeft >= orgLeft) {
            if ( *height >= tHeight) {
cout << "remove left " << endl;
                *(it + 2) = -1;
            } 

        }
    }

    return re;

}

