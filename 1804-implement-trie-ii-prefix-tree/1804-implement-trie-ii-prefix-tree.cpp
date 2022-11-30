class Trie {
private:
    Trie* child[26];
    int endCount;

    int dfs(Trie* node) {
        int ans = node->endCount;
        for (int i = 0; i < 26; ++i) {
            if (node->child[i] != NULL) {
                ans += dfs(node->child[i]);
            }
        }
        return ans;
    }

public:
    Trie() {
        for (int i = 0; i < 26; ++i) child[i] = NULL;
        endCount = 0;
    }

    void insert(string word) {
        Trie* node = this;
        for (auto &c : word) {
            if (node->child[c - 'a'] == NULL) {
                node->child[c - 'a'] = new Trie();
            }
            node = node->child[c - 'a'];
        }
        node->endCount += 1;
    }

    int countWordsEqualTo(string word) {
        Trie* node = this;
        for (auto &c : word) {
            if (node->child[c - 'a'] == NULL) {
                return 0;
            }
            node = node->child[c - 'a'];
        }
        return node->endCount;
    }

    int countWordsStartingWith(string prefix) {
        Trie* node = this;
        for (auto &c : prefix) {
            if (node->child[c - 'a'] == NULL) {
                return 0;
            }
            node = node->child[c - 'a'];
        }
        return dfs(node);
    }

    void erase(string word) {
        Trie* node = this;
        erase(node, word, 0);
    }

    void erase(Trie* node, string& word, int index) {
        if (!node) return;
        if (index == (int) word.size()) {
            node->endCount--;
            return;
        }
        if (node->child[word[index] - 'a']) {
            erase(node->child[word[index] - 'a'], word, index + 1);
        }
    }
};