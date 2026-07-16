class Solution {
public:
    typedef pair <int, int> pi;
    using T = tuple<int, int, int>;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // dijkstra, track {dist, stops} for each node
        // stops = 0 for source node

        vector <vector <pi> > g(n);
        for (auto& e : flights) {
            int u = e[0], v = e[1], w = e[2];
            g[u].push_back({v, w});
        }

        // keep dist for every stop number, might get optimal distance updates based on stop too
        vector dist(n, vector <int> (k + 2, INT_MAX));
        priority_queue <T, vector <T>, greater<> > pq;

        dist[src][0] = 0;
        pq.push({0, 0, src});
        while (not pq.empty()) {
            auto [s, d, u] = pq.top(); pq.pop();
            if (d > dist[u][s]) continue; // better dist found before

            for (auto& [v, w] : g[u]) {
                // only add if edges <= k + 1 and dist improved for that stop number
                if (s + 1 <= k + 1 and d + w < dist[v][s + 1]) {
                    dist[v][s + 1] = d + w;
                    pq.push({s + 1, dist[v][s + 1], v});
                }
            }
        }

        int val = *min_element(dist[dst].begin(), dist[dst].end());
        return val == INT_MAX ? -1 : val;
    }
};