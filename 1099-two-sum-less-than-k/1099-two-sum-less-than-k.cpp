class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k, int ans = -1) {
        int c[1001] = {0};
        for (auto &num : nums) c[num]++;
        int lo = 0, hi = 1000;
        while (lo <= hi) {
            if (c[lo] == 0) {++lo; continue;}
            if (c[hi] == 0) {--hi; continue;}
            if (lo + hi < k) {
                if (lo != hi) ans = max(ans, lo + hi);
                else if (lo == hi and c[lo] > 1) ans = max(ans, 2 * lo);
                ++lo;
            } else {
                --hi;
            }
        }
        return ans;
    }
};