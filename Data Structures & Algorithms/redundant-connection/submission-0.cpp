class Solution {
    class DSU {
        int N;
        vector <int> par, size;
    public:
        DSU(int N) : N(N), par(N), size(N, 1) {
            iota(par.begin(), par.end(), 0);
        }

        int find(int x) {
            if (x == par[x]) return x;
            return par[x] = find(par[x]);
        }

        bool merge(int x, int y) {
            x = find(x), y = find(y);
            if (x == y) return false;
            if (size[x] < size[y]) swap(x, y);
            par[y] = x, size[x] += size[y];
            return true;
        }
    };
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);

        for (auto& e : edges) {
            int u = e[0] - 1, v = e[1] - 1;
            if (not dsu.merge(u, v))
                return e;
        }
        return {};
    }
};