
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges,
                     string labels, int k) {

        // 1. Build adjacency list
        vector<vector<pair<int,int>>> adj(n);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
        }

        // 2. Distance for each (node, consecutive count)
        const long long INF = LLONG_MAX;

        vector<vector<long long>> dist(
            n, vector<long long>(k + 1, INF)
        );

        // {cost, node, consecutive count}
        using State = tuple<long long, int, int>;

        priority_queue<
            State,
            vector<State>,
            greater<State>
        > pq;

        // 3. Initially, we are at node 0
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        // 4. Dijkstra
        while (!pq.empty()) {

            auto [cost, curr, cnt] = pq.top();
            pq.pop();

            // Ignore outdated states
            if (cost > dist[curr][cnt])
                continue;

            // Destination reached
            if (curr == n - 1)
                return cost;

            // Explore adjacent nodes
            for (auto &[node, weight] : adj[curr]) {

                int newCnt;

                if (labels[curr] == labels[node]) {
                    newCnt = cnt + 1;
                }
                else {
                    newCnt = 1;
                }

                // Invalid consecutive sequence
                if (newCnt > k)
                    continue;

                long long newCost = cost + weight;

                if (newCost < dist[node][newCnt]) {

                    dist[node][newCnt] = newCost;

                    pq.push({
                        newCost,
                        node,
                        newCnt
                    });
                }
            }
        }

        return -1;
    }
};
