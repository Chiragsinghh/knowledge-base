class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc =1;
        int dec =1;
        int ans = INT_MIN;


        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1] > 0){
                inc++;
                ans = max(ans,inc);
                dec=1;
                
            }
            else if(nums[i]-nums[i-1] < 0){
                dec++;
                ans = max(ans,dec);
                inc =1;
            }else{
                inc=1;
                dec=1;
            }
            
        }
        if(ans == INT_MIN) return 1;
        return ans;
    }
};