class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector <vector <int> > g(numCourses, vector <int> ());
        vector <int> indegree(numCourses, 0);

        for (auto e : prerequisites) {
            int u = e[1], v = e[0];
            g[u].push_back(v);
            indegree[v]++;
        }

        queue <int> bfs;
        for (int i = 0; i < numCourses; i++)
            if (not indegree[i])
                bfs.push(i);
        
        int done = 0;
        while (not bfs.empty()) {
            int u = bfs.front();
            bfs.pop();
            done++; // visited

            for (auto v : g[u])
                if (not --indegree[v]) // add only when course has no prereqs left, u taken so reduce prereq for v by 1
                    bfs.push(v);
        }

        return done == numCourses;
    }
};
