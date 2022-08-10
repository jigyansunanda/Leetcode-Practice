class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            if (i and nums[i] == nums[i - 1]) continue;
            int lo = i + 1, hi = n - 1;
            while (lo < hi) {
                int sum = nums[lo] + nums[hi] + nums[i];
                if (sum < 0) ++lo;
                else if (sum > 0) --hi;
                else {
                    vector<int> v = {nums[i], nums[lo], nums[hi]};
                    res.push_back(v);
                    int start = lo, end = hi;
                    while (start + 1 < n and nums[start + 1] == nums[lo]) start++;
                    while (end - 1 >= 0 and nums[end - 1] == nums[hi]) end--;
                    lo = start + 1;
                    hi = end;
                }
            }
        }
        return res;
    }
};