class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int val = -1;
        unordered_map<int,int>mp;
        

        for(int i=arr.size()-1;i>=0;i--){
            mp[i]=val;
            val = max(val,arr[i]);
        }
        
        for(auto vals:mp){
            arr[vals.first]=vals.second;
        }
        return arr;
    }
};