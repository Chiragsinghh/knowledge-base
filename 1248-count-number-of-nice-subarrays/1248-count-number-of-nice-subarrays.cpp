class Solution {
public:
    int atMost(vector<int>& nums, int k){
        if(k<0) return 0;
        int l=0;
        int ans =0;
        int oddcount =0;

        for(int r=0;r<nums.size();r++){
            if(nums[r]%2!=0){
                oddcount++;
            }

            while(oddcount>k){
                if(nums[l]%2!=0){
                    oddcount--;
                }
                l++;
            }
            ans += (r-l+1);
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
        
    }
};