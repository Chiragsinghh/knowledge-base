class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int color = 0;

        unordered_map<int, int> coloured;
        unordered_map<int, bool> vis;

        queue<int> q;

        for (int i = 0; i < graph.size(); i++) {
            if (!vis[i]) {
                vis[i] = true;
                coloured[i] = color;
                q.push(i);
            }

            while (!q.empty()) {
                int src = q.front();
                q.pop();

                for (int nbr : graph[src]) {
                    if (!vis[nbr]) {
                        vis[nbr] = true;
                        q.push(nbr);
                        coloured[nbr] = !coloured[src];
                    } else {
                        if (coloured[nbr] == coloured[src]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};