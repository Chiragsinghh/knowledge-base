class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>>adj;
        const int MOD = 1e9 + 7;

        for(int i=0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u, w});
        }

        vector<long long>dist(n,LLONG_MAX);
        vector<int> ways(n, 0);
        ways[0]=1;
        dist[0] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0,0});

        while(!pq.empty()){
            auto [cost, u] = pq.top();
            pq.pop();

            if (cost > dist[u]) continue;


            for(auto [v, w] : adj[u]){
                long long newCost = cost + w;
                if (newCost < dist[v]) {
                    dist[v] = newCost;
                    ways[v] = ways[u];
                    pq.push({newCost, v});
                } else if (newCost == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }

        }

        return ways[n - 1];


    }
};