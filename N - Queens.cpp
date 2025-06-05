class Solution {
public:
    vector<vector<string>> res;
    int N;
    void backtrack(int R, unordered_set<int> &col, unordered_set<int> &diag, unordered_set<int> &back_diag, vector<string> &board) {
        if (N == R) {
            res.push_back(board);
        }
        for (int C = 0; C < N; C++) {
            int D = R - C;
            int BD = R + C;
            if (col.find(C) != col.end() || diag.find(D) != diag.end() || back_diag.find(BD) != back_diag.end())
                continue;
            col.insert(C);
            diag.insert(D);
            back_diag.insert(BD);
            board[R][C] = 'Q';
            backtrack(R+1, col, diag, back_diag, board);
            col.erase(C);
            diag.erase(D);
            back_diag.erase(BD);
            board[R][C] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<string> board(N, string(N, '.'));
        unordered_set<int> col, diag, back_diag;
        backtrack(0, col, diag, back_diag, board);
        return res;
    }
};
