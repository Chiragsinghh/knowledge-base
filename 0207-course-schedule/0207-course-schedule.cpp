class Solution {
public:
    void solve(int v,unordered_map<int,vector<int>>&adjlist,unordered_map<int,int>&indegree,vector<int>&ans){
        queue<int>q;
        for(int i=0;i<v;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto nbr:adjlist[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0) q.push(nbr);
            }
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int ,vector<int>>adjlist;
        unordered_map<int ,bool> visited;
        unordered_map<int,int>indegree;
        vector<int>ans;
        for(auto node:prerequisites){
            adjlist[node[1]].push_back(node[0]);
            indegree[node[0]]++;
        }
       
            solve(numCourses,adjlist,indegree,ans);
        
        return ans.size() == numCourses;
        
    }
};