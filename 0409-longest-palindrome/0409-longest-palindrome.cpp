class Solution {
public:
    int longestPalindrome(string s) {
        int c[128] = {0};
        for (auto &ch : s) c[ch]++;
        int ans = 0;
        for (auto &e : c) {
            ans += (e / 2) * 2;
            if (ans % 2 == 0 and e % 2 == 1) {
                ans++;
            }
        }
        return ans;
    }
};