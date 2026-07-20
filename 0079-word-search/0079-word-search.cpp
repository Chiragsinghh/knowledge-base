class Solution {
public:
    bool solve(int i,int j,int idex,string& word,vector<vector<char>>& board,int &m,int &n){
        if(i<0 || i>=m || j<0 || j>=n){
            return false;
        }
        if(board[i][j]!=word[idex]){
            return false;
        }
        if(idex==word.size()-1){
            return true;
        }

        char og = board[i][j];
        board[i][j]='%';
        

        bool ans = solve(i+1,j,idex+1,word,board,m,n)|| 
        solve(i-1,j,idex+1,word,board,m,n) || 
        solve(i,j+1,idex+1,word,board,m,n) || 
        solve(i,j-1,idex+1,word,board,m,n);

        board[i][j]=og;
        return ans;


    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(solve(i,j,0,word,board,m,n)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};