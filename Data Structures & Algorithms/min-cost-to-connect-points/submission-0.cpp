class Solution {
public:
    typedef pair <int, int> pi;

    int minCostConnectPoints(vector<vector<int>>& points) {
        auto mandist = [&](const auto& p1, const auto& p2) {
            return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
        };

        int n = points.size();
        vector <int> dist(n, INT_MAX);
        vector <bool> vis(n, 0);

        int edges = 0, node = 0, cost = 0;
        while (edges < n - 1) { // tree has n-1 edges
            // every time find node which has min dist from last
            // added node. don't need to check for every node
            // in MST because we already checked dist from it to 
            // all other nodes before adding it to MST

            vis[node] = 1;
            int nxt = -1;
            for (int i = 0; i < n; i++) {
                if (vis[i]) continue;

                int x = points[node][0], y = points[node][1];
                int nx = points[i][0], ny = points[i][1];

                int mandist = abs(x - nx) + abs(y - ny);
                dist[i] = min(dist[i], mandist);
                if (nxt == -1 or dist[i] < dist[nxt])
                    nxt = i; // pick as next, dist is min seen among all unincluded points and can be added in MST
            } 
            cost += dist[nxt];
            node = nxt;
            edges++;
        }

        return cost;
    }
};