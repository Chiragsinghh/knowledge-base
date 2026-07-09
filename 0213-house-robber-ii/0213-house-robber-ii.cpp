class Solution {
public:
    int solve(vector<int>& nums,int i,int n,vector<int>&dp){
        if(i>=n){
            return 0;
        }

        if(dp[i]!=-1){
            return dp[i];
        }
        int include=0,exclude=0;

    include = nums[i] + solve(nums,i+2,n,dp);
       exclude = 0+solve(nums,i+1,n,dp);
       

       return dp[i]= max(exclude,include);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int>dp(nums.size()+1,-1);
        vector<int>dp2(nums.size()+1,-1);
        return max(solve(nums,0,nums.size()-1,dp),solve(nums,1,nums.size(),dp2));
    }
};