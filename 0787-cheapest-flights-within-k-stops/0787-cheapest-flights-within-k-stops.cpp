class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        int ans = INT_MAX;
        vector<int>dist(n,INT_MAX);
        dist[src]=0;

        for(int i=0;i<flights.size();i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            adj[u].push_back({v,w});
        }


        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});

        while(!q.empty()){
            auto [cuk,info] = q.front();
            auto [node,cost] = info;
            q.pop();


            if(cuk>k){
                continue;
            }

            for(auto nbrinfo:adj[node]){
                int nbr = nbrinfo.first;
                int weight = nbrinfo.second;

                if(cost +weight < dist[nbr]){
                    dist[nbr] = cost +weight;
                    q.push({cuk+1,{nbr,dist[nbr]}});

                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];



    }
};