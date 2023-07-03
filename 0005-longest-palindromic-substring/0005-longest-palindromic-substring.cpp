class Solution {
public:
    string longestPalindrome(string S) {
        int n = S.size();
        vector<int> d1(n+1, 0), d2(n+1, 0);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && S[i - k] == S[i + k]) {
                k++;
            }
            d1[i] = k--;
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }

        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
            while (0 <= i - k - 1 && i + k < n && S[i - k - 1] == S[i + k]) {
                k++;
            }
            d2[i] = k--;
            if (i + k > r) {
                l = i - k - 1;
                r = i + k;
            }
        }

        int ans = 0, ind = -1;
        for (int i = 0; i < n; i++) {
            if (d1[i] * 2 - 1 > ans) ans = d1[i] * 2 - 1, ind = i;
            if (d2[i] * 2 > ans) ans = d2[i] * 2, ind = i;
        }
        return S.substr(ind - ans / 2, ans);
    }
};