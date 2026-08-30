class Solution {
public:
    bool isValid(int row, int col, vector<vector<char>>& board, char c) {
        for (int i = 0; i < 9; i++) {
            // Check row
            if (board[row][i] == c) return false;
            
            // Check column
            if (board[i][col] == c) return false;
            
            // Check 3x3 sub-grid
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(i, j, board, c)) {
                            board[i][j] = c; // Place the character

                            if (solve(board)) {
                                return true; // Move forward if valid
                            }

                            board[i][j] = '.'; // Backtrack if it fails later
                        }
                    }
                    return false; // Return false if no number from '1'-'9' fits
                }
            }
        }
        return true; // Return true if the board is completely filled
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
