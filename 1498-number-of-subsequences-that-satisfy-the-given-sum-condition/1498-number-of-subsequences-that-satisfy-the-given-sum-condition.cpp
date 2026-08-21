class Solution {
public:
    long long power(long long a, int b) {
        long long ans = 1;

        while(b > 0) {
            if(b & 1)
                ans = (ans * a) % 1000000007;

            a = (a * a) % 1000000007;
            b /= 2;
        }

        return ans;
    }

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size() - 1;
        long long ans = 0;

        while(left <= right) {
            if(nums[left] + nums[right] <= target) {
                ans = (ans + power(2, right - left)) % 1000000007;
                left++;
            }
            else {
                right--;
            }
        }

        return ans;
    }
};