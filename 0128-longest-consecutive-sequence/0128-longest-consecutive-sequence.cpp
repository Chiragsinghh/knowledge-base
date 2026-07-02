class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int count=1;
        int temp=1;
        sort(nums.begin(),nums.end());
        int i=1;
        if(nums.size()==0) return 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                continue;
            }
            else if(nums[i]==nums[i-1]+1){
                temp++;
                count=max(temp,count);
            }
            else{
                temp=1;
            }
        }
        return count;
    }
};