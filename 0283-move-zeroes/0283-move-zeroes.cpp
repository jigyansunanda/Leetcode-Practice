class Solution {
public:
    void moveZeroes(vector<int>& nums, int index = 0) {
        for (int i = 0; i < (int) nums.size(); ++i) 
            if (nums[i]) swap(nums[i], nums[index++]);
    }
};