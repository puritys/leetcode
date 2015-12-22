#include "solution.h"

/*DP Solution*/

// Better performance
int Solution::minPathSum(vector<vector<int>>& grid) {
    if (grid.empty()) return 0;
    rows = grid.size();
    cols = grid[0].size();
    vector<vector<int>> minPath(rows, vector<int>(cols));
    int r, c; //row and col
    minPath[0][0] = grid[0][0];
    for (r = 1; r < rows; r++) minPath[r][0] = minPath[r-1][0] + grid[r][0];
    for (c = 1; c < cols; c++) minPath[0][c] = minPath[0][c - 1] + grid[0][c];

    for (r = 1; r < rows; r++) {
        for (c = 1; c < cols; c++) {
            minPath[r][c] = min(minPath[r-1][c], minPath[r][c-1]) + grid[r][c];           
        }
    }
    return minPath[rows-1][cols-1];
}


// The original , version 1
//int Solution::minPathSum(vector<vector<int>>& grid) {
//    if (grid.empty()) return 0;
//    rows = grid.size();
//    cols = grid[0].size();
//    vector<vector<int>> minPath(rows, vector<int>(cols));
//    int r, c; //row and col
//    for (r = 0; r < rows; r++) {
//        for (c = 0; c < cols; c++) {
//            minPath[r][c] = 0;
//        }
//    }
//
//    for (r = 0; r < rows; r++) {
//        for (c = 0; c < cols; c++) {
//            if (r - 1 < 0 && c - 1 < 0) {
//                minPath[r][c] = grid[r][c];
//            } else if (r - 1 < 0) {
//                minPath[r][c] = minPath[r][c-1] + grid[r][c];
//            } else if (c - 1 < 0) {
//                minPath[r][c] = minPath[r - 1][c] + grid[r][c];
//            } else {
//                minPath[r][c] = min(minPath[r-1][c], minPath[r][c-1]) + grid[r][c];           
//            }
//        }
//    }
//    return minPath[rows-1][cols-1];
//}

