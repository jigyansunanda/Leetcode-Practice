class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int next = index + 1, idx = index + 1;
        int minSoFar = nums[next];
        while (next < nums.size() and nums[next]>nums[index]) {
            if (minSoFar > nums[next]) {
                idx = next;
                minSoFar = nums[next];
            }
            ++next;
        }
        swap(nums[idx], nums[index]);
        sort(nums.begin() + index + 1, nums.end());
    }
};