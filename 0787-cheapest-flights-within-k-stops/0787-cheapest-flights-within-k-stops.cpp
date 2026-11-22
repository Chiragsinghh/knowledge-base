class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        int ans = INT_MAX;

        for(int i=0;i<flights.size();i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            adj[u].push_back({v,w});
        }

        vector<int>dist(n,INT_MAX);
        queue<pair<int, pair<int, int>>> pq;
        pq.push({0,{src,0}});

        while(!pq.empty()){
            auto [stops, info] = pq.front();
            auto [curr, cost] = info;

            pq.pop();

            if(k<stops){
                continue;
            }

            if(curr == dst){
                ans = min(cost,ans);
            }

            for(auto [nbr, val] : adj[curr]){
                if(cost +val < dist[nbr]){
                    dist[nbr] = cost +val;
                    pq.push({stops+1,{nbr,dist[nbr]}});

                }
            }

        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};