class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<vector<int>>q;
        q.push({0});
        vector<vector<int>>ans;

        while(!q.empty()){
            auto currpath = q.front();
            q.pop();

            int currnode = currpath.back();
            if(currnode == n-1){
                ans.push_back(currpath);
            }

            for(int nbr:graph[currnode]){
                auto newpath = currpath;
                newpath.push_back(nbr);
                q.push(newpath);
            }
        }

        return ans;

        
    }
};