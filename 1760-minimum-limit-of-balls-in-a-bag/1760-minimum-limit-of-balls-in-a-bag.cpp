class Solution {
private:
    bool check(vector<int>& nums, int x, int ops) {
        int total = 0;
        for (auto e : nums) {
            total += (e % x == 0 ? (e / x) - 1 : (e / x));
        }
        return (total <= ops);
    }

public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int lo = 0, hi = *max_element(nums.begin(), nums.end());
        while (hi > lo + 1) {
            int mid = (lo + hi) >> 1;
            if (check(nums, mid, maxOperations)) hi = mid;
            else lo = mid;
        }
        return hi;
    }
};