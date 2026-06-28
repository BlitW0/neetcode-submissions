class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector <vector <int> > adj(n);
        vector <bool> vis(n, 0);

        for (auto edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = dfs(0, -1, adj, vis);
        for (int i = 0; i < n; i++)
            ans = ans && vis[i];
        return ans;
    }

    bool dfs(int u, int prev, vector <vector <int> >& adj, vector <bool> &vis) {
        bool ret = true;
        if (!vis[u]) {
            vis[u] = true;
            for (int v : adj[u]) {
                if (vis[v] && v != prev) // Found cycle
                    return false;
                ret = ret && dfs(v, u, adj, vis);
            }
        }
        return ret;
    }
};
