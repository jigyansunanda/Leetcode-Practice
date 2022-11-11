class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0, curr = 1;
        while (curr < (int)nums.size()) {
            if (nums[curr] == nums[index]) {
                ++curr; 
            }else {
                nums[++index] = nums[curr];
                +curr;
            }
        }
        return index + 1;
    }
};