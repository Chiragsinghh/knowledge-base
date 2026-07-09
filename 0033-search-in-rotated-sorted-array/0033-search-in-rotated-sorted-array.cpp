class Solution {
public:
    int findpivot(vector<int>nums,int l,int r){
        int ans =-1;
        if(nums[l]<nums[r]){
            return r;
        }
        while(l<=r){
            int mid =(r+l)/2;
            if(l==r) return mid;
            if(mid+1<nums.size() && nums[mid]>nums[mid+1]){
                ans = mid;
                return ans;
            }else if(mid-1>=0 && nums[mid]<nums[mid-1]){
                ans = mid-1;
                return ans;
            }
            else if(nums[mid]>nums[l]){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
    int bsearch(vector<int>& nums,int start,int end,int target){
        int ans =-1;

        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid]==target){
                return mid;
            }if(nums[mid]>target){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return ans;
    }
    int search(vector<int>& nums, int target) {
        int pivot =findpivot(nums,0,nums.size()-1);
        cout<<pivot;

        int ans =-1;
        if(target<= nums[pivot] && target>=nums[0]){
            ans =bsearch(nums,0,pivot,target);
        }else{
            ans =bsearch(nums,pivot+1,nums.size()-1,target);
        }

        return ans;
    }
};