class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector <vector <int> > adj(n);
        vector <bool> vis(n, 0);

        for (auto edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int cc = 0;
        for (int i = 0; i < n; i++)
            if (!vis[i]) {
                dfs(i, adj, vis);
                cc++;
            }
        
        return cc;
    }

    void dfs(int u, vector <vector <int> >& adj, vector <bool> &vis) {
        if (!vis[u]) {
            vis[u] = 1;
            for (auto v : adj[u])
                dfs(v, adj, vis);
        }
    }
};
