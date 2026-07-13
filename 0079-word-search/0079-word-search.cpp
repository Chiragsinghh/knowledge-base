class Solution {
public:
    bool isSafe(int x, int y, int m, int n, vector<vector<bool>>& vis) {
        return (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]);
    }

    bool solve(int x, int y, vector<vector<char>>& board, string &word, vector<vector<bool>>& vis, int index, int m, int n) {
        // Base Case: If the current character doesn't match, stop this path
        if (board[x][y] != word[index]) {
            return false;
        }
        
        // Base Case: If the whole word is matched
        if (index == word.length() - 1) {
            return true;
        }

        vis[x][y] = true;

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        // Explore all 4 directions
        for (int d = 0; d < 4; d++) {
            int newx = x + dx[d];
            int newy = y + dy[d];

            if (isSafe(newx, newy, m, n, vis)) {
                // If any path succeeds, immediately pass the success up the chain
                if (solve(newx, newy, board, word, vis, index + 1, m, n)) {
                    return true;
                }
            }
        }

        // Backtrack
        vis[x][y] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int len = word.size();

        int m= board.size();
        int n = board[0].size();

        vector<vector<bool>>vis(m,vector<bool>(n,false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (solve(i, j, board, word, vis, 0, m, n)) {
                        return true;
                    }
                }
            }
        }
        return false;

    }
};