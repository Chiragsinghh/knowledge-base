class Solution {
public:
    // Helper function with a memoization array (dp) to store already computed results
    int solve(vector<int>& nums, int target, vector<int>& dp) {
        // Base case 1: Found a valid combination
        if (target == 0) {
            return 1;
        }
        // Base case 2: Exceeded the target, invalid path
        if (target < 0) {
            return 0;
        }
        // Base case 3: Return already calculated result to save time
        if (dp[target] != -1) {
            return dp[target];
        }

        int totalWays = 0;
        // Loop through all numbers to try every possible choice for the current position
        for (int i = 0; i < nums.size(); i++) {
            totalWays += solve(nums, target - nums[i], dp);
        }

        // Store the result in the memoization table before returning
        return dp[target] = totalWays;
    }

    int combinationSum4(vector<int>& nums, int target) {
        // Initialize memoization array with -1 for all states up to target
        vector<int> dp(target + 1, -1);
        return solve(nums, target, dp);
    }
};
