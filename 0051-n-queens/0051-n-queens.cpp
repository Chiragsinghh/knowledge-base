class Solution {
public:
    void saveans(vector<vector<char>>&board,vector<vector<string>>&ans){
        vector<string>temp;
        for(int i=0;i<board.size();i++){
            string word = "";
            for(int j=0;j<board.size();j++){
                word.push_back(board[i][j]);
            }
            temp.push_back(word);
        }

        ans.push_back(temp);
        return;
    }
    bool isSafe(vector<vector<char>>&board,int col ,int row){
        for (int i = col; i >= 0; i--) {
            if (board[row][i] == 'Q') return false;
        }
        int n = board.size();
        int r = row-1;
        int c = col-1;
        while(r>=0 && c>=0){
            if(board[r][c]=='Q'){
                return false;
            }
            r--;
            c--;
        }

        r = row+1;
        c = col-1;
        while(r<n && c>=0){
            if(board[r][c]=='Q'){
                return false;
            }
            r++;
            c--;
        }

        return true;

    }
    void solve(vector<vector<char>>&board,vector<vector<string>>&ans,int col){
        if(col>=board.size()){
            saveans(board,ans);
            return;
        }

        for(int i=0;i<board.size();i++){
            if(isSafe(board,col,i)){
                board[i][col] = 'Q';
                solve(board,ans,col+1);
                board[i][col] = '.';
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>>board(n,vector<char>(n,'.'));
        vector<vector<string>>ans;
        solve(board,ans,0);
        return ans;
    }
};