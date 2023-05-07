class Solution {
private:
    int get_random_number(int l, int r) {
        int len = r - l + 1;
        return l + (rand() % len);
    }

    int partition(vector<int>& nums, int l, int r) {
        int pivot_index = get_random_number(l, r);
        swap(nums[pivot_index], nums[r]);
        int index = l;
        for (int i = l; i <= r; ++i) {
            if (nums[i] <= nums[r]) {
                swap(nums[i], nums[index]);
                ++index;
            }
        }
        return index - 1;
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        // k-th largest = in sorted array, index = n-k
        int l = 0, r = n - 1;
        while (l <= r) {
            int final_pivot_index = partition(nums, l, r);
            if (final_pivot_index == n - k) return nums[final_pivot_index];
            if (final_pivot_index < (n - k)) l = final_pivot_index + 1;
            else r = final_pivot_index - 1;
        }
        return -1;
    }
};