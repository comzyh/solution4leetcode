class Trie {
    struct TrieNode {
        TrieNode* next[26];
        bool end;
        TrieNode() {
            end = false;
            fill(next, next + 26, nullptr);
        }
    };
private:
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *r = root;
        for (auto &c : word) {
            if (r->next[c - 'a'] == nullptr) {
                r->next[c - 'a'] = new TrieNode();
            }
            r = r->next[c - 'a'];
        }
        r->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *r = root;
        for (auto &c : word) {
            if (r->next[c - 'a'] == nullptr) {
                return false;
            }
            r = r->next[c - 'a'];
        }
        return r->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *r = root;
        for (auto &c : prefix) {
            if (r->next[c - 'a'] == nullptr) {
                return false;
            }
            r = r->next[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
