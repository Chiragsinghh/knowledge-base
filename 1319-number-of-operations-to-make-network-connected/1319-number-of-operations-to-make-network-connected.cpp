class Solution {
public:
    void dfs(int src,unordered_map<int,vector<int>>&adj,unordered_map<int,bool>&vis){
        vis[src] = true;

        for (auto nbr : adj[src]) {
            if (!vis[nbr]) {
                dfs(nbr, adj, vis);
            }
        }
        
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int component =0;
        int edges =0;
        unordered_map<int,vector<int>>adj;
        unordered_map<int,bool>vis;

        for(int i=0;i<connections.size();i++){
            int u =connections[i][0];
            int v =connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
            edges++;
        }

        if(edges<n-1) return -1;
        
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                dfs(i,adj,vis);
                component++;
            }    
        }

        return component-1;
    }
};