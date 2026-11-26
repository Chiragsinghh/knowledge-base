class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<pair<int,int>>>adj;
        unordered_map<int,bool>vis;

        for(int i=0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back({v,1});
            adj[v].push_back({u,0});
        }
        queue<int>q;
        q.push(0);
        vis[0] = true;
        int ans =0;

        while(!q.empty()){
            int src = q.front();
            q.pop();

            for(auto nbrs:adj[src]){
                int nbr = nbrs.first;
                int dir = nbrs.second;
                if(!vis[nbr]){
                    vis[nbr] = true;
                    if(dir==1){
                        ans++;
                    }        
                    q.push(nbr);
                }
            }
        }
        return ans;


    }
};