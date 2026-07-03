class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int>mp;
        int n= grid.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[grid[i][j]]++;
            }
        }
        int a;
        int b;
        for(int i=1;i<=n*n;i++){
            if(mp[i]==0){
                b=i;
            }
            if(mp[i]>1){
                a=i;
            }
        }

        return {a,b};
    }
};