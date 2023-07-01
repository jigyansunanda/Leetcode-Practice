class Solution {
private:
    bool KMPcheck(string& txt, string& pat) {
        auto lps = getLPSarray(pat);
        int m = txt.size(), n = pat.size(), i = 0, j = 0;
        while (i < m) {
            if (txt[i] == pat[j]) {
                ++i;
                ++j;
            }
            if (j == n) {
                j = lps[j - 1];
                return true;
            }
            if (i < m and pat[j] != txt[i]) {
                if (j == 0) ++i;
                else j = lps[j - 1];
            }
        }
        return false;
    }

    vector<int> getLPSarray(string& s) {
        int n = s.size();
        vector<int> lps(n, 0);
        int len = 0, index = 1;
        while (index < n) {
            if (s[len] == s[index]) lps[index++] = ++len;
            else {
                if (len == 0) lps[index++] = len;
                else len = lps[len - 1];
            }
        }
        return lps;
    }

public:
    bool rotateString(string s, string goal) {
        if (s.size() > goal.size()) return false;
        string txt = goal + goal;
        return KMPcheck(txt, s);
    }
};