class Solution {
public:
    // REMOVED '&' from profit and transaction to pass them BY VALUE
    int solve(int i, vector<int>& prices, int transaction, int buy,vector<vector<vector<int>>>&dp){
        if (i == prices.size() || transaction == 0) {
            return 0;
        }

        if(dp[i][transaction][buy]!=-1){
            return dp[i][transaction][buy];
        }

        int profit=0;
        if(buy){
            // Choice 1: Skip buying today
            profit = max(solve(i+1, prices, transaction, 0,dp)-prices[i],solve(i+1, prices, transaction, 1,dp));
        } else {
            profit = max(solve(i+1,prices,transaction-1, 1,dp)+prices[i],solve(i+1,prices,transaction, 0,dp));
        }

        return dp[i][transaction][buy]= profit;
    }

    int maxProfit(vector<int>& prices) {
        
        // ans is still passed by reference since we want ALL branches to update the global maximum
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(3,vector<int>(2,-1)));
        return solve(0, prices, 2, 1,dp);
        //return ans;
    }
};
