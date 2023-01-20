class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> subans;

        auto solve = [&] (auto solve, int index) -> void {
            ans.push_back(subans);
            unordered_set<int> added;
            for (int i = index; i < n; ++i) {
                if ((added.find(nums[i]) != added.end())) continue;
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