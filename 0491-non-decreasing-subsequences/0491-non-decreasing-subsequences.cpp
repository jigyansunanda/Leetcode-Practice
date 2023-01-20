class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<int> subans;

        auto solve = [&] (auto solve, int index) -> void {
            if (subans.size() > 1) ans.push_back(subans);
            unordered_set<int> added;
            for (int i = index; i < n; ++i) {
                if ((subans.empty() == false and nums[i] < subans.back()) or (added.find(nums[i]) != added.end())) {
                    continue;
                }
                subans.push_back(nums[i]);
                added.insert(nums[i]);
                solve(solve, i + 1);
                subans.pop_back();
            }
        };
        solve(solve, 0);

        return ans;
    }
};