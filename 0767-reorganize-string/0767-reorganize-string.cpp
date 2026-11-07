struct cmp{
    static bool operator()(const pair<char,int>a,const pair<char,int>b){
        return a.second < b.second;
    }
};
class Solution {
public:
    string reorganizeString(string s) {
        int total_length = s.size();
        int max_allowed = (s.size() + 1)/2;
        if(s.size()==1) return s;

        string ans = "";
        unordered_map<char,int>mp;
        priority_queue<pair<char,int>,vector<pair<char,int>>, cmp>pq;

        for(auto ch:s){
            mp[ch]++;
        }

        for (auto pair : mp) {
            if (pair.second > max_allowed) return "";
            pq.push(pair);
        }

        while (pq.size() >= 2) {
            auto first = pq.top(); pq.pop();
            auto second = pq.top(); pq.pop();

            ans.push_back(first.first);
            ans.push_back(second.first);

            first.second--;
            second.second--;

            if (first.second > 0) pq.push(first);
            if (second.second > 0) pq.push(second);
        }

        if (!pq.empty()) {
            auto last = pq.top(); pq.pop();
            ans.push_back(last.first);
        }

        return ans;
        
    }
};