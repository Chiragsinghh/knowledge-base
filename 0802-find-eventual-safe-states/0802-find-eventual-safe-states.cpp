class Solution {
public:
    bool isSafe(int src, vector<vector<int>>& graph, vector<int>& state) {
        if (state[src] != 0) {
            return state[src] == 2;
        }
        
        // Mark current node as visiting (tentatively unsafe)
        state[src] = 1;
        
        for (int nbr : graph[src]) {
            // If any neighbor is unsafe or leads to a cycle, src is also unsafe
            if (!isSafe(nbr, graph, state)) {
                return false;
            }
        }
        
        // All paths from src are safe
        state[src] = 2;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0);
        vector<int> ans;
        
        for (int i = 0; i < n; i++) {
            if (isSafe(i, graph, state)) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};
