struct cmp {
    bool operator()(pair<int,int>& a, pair<int,int>& b) {
        return a.second < b.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   cmp> pq;
        
        unordered_map<int,int>mp;
        vector<int>ans;

        for(int num:nums){
            mp[num]++;
        }

        for(auto pair:mp){
            pq.push({pair.first,pair.second});
        }

        while(k){
            ans.push_back(pq.top().first);
            pq.pop();
            k--;
        }

        return ans;
    }
};