class Trie {
public:
    Trie* child[26];
    Trie() {
        for (int i = 0; i < 26; ++i) {
            this->child[i] = NULL;
        }
    }
};

class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int n = s.size(), ans = 0;
        Trie* root = new Trie();
        for (int i = 0; i < n; ++i) {
            Trie* curr = root;
            for (int j = i; j < n; ++j) {
                if (curr->child[s[j] - 'a'] == NULL) {
                    curr->child[s[j] - 'a'] = new Trie();
                    curr = curr->child[s[j] - 'a'];
                } else {
                    ans = max(ans, j - i + 1);
                    curr = curr->child[s[j] - 'a'];
                }
            }
        }
        return ans;
    }
};