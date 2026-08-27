class Solution {
public:
    bool check(string s, vector<string>& wordDict){
        for(auto i:wordDict){
            if(s==i){
                return true;
            }
        }

        return false;
    }
    bool solve(string s, vector<string>& wordDict,int start,vector<int>&dp){
        if(start == s.size()) return true;

        if(dp[start] != -1) return dp[start];

        string word = "";
        bool flag = false;

        for(int i=start;i<s.size() ;i++){
            word = word+s[i];
            if(check(word,wordDict)){
                flag = flag || solve(s,wordDict,i+1,dp);
            }
        }
        dp[start] = flag;
        return dp[start];
    }
    bool solvedu(string s, vector<string>& wordDict,vector<bool>& dp){
        for(int start=s.size() -1 ;start>=0 ;start--){
            string word = "";
            bool flag = false;
            for(int i= start ;i<s.size();i++){
                word=word+s[i];
                if(check(word,wordDict)){
                flag = flag || dp[i+1];
                }
            dp[start] = flag;
            }
        }

        return dp[0];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool>dp(s.size()+1,true);
        return solvedu(s,wordDict,dp);

    }
};