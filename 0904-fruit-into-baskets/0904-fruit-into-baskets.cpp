class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int i=0;
        int k=0;

        int ans = INT_MIN;

        for(int j=0;j<fruits.size();j++){
            if(mp[fruits[j]]==0){
                while(k==2){
                    mp[fruits[i]]--;
                    if(mp[fruits[i]]==0){
                        k--;
                    }
                    i++;
                }

                mp[fruits[j]]++;
                k++;
            }else{
                mp[fruits[j]]++;
            }
            ans = max(ans,j-i+1);

        }

        return ans;
    }
};