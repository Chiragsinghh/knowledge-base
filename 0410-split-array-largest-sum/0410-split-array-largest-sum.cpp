class Solution {
public:
    bool solve(vector<int> &arr, int mid,int m){
        int sum=0;
        int sc=1;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]>mid) return false;
            if(sum+arr[i]<=mid){
                sum+=arr[i];
            }else{
                sc++;
                sum = arr[i];
            }
        }
        
        return sc<=m;
        
    }
    int splitArray(vector<int>& nums, int k) {

        if(k>nums.size()) return -1;
        
        int start =0;
        int end =0;
        
        for(int p:nums){
            end+=p;
        }
        int ans =-1;
        
        while(start<= end){
            int mid = start + (end - start) / 2;
            if(solve(nums,mid,k)){
                end = mid-1;
                ans = mid;
            }else{
                start = mid+1;
            }
        }
        
        return ans;
        
        
    }
};
