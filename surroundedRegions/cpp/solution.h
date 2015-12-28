#include <iostream>
#include <vector>
#include <stack>
#include <deque>
using namespace std;

void print(vector<vector<char>> V);

class Solution {
private:
    int rows, cols;
public:
    void BFS(vector<vector<char>>& board, int r, int c);
    void solve(vector<vector<char>>& board);
};
