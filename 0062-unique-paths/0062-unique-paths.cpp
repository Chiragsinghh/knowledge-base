class Solution {
public:
    int solve(int m,int n,int i,int j,vector<vector<int>>&dp){
        if(i >= m || j >= n) return 0;
        if(dp[i][j]!=0){
            return dp[i][j];
        }
        if(i == m-1 && j == n-1) return 1;
        return dp[i][j]=solve(m,n,i+1,j,dp)+solve(m,n,i,j+1,dp);
    }
    int uniquePaths(int m, int n) {
        //if(i >= m || j >= n) return 0;
        vector<vector<int>>dp(m,vector<int>(n,0));                                                                  
        return solve(m, n, 0, 0,dp);     
    }
};