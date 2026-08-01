class Solution {
public:
    int solve(vector<int>& nums,int mid){
        int sum =0;
        for(auto num:nums){
            sum += (num + mid-1)/mid;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1;
        int end = *max_element(nums.begin(),nums.end());
        int ans = INT_MAX;

        while(start<=end){
            int mid = (start+end)/2;
            int sum = solve(nums,mid);
            if(sum<=threshold){
                ans = mid;
                end= mid-1; 
            }else{
                start = mid+1;
            }
            
        }

        return ans==INT_MAX?*max_element(nums.begin(),nums.end()):ans;

    }
};