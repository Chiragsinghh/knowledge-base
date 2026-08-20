class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>&arr,int target,vector<int>&temp,int index){
        if(target==0){
            ans.push_back(temp);
        }
        if(target<0){
            return;
        }

        for(int i=index;i<arr.size();i++){
            temp.push_back(arr[i]);
            helper(arr,target-arr[i],temp,i);
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        helper(candidates,target,temp,0);
        return ans;

    }
};