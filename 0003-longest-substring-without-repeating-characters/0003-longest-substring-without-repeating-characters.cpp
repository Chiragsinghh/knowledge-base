class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int i=-1;
        int j=0;
        int ans =0;

        while(j<s.size()){
            mp[s[j]]++;

            while(mp[s[j]]>1){
                i++;
                mp[s[i]]--;    
            }

            ans = max(j-i,ans);
            j++;
        }

        return ans;
    }
};