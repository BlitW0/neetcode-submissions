class Solution {
public:
    typedef pair <int, int> pi;
    typedef vector <int> vi;
    const int INF = INT_MAX;

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Dijkstra from source, min time is max of all distances
        // if any node is unreachable, -1
        
        // make graph
        vector <vector <pi> > G(n);
        for (auto e : times) {
            int u = e[0], v = e[1], w = e[2];
            u -= 1, v -= 1;
            G[u].emplace_back(v, w);
        }

        vi dist(n, INF);
        priority_queue <pi, vector <pi>, greater <> > pq;
        
        k -= 1;
        dist[k] = 0;
        pq.emplace(0, k);
        while (not pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            // skip stale dist entries
            // works as repl for processed array
            if (d > dist[u]) continue;

            for (auto [v, w] : G[u])
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
        }

        int mxtime = *max_element(dist.begin(), dist.end());
        
        return mxtime == INF ? -1 : mxtime;
    }
};