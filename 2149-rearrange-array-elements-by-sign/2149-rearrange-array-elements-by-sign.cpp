class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;

        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                neg.push_back(nums[i]);
            }else{
                pos.push_back(nums[i]);
            }
        }

        int j=0,k=0;
        for(int i=0;i<nums.size();i=i+2){
            nums[i]=pos[k];
            nums[i+1]=neg[j];
            k++;
            j++;
        }

        return nums;
    }
};