#include "solution.h"

// Failed, stack overflow
//void Solution::BFS(vector<vector<char>>& board, int r, int c) {
//    if (r >= rows) return ;  else if (r < 0) return ;
//    if (c >= cols) return ;  else if (c < 0) return ;
//    if (board[r][c] == 'O') {
//        board[r][c] = 'Y';
//        BFS(board, r+1, c);
//        BFS(board, r-1, c);
//        BFS(board, r, c+1);
//        BFS(board, r, c-1);
//    }
//
//}

//Runtime: 52 ms
//void Solution::BFS(vector<vector<char>>& board, int r, int c) {/*{{{*/
//    stack<pair<int, int>> now, next;
//    next.push(make_pair(r, c));
//    while (!next.empty()) {
//        now = next;
//        while(!next.empty()) next.pop();
//        while (!now.empty()) {
//            pair<int, int> v = now.top();
//            now.pop();
//            int r1, c1;
//            r1 = v.first;
//            c1 = v.second;
//            if (r1 >= rows) continue;  else if (r1 < 0) continue;
//            if (c1 >= cols) continue;  else if (c1 < 0) continue;
//           
//            if (board[r1][c1] == 'O') {
//                board[r1][c1] = 'Y';
//                next.push(make_pair(r1 + 1, c1));
//                next.push(make_pair(r1 - 1, c1));
//                next.push(make_pair(r1, c1 + 1));
//                next.push(make_pair(r1, c1 - 1));
//            }
//        }
//    }
//}/*}}}*/

//Runtime: 24 ms
void Solution::BFS(vector<vector<char>>& board, int r, int c) {/*{{{*/
    deque<pair<int, int>> now;
    now.push_back(make_pair(r, c));
    pair<int, int> v;
    while (!now.empty()) {
        v = now.front();
        now.pop_front();
        int r1, c1;
        r1 = v.first;
        c1 = v.second;
       
        if (board[r1][c1] == 'O') {
            board[r1][c1] = 'Y';

            if (r1 + 1 < rows) now.push_back(make_pair(r1 + 1, c1));
            if (r1 - 1 >= 0) now.push_back(make_pair(r1 - 1, c1));
            if (c1 + 1 < cols) now.push_back(make_pair(r1, c1 + 1));
            if (c1 - 1 >= 0) now.push_back(make_pair(r1, c1 - 1));
        }
    }
}/*}}}*/

void Solution::solve(vector<vector<char>>& board) {
    int r, c;
    rows = board.size();
    if (rows <= 0) return ;
    cols = board[0].size();
    if (cols <= 0) return ;

    for (c = 0; c < cols; c++) {
        if (board[0][c] == 'O') {
            BFS(board, 0, c);
        }
        if (board[rows - 1][c] == 'O') {
            BFS(board, rows - 1, c);
        }
    }

    for (r = 1; r < rows - 1; r++) {
        if (board[r][0] == 'O') {
            BFS(board, r, 0);
        }
        if (board[r][cols - 1] == 'O') {
            BFS(board, r, cols - 1);
        }
    }
    for (r = 0; r < rows; r++) {
        for (c = 0; c < cols; c++) {
            if (board[r][c] == 'Y') {
                board[r][c] = 'O';
            } else {
                board[r][c] = 'X';
            }
        }
    }
}

void print(vector<vector<char>> V) {
    for (auto x = V.begin(); x != V.end(); x++) {
        for (auto y = x->begin(); y != x->end(); y++) {
            cout << *y << " ";
        }
        cout << endl;
    }
}
