class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> permute(vector<int>& nums) {
        permute(nums, 0, (int)nums.size() - 1);
        return ans;
    }

    void permute(vector<int> &nums, int l, int r) {
        if (l == r) {
            ans.push_back(nums);
            return;
        }
        for (int i = l; i <= r; ++i) {
            swap(nums[i], nums[l]);
            permute(nums, l + 1, r);
            swap(nums[i], nums[l]);
        }
    }
};