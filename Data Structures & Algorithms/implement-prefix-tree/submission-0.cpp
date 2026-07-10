class TrieNode {
    // Needs destructor for production code
    // for proper memory management, but this is fine for DSA
public:
    TrieNode* child[26];
    bool end;
    TrieNode() {
        end = false;
        fill(child, child + 26, nullptr);
    }
};

class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (not cur->child[i])
                cur->child[i] = new TrieNode();
            cur = cur->child[i];
        }
        cur->end = true;
    }
    
    bool search(string word, bool prefix=false) {
        TrieNode* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (not cur->child[i]) return false;
            cur = cur->child[i];
        }
        // if didn't find nullptr during traversal
        // word exists as prefix for sure
        return prefix ? true : cur->end;
    }
    
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * PrefixTree* obj = new PrefixTree();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */