class Solution {
public:
    void helper(vector<int>& nums, int i, vector<int>& temp, vector<vector<int>>& ans) {
        // Base case: Add the current subset to the answer
        ans.push_back(temp);

        for (int j = i; j < nums.size(); j++) {
            // Skip duplicates to prevent duplicate subsets
            if (j > i && nums[j] == nums[j - 1]) {
                continue;
            }

            temp.push_back(nums[j]);   // Fix 1: Push nums[j], not nums[i]
            helper(nums, j + 1, temp, ans);
            temp.pop_back();           // Backtrack
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>temp;
        vector<vector<int>>ans;
        helper(nums,0,temp,ans);
        return ans;
    }
};