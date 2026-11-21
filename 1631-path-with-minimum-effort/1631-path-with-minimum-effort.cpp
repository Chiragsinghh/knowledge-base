class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        // Stores minimum effort required to reach (x, y)
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        
        // Min-heap storing {effort, x, y}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
            int effort = top[0];
            int x = top[1];
            int y = top[2];
            
            // Reached destination
            if (x == n - 1 && y == m - 1) return effort;
            
            // Skip outdated entries in the priority queue
            if (effort > dist[x][y]) continue;
            
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int newEffort = max(effort, abs(heights[x][y] - heights[nx][ny]));
                    if (newEffort < dist[nx][ny]) {
                        dist[nx][ny] = newEffort;
                        pq.push({newEffort, nx, ny});
                    }
                }
            }
        }
        return 0;
    }
};
