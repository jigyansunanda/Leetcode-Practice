class Trie {
private:
    Trie* child[26] = {};
    bool isWordEnd = false;

public:
    Trie() {}

    void insert(string word) {
        Trie* node = this;
        for (auto &ch : word) {
            if (node->child[ch - 'a'] == NULL) node->child[ch - 'a'] = new Trie();
            node = node->child[ch - 'a'];
        }
        node->isWordEnd = true;
    }

    bool search(string word) {
        Trie* node = this;
        for (auto &ch : word) {
            if (node->child[ch - 'a'] == NULL) return false;
            node = node->child[ch - 'a'];
        }
        return node->isWordEnd;
    }

    bool startsWith(string prefix) {
        Trie* node = this;
        for (auto &ch : prefix) {
            if (node->child[ch - 'a'] == NULL) return false;
            node = node->child[ch - 'a'];
        }
        return true;
    }
};