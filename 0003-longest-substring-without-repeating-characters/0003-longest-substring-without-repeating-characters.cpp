class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>idx(128,-1);
        vector<int>f(128,0);

        int ans = INT_MIN;

        int left =0;

        for(int right =0;right<s.size();right++){
            auto a = s[right];
            
            if(idx[a]>=left){
                left = idx[a]+1;
            }

            idx[a] = right;
            ans = max(ans,right-left+1);
            
        }

        return ans==INT_MIN?0:ans;
    }
};