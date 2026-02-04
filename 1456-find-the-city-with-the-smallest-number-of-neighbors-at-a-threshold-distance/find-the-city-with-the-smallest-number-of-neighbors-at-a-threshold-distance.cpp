class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        int minCount = INT_MAX;
        int res = -1;
        for (int src = 0; src < n; src++) {
            vector<int> dist(n,1e9);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>
                minH;
            minH.push({0, src});
            dist[src] = 0;
            while (!minH.empty()) {
                auto [d, node] = minH.top();
                minH.pop();

                if (d > dist[node])
                    continue;
                if (d > distanceThreshold)
                    continue;

                for (auto& [nextNode, nextD] : adj[node]) {
                    if (dist[nextNode] > d + nextD) {
                        dist[nextNode] = d + nextD;
                        minH.push({d + nextD, nextNode});
                    }
                }
            }

            int count = 0;
            for (int i = 0; i < n; i++) {
                if (i != src && dist[i] <= distanceThreshold) {
                    count++;
                }
            }

            if (count < minCount || (minCount == count && src > res)) {
                minCount = count;
                res = src;
            }
        }
        return res;
    }
};