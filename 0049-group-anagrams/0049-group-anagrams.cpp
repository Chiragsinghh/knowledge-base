class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>ans;

        for(string word:strs){
            string a = word;
            sort(a.begin(),a.end());
            mp[a].push_back(word);
        }

        for(auto pair:mp){
            ans.push_back(pair.second);
        }

        return ans;
    }
};