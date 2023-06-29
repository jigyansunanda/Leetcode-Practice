class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre = nums;
        for (int i = 1; i <= n - 1; ++i) {
            pre[i] += pre[i - 1];
        }
        vector<int> suf = nums;
        for (int i = n - 2; i >= 0; --i) {
            suf[i] += suf[i + 1];
        }
        for (int i = 0; i < n; ++i) {
            int presum = (i - 1 >= 0) ? pre[i - 1] : 0;
            int sufsum = (i + 1 < n) ? suf[i + 1] : 0;
            if (presum == sufsum) return i;
        }
        return -1;
    }
};