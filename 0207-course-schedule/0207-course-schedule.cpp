class Solution {
public:
    bool dfs(int src,vector<bool>&vis,vector<bool>&pathvis,unordered_map<int,vector<int>>&adj){
        vis[src]=true;
        pathvis[src]=true;

        for(int nbr:adj[src]){
            if(!vis[nbr]){
                dfs(nbr,vis,pathvis,adj);
            }
            if(pathvis[nbr]){
                return true;
            }
        }
        pathvis[src]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<bool>vis(numCourses,false);
        vector<bool>pathvis(numCourses,false);
        for(auto pair :prerequisites){
            int u = pair[0];
            int v=pair[1];

            adj[v].push_back(u);
        }

        for(auto pair:adj){
            if(!vis[pair.first]){
                if(dfs(pair.first,vis,pathvis,adj)){
                    return false;
                }
            }
        }
        return true;
    }
};