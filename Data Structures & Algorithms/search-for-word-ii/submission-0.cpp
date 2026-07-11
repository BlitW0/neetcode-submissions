class TrieNode {
public:
    TrieNode* child[26];
    string word;
    TrieNode() {
        fill(child, child + 26, nullptr);
    }
};

class Trie {
    TrieNode* root;
public:
    TrieNode* getRoot() { return root; }

    Trie(vector <string>& words) {
        root = new TrieNode();
        for (string& word : words)
            insert(word);
    }
    
    void insert(string& word) {
        TrieNode* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (not cur->child[i])
                cur->child[i] = new TrieNode();
            cur = cur->child[i];
        }
        cur->word = word;
    }

    ~Trie() {
        delTrie(root);
    }
    void delTrie(TrieNode* root) {
        for (int i = 0; i < 26; i++)
            if(root->child[i])
                delTrie(root->child[i]);
        delete root;
    }
};

class Solution {
public:
    void dfs(int x, int y, TrieNode* node, vector<vector<char>>& board, vector<string>& res) {
        int n = board.size(), m = board[0].size();
        if (x < 0 or x >= n or y < 0 or y >= m)
            return;
        
        char c = board[x][y];
        if (c == '#') return;

        node = node->child[c - 'a'];
        if (not node) return;
        if (not node->word.empty()) {
            res.push_back(node->word);
            node->word.clear(); // add every word only once
        }

        board[x][y] = '#';
        dfs(x + 1, y, node, board, res);
        dfs(x - 1, y, node, board, res);
        dfs(x, y + 1, node, board, res);
        dfs(x, y - 1, node, board, res);
        board[x][y] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie(words);
        vector <string> res;
        
        int n = board.size(), m = board[0].size();
        for (int x = 0; x < n; x++)
            for (int y = 0; y < m; y++) {
                TrieNode* root = trie.getRoot();
                if (root->child[board[x][y] - 'a'])
                    dfs(x, y, root, board, res);
            }
        return res;
    }
};