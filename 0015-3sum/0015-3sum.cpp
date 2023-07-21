class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i + 2 < n; ++i) {
            if (i and nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = n - 1;
            while (l < r) {
                if (nums[l] + nums[r] + nums[i] > 0) --r;
                else if (nums[l] + nums[r] + nums[i] < 0) ++l;
                else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    int L = l, R = r;
                    while (L < n and nums[l] == nums[L]) ++L;
                    while (R > L and nums[R] == nums[r]) --R;
                    l = L;
                    r = R;
                }
            }
        }
        return ans;
    }
};