class Solution {
public:
    int largestVariance(string s, int ans = 0) {
        int c[26] = {0};
        for (auto &ch : s) c[ch - 'a']++;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if ((i == j) or (c[i] == 0) or (c[j] == 0)) continue;
                int minCharCount = 0, maxCharCount = 0, minCharLeft = c[i];
                for (auto &ch : s) {
                    if ((ch - 'a') == j) maxCharCount++;
                    if ((ch - 'a') == i) {
                        minCharCount++;
                        minCharLeft--;
                    }
                    if (minCharCount > 0) ans = max(ans, maxCharCount - minCharCount);
                    if (maxCharCount<minCharCount and minCharLeft>0) {
                        maxCharCount = 0;
                        minCharCount = 0;
                    }
                }
            }
        }
        return ans;
    }
};