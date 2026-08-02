class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        if (words.size() < 2)
            return words.empty() ? "" : words[0];

        vector g(26, vector <int> ());
        vector <int> indeg(26, 0);
        vector <bool> seen(26, 0);
        int chars = 0;

        for (string word : words)
            for (char c : word)
                if (not seen[c - 'a']) {
                    seen[c - 'a'] = 1;
                    chars++;
                }

        for (int i = 0; i < words.size() - 1; i++) {
            string &w1 = words[i], &w2 = words[i + 1];
            int mn = min(w1.size(), w2.size());

            // w2 is prefix of w1, but w1 is longer and comes first
            // impossible lexicographically
            if (w1.size() > w2.size() 
                and w1.substr(0, mn) == w2.substr(0, mn))
                return "";
            
            for (int j = 0; j < mn; j++) {
                int u = w1[j] - 'a', v = w2[j] - 'a';
                if (u != v) {
                    if (find(g[u].begin(), g[u].end(), v) == g[u].end()) {
                        g[u].push_back(v);
                        indeg[v]++;
                    }
                    break;
                }
            }
        }

        queue <int> q;
        string ans;
        for (int i = 0; i < 26; i++)
            if (seen[i] and indeg[i] == 0) {
                q.push(i);
                ans += char(i + 'a');
            }
        
        int proc = 0;
        while (not q.empty()) {
            int u = q.front();
            q.pop();
            proc++;

            for (int v : g[u]) {
                indeg[v]--;
                if (indeg[v] == 0) {
                    q.push(v);
                    ans += char(v + 'a');
                }
            }
        }

        return proc == chars ? ans : "";
    }
};
