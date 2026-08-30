class Solution {
public:
    void saveans(vector<vector<string>>& ans, vector<vector<char>>& board,
                 int n) {
        vector<string> output;
        for (int i = 0; i < n; i++) {
            string temp = "";
            for (int j = 0; j < n; j++) {
                temp += board[i][j];
            }
            output.push_back(temp);
        }
        ans.push_back(output);
        return;
    }
    bool isSafe(int n, vector<vector<char>>& board, int row, int col) {
        for (int i = col; i >= 0; i--) {
            if (board[row][i] == 'Q') {
                return false;
            }
        }
        int x = row - 1;
        int y = col - 1;
        while (x >= 0 && y >= 0) {
            if (board[x][y] == 'Q') {
                return false;
            }
            x--;
            y--;
        }

        // 3. Check lower-left diagonal (Row increases, Col decreases)
        x = row + 1;
        y = col - 1;
        while (x < n && y >= 0) {
            if (board[x][y] == 'Q') {
                return false;
            }
            x++;
            y--;
        }

        return true;
    }
    void solve(int n, vector<vector<char>>& board, int col,
               vector<vector<string>>& ans) {
        if (col >= n) {
            saveans(ans, board, n);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (isSafe(n, board, i, col)) {
                board[i][col] = 'Q';
                solve(n, board, col + 1, ans);
                board[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> board(n, vector<char>(n, '.'));

        int col = 0;
        solve(n, board, col, ans);
        return ans;
    }
};