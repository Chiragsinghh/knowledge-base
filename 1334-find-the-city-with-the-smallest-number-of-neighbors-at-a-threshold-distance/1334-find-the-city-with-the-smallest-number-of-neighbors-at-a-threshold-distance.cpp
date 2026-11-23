class Solution {
public:
    void solve(int src, int n,
           unordered_map<int, vector<pair<int,int>>> &adj,
           unordered_map<int,int> &neighbours,
           int thresh)
{
    vector<int> dis(n, INT_MAX);

    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;

    dis[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {
        auto [dist, u] = pq.top();
        pq.pop();

        if(dist > dis[u]) continue;

        for(auto &[v, w] : adj[u]) {
            if(dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(dis[i] <= thresh)
            neighbours[src]++;
    }
}
    int findTheCity(int n, const vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        unordered_map<int,int>neighbours;
        
        for(int i=0;i<n;i++){
            solve(i,n,adj,neighbours,distanceThreshold);
        }
        int neigh =INT_MAX;
        int ans=-1;

        for (int i = 0; i < n; i++) {
    if (neighbours[i] <= neigh) {
        neigh = neighbours[i];
        ans = i;
    }
}

        return ans;
    }
};