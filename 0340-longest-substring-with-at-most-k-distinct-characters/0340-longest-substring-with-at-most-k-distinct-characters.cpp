class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int l = 0, ans = 0, dis = 0;
        int c[256] = {0};
        for (int r = 0; r < s.size(); ++r) {
            int index = s[r];
            c[index]++;
            if (c[index] == 1) ++dis;
            while (dis > k) {
                int idx = s[l];
                c[idx]--;
                if (c[idx] == 0) dis--;
                ++l;
            }
            if (dis <= k) {
                ans = max(ans, r - l + 1);
            }
        }
        return ans;
    }
};