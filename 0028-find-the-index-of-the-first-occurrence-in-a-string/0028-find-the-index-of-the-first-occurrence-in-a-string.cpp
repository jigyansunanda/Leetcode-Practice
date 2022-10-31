class Solution {
public:
    int strStr(string text, string pat) {
        string s = pat + "$" + text;
        int n = s.size();
        vector<int> kmp(n + 1, 0);
        kmp[0] = -1;
        int i = 0, j = -1;
        while (i < n) {
            while (j != -1 and s[i] != s[j]) j = kmp[j];
            ++i; ++j;
            kmp[i] = j;
        }
        for (int i = pat.size(); i < n; ++i) {
            if (kmp[i + 1] == (int) pat.size()) {
                return i - kmp[i + 1] - pat.size();
            }
        }
        return -1;
    }
};