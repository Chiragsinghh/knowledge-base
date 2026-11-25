class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<times.size();i++){
            int u= times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({v,w});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        unordered_map<int,bool>vis;
        int viscount =0;
        pq.push({0,k});
        int ans = INT_MAX;

        while(!pq.empty()){
            auto [time,curr] = pq.top();
            pq.pop();
            if(vis[curr]) continue;
            vis[curr]=true;
            viscount++;

            if(viscount == n) ans = min(time,ans);

            for(auto [nbr,wt]:adj[curr]){
                if(!vis[nbr]){
                    pq.push({time+wt,nbr});
                }
            }

        }

        return ans == INT_MAX?-1:ans;
    }
};