#include "algorithm.h"
    

vector<pair<int, int>> Solution::getSkyline(vector<vector<int>>& buildings) {
    vector<vector<int> > roof; // {left, right, x1, x1', h1, x2, x2', h2}
    int left, right, height, index, c;
    for (auto vit:buildings) {
        left = vit[0];
        right = vit[1];
        height = vit[2];
        index = findIndexInRectangles(left, roof);
        if (index >= 0) {
            if (right > roof[index][1]) roof[index][1] = right;
            c = addTheRoofPoints(left, right, height, &roof[index]);
        } else {
            vector<int> p = vector<int> (5, 0);
            p[0] = p[2] = left; p[1] = p[3] = right; p[4] = height;
            roof.push_back(p);
        }
    //cout << "----" << endl;printVector(roof); cout << endl;

//printVector(roof);
    }

    //At the end, return the points
    sort(&roof);
//printVector(roof);

    vector<pair<int, int>> ret;
    vector<int>::iterator roofIt;
    int preLeft, preRight, preHeight, maxRight;

    for (auto rit:roof) {
        roofIt = rit.begin();
        maxRight = *(++roofIt);
        preLeft = *(++roofIt);
        preRight = *(++roofIt);
        preHeight = *(++roofIt);
        ret.push_back(make_pair(preLeft, preHeight));

        for (roofIt++; roofIt != rit.end(); roofIt++) {
            left = *(roofIt);
            right = *(++roofIt);
            height = *(++roofIt);
            if (height == preHeight) continue;
            preHeight = height;
            ret.push_back(make_pair(left, height));
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

int Solution::addTheRoofPoints(int left, int right, int height, vector<int> *ret) {
    int orgLeft = left;
    int tLeft, tRight, tHeight;
    vector<int>::iterator it;
    vector<int>::iterator end;
    vector<int> newPoints;
    end = ret->begin();end++;
    it = ret->end();

    while(1) {
        it--;
        if (it == end) break;

        tHeight = *(it);
        tRight = *(--it);
        tLeft = *(--it);
//cout << "left right " << left <<" " << right << " " << height  << "  tLeft tRight " <<  tLeft << " " << tRight << " " << tHeight<< endl;
        if (right > tRight && left > tRight) continue;

        if (right > tRight && left < tLeft) {
            // split this
            if (height >= tHeight) {
                ret->erase(it + 2);
                ret->erase(it + 1);
                ret->erase(it);
            } else {
//cout << "add right "<< tRight << endl;
                newPoints.push_back(tRight);
                newPoints.push_back(right);
                newPoints.push_back(height);
                right = tLeft;
            }

        } else if (left < tLeft && right > tRight) {
            if (height >= tHeight) {
                ret->erase(it + 2);
                ret->erase(it + 1);
                ret->erase(it);
            }
        } else if (right <= tRight && left >= tLeft) {
            if (height > tHeight) {
                if (right == tRight && left == tLeft) {
                    *(it + 2) = height;
                    addNewPoints(newPoints, ret);
                    return 0;
                } else if (left == tLeft) {
                    *it = right;
                } else if (right == tRight) { 
                    *(it + 1) = left;
                } else {
                    //split the last point to two line
                    int newLeft = right;
                    int newRight = tRight;
                    *(it + 1) = left;
                    ret->push_back(newLeft);
                    ret->push_back(newRight);
                    ret->push_back(tHeight);
                }
            } else {
                addNewPoints(newPoints, ret);
                return 0;
            }
        } else if (left >= tLeft) { //right > tRight
            if (height > tHeight) {
                if (left == tLeft) {
                    ret->erase(it + 2);
                    ret->erase(it + 1);
                    ret->erase(it);
                    continue;
                }
                *(it+1) =  left;//change right
            } else {
                left = tRight;
            }
        } else if (right <= tRight && right > tLeft) {
            if (height > tHeight) {
                if (right == tRight) {
                    ret->erase(it + 2);
                    ret->erase(it + 1);
                    ret->erase(it);
                    continue;
                }
                *it = right; //change left
            } else {
                right = tLeft;
            }
        } 

    }
    if (left != right) {
        // Add new point
        ret->push_back(left);
        ret->push_back(right);
        ret->push_back(height);
    }
    addNewPoints(newPoints, ret);
    return 1;

}

void Solution::addNewPoints(vector<int> newPoints, vector<int> *ret) {
    vector<int>::iterator it;
    it = newPoints.begin();
    for (; it != newPoints.end(); it++) {
        addTheRoofPoints(*(it), *(it + 1), *(it + 2), ret);
        ++++it;
    }

}

void Solution::sort(vector<vector<int>> *roof) {
    int size, i, j, tmp;
    vector<vector<int>>::iterator rit;
    rit = roof->begin();
    for (; rit != roof->end(); rit++) {
        size = rit->size();
        for (i = 2; i < size; i+=3) {
            for (j = i + 3; j < size; j+=3) {
                if ((*rit)[j] < (*rit)[i]) {
                    tmp = (*rit)[i];
                    (*rit)[i] = (*rit)[j];
                    (*rit)[j] = tmp;

                    tmp = (*rit)[i + 1];
                    (*rit)[i + 1] = (*rit)[j + 1];
                    (*rit)[j + 1] = tmp;

                    tmp = (*rit)[i + 2];
                    (*rit)[i + 2] = (*rit)[j + 2];
                    (*rit)[j + 2] = tmp;
                }
            }
        }
    }
}

