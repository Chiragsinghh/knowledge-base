
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long idx = nums.size()/2;
        long long mn = nums[idx];
        long long ans = 0;


        for (int i = 0; i < nums.size(); i++) {
            ans += abs(nums[i] - mn);
        }

        return ans;
    }
};
