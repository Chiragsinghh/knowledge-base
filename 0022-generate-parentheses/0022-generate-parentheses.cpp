class Solution {
public:
vector<string> ans;
    void helper(int n,string temp,int open,int close){
        if(open+close == 2*n){
            ans.push_back(temp);
            return;
        }

        if(open<n){
            temp.push_back('(');
            helper(n,temp,open+1,close);
            temp.pop_back();

        }

        if(close<open){
            temp.push_back(')');
            helper(n,temp,open,close+1);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int open = 0;
        int close = 0;
        helper(n,"",open,close);
        return ans;
    }
};