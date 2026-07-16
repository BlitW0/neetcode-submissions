class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Bellman ford algorithm
        // Do X rounds to process all shortest paths with X edges
        // Every round consider all edges, check if the dist to
        // dst of edge can be reduced using this one

        vector <int> dist(n, INT_MAX);
        dist[src] = 0;

        // do k+1 rounds for k+1 edges
        for (int i = 1; i <= k + 1; i++) {
            vector <int> nxt = dist; // use temp so that paths of only length i are considered
            for (auto &e : flights) {
                int u = e[0], v = e[1], w = e[2];
                if (dist[u] == INT_MAX) continue;

                // don't put updated values in cur level
                // to prevent more than 1 edge being considered
                // in one round
                if (dist[u] + w < nxt[v]) 
                    nxt[v] = dist[u] + w;
            }
            dist = nxt;
        }
        
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};