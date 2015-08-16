#include <iostream>
#include <vector>
#include <regex>
using namespace std;

vector<vector<int> > createVector(string data);
void printVector(vector<vector<int> > v);
void printPairVector(vector<pair<int, int> > v);

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings);
    int findIndexInRectangles(int left, vector<vector<int>> ret);
    int addTheRoofPoints(int left, int right, int height, vector<int> *ret);
    void sort(vector<vector<int>> *ret);
    void addNewPoints(vector<int> newPoints, vector<int> *ret);
};

class SolutionOld {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings);
    int findIndexInRectangles(int left, vector<vector<int>> ret);
    int findLeftOutlinePoint(int *left, int *right, int *height, int *height2, vector<int> *ret);
};

