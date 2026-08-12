class Solution {
private:
    void backtrack(int row, int n, 
                   vector<string>& board, 
                   vector<vector<string>>& res,
                   vector<bool>& cols, 
                   vector<bool>& posDiag, 
                   vector<bool>& negDiag) {
        if (row == n) {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (cols[col] || posDiag[row + col] || negDiag[row - col + n - 1]) {
                continue;
            }

            board[row][col] = 'Q';
            cols[col] = true;
            posDiag[row + col] = true;
            negDiag[row - col + n - 1] = true;

            backtrack(row + 1, n, board, res, cols, posDiag, negDiag);

            board[row][col] = '.';
            cols[col] = false;
            posDiag[row + col] = false;
            negDiag[row - col + n - 1] = false;
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));

        vector<bool> cols(n, false);
        vector<bool> posDiag(2 * n - 1, false);
        vector<bool> negDiag(2 * n - 1, false);

        backtrack(0, n, board, res, cols, posDiag, negDiag);
        return res;
    }
};