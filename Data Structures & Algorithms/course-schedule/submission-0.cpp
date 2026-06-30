class Solution {
public:
    vector <vector <int> > g;
    vector <bool> vis;
    bool cycle;

    void dfs(int u, unordered_set <int> path) {
        if (vis[u]) {
            if (path.contains(u))
                cycle = true;
            return;
        }
        vis[u] = true;

        path.insert(u);
        for (auto v : g[u])
            dfs(v, path);
        path.erase(u);
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        g = vector <vector <int> > (numCourses, vector <int> ());
        vis = vector <bool> (numCourses, 0);
        cycle = false;

        for (auto e : prerequisites) {
            int u = e[1], v = e[0];
            g[u].push_back(v);
        }
        for (int i = 0; i < numCourses; i++)
            if (not vis[i])
                dfs(i, unordered_set <int> ());
        
        bool allvis = true;
        for (auto u : vis)
            allvis &= u;
        
        return allvis and not cycle;
    }
};
