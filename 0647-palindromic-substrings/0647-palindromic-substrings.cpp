class Solution {
public:
    int countSubstrings(string s) {
        string str = "#";
        for (auto ch : s) {
            str += ch;
            str += "#";
        }
        int n = str.length();
        vector<int> manachers(n);
        int c = 0, r = 0;
        for (int i = 0; i < n; i++) {
            if (i < r) {
                manachers[i] = min(manachers[2 * c - i], r - i);
            }
            while (i + manachers[i] + 1 < n && i - manachers[i] - 1 >= 0 && str[i + manachers[i] + 1] == str[i - manachers[i] - 1]) {
                manachers[i]++;
            }
            if (i + manachers[i] > r) {
                c = i;
                r = i + manachers[i];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                ans += ((manachers[i]) / 2 + 1);
            } else {
                ans += (manachers[i] + 1) / 2;
            }
        }
        return ans;
    }
};