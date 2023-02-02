class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> mp;
        for (int i = 0; i < (int) order.size(); ++i) {
            mp[order[i]] = i;
        }
        for (int i = 1; i <= (int) words.size() - 1; ++i) {
            int a = 0, b = 0;
            string s = words[i], t = words[i - 1];
            while (a < (int) s.size() and b < (int) t.size()) {
                int p = mp[t[b]], q = mp[s[a]];
                // debug(p, q);
                if (p > q) return false;
                else if (p < q) break;
                else {
                    ++a;
                    ++b;
                }
            }
            if (b != (int) t.size() and a == (int) s.size()) return false;
        }
        return true;
    }
};