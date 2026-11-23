class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<long long,vector<pair<long long,long long>>>adj;
        const int MOD = 1e9 +7;

        for(int i=0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<long long>ways(n,0);
        ways[0]=1;
        vector<long long>dist(n,LLONG_MAX);
        dist[0]=0;

        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<>>q;

        q.push({0,0});

        while(!q.empty()){
            auto [time,node] = q.top();
            q.pop();

            if(time>dist[node]){
                continue;
            }

            for(auto [nbr,val]:adj[node]){
                if(val+time<dist[nbr]){
                    dist[nbr]=val+time;
                    ways[nbr] = ways[node];
                    q.push({val+time,nbr});
                }else if(val+time == dist[nbr]){
                    ways[nbr] = (ways[nbr]+ways[node])%MOD;
                }
            }
        }

        return ways[n-1];

    }
};