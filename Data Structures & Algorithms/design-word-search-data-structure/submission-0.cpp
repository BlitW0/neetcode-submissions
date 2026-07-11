class Node {
public:
    Node* child[26];
    bool end;
    Node () {
        end = false;
        fill(child, child + 26, nullptr);
    }
};

class WordDictionary {
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (not cur->child[i]) cur->child[i] = new Node();
            cur = cur->child[i];
        }
        cur->end = true;
    }
    
    bool search(string word, int idx=0, Node* node=nullptr) {
        Node* cur = node ? node : root;
        for (int j = idx; j < word.size(); j++) {
            char c = word[j];
            if (c == '.') {
                for (int i = 0; i < 26; i++)
                    if (cur->child[i] 
                        and search(word, j + 1, cur->child[i]))
                        return true;
                return false;
            } else cur = cur->child[c - 'a'];
            
            if (not cur) return false;
        }
        return cur->end;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */