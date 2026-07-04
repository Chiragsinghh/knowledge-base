class Solution {
public:
    int findPivotIndex(vector<int>& nums){
        int start=0;
        int end=nums.size()-1;
        int ans=-1;
        if(nums[start]<nums[end]) return end;


        while(start<=end){
            int mid=(start+end)/2;
            if(start==end) return mid;

            if(mid+1<nums.size() && nums[mid]>nums[mid+1]){
                return mid;
            }
            if(mid > start && nums[mid] < nums[mid - 1])
                return mid - 1;

            if(nums[mid] >= nums[start]){
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
}

    int binarysearch(int s,int e,vector<int>& nums,int target){
        while(s<=e){
            int mid=(s+e)/2;

            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {   
        int pivotindex=findPivotIndex(nums);
        int ans=-1;

        if(target>=nums[0] && target<=nums[pivotindex]){
            ans=binarysearch(0,pivotindex,nums,target);
        }
        else{
            ans=binarysearch(pivotindex+1,nums.size()-1,nums,target);
        }
        return ans;
    }
};