class Solution {
public:
    bool solve(vector<vector<char>>& board,string& word,int r,int c,int i){
        if(i>= word.size()){
            return true;
        }

        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c]!= word[i] ){
            return false;
        }

        char temp =board[r][c];
        board[r][c]='%';

        bool found= solve(board,word,r-1,c,i+1) || solve(board,word,r+1,c,i+1) || solve(board,word,r,c+1,i+1) || solve(board,word,r,c-1,i+1);

        board[r][c]=temp;
        return found;

    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(solve(board,word,i,j,0)){
                    return true;
                }
            }
        }
        
        return false;
    }
};