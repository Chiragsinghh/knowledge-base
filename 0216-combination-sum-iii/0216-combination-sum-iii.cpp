class Solution {
public:
    void helper(int k,int n,int i,vector<int>&temp,vector<vector<int>>& ans){
        if(n==0 && k==0){
            ans.push_back(temp);
            return;
        }

        if (i > 9 || n < 0 || k < 0) {
            return;
        }

        temp.push_back(i);
        helper(k-1,n-i,i+1,temp,ans);
        temp.pop_back();
        helper(k,n,i+1,temp,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        vector<vector<int>>ans;

        helper(k,n,1,temp,ans);
        return ans;
    }
};