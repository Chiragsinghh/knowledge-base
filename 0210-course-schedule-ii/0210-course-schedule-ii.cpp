class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>ind(numCourses,0);

        for(auto pair:prerequisites){
            adj[pair[1]].push_back(pair[0]);
            ind[pair[0]]++;
        }

        queue<int>q;
        vector<int> ans;
        for(int i=0;i<ind.size();i++){
            if(ind[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            ans.push_back(curr);
            for(int nbr:adj[curr]){
                ind[nbr]--;
                if(ind[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        if(ans.size() != numCourses) return {};
        return ans;;
    }
};