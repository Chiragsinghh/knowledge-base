class Solution {
public:
    int atmost(vector<int>& nums, int k){
        unordered_map<int,int>mp;
        int cnt =0;
        int ans =0;

        int l=0;

        for(int r=0;r<nums.size();r++){
            if(mp[nums[r]]==0){
                cnt++;
            }
            mp[nums[r]]++;

            while(cnt>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    cnt--;
                }
                l++;
            }

            ans+= (r-l+1);
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return atmost(nums,k) - atmost(nums,k-1);
    }
};