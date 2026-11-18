class Solution {
public:
    bool solve(int src,vector<int>& unsafe,vector<vector<int>>& graph){
        if(unsafe[src]!=0){
            return unsafe[src] ==2 ;
        }

        unsafe[src]=1;

        for(int nbr:graph[src]){
            if(!solve(nbr,unsafe,graph)){
                return false;
            }
        }

        unsafe[src]=2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>unsafe(graph.size(),0);
        vector<int>ans;

        for(int i=0;i<graph.size();i++){
                if(solve(i,unsafe,graph)){
                    ans.push_back(i);
                }

        }

        return ans;
    }
};