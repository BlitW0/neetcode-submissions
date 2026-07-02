class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& lst) {
        unordered_set <string> str;
        for (auto w : lst)
            str.insert(w);
        
        if (not str.contains(end))
            return 0;
        
        queue <pair <string, int> > q;
        q.push({begin, 1});

        while (not q.empty()) {
            string word = q.front().first;
            int dist = q.front().second;
            q.pop();

            // modify char at every position of word
            // to get its neighbours
            for (int i = 0; i < word.length(); i++) {
                string nei = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    nei[i] = c;
                    if (nei == end)
                        return dist + 1;
                    
                    if (str.contains(nei)) {
                        q.push({nei, dist + 1});
                        str.erase(nei); // mark as processed by removing
                    }
                }
            }
                    
        }

        return 0;
    }
};
