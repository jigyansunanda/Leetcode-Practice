class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }

    void mergesort(vector<int>& nums, int l, int r) {
        if (l < r) {
            int mid = (l + r) >> 1;
            mergesort(nums, l, mid);
            mergesort(nums, mid + 1, r);
            merge(nums, l, mid, r);
        }
    }

    void merge(vector<int> &nums, int l, int m, int r) {
        int left[m - l + 1];
        int right[r - m];
        for (int i = l; i <= m; ++i) left[i - l] = nums[i];
        for (int i = m + 1; i <= r; ++i) right[i - m - 1] = nums[i];
        int p = 0, q = 0, id = l;
        while (p < (m - l + 1) and q < (r - m)) {
            if (left[p] <= right[q]) {
                nums[id] = left[p];
                ++id; ++p;
            } else {
                nums[id] = right[q];
                ++id; ++q;
            }
        }
        while (p < (m - l + 1)) {
            nums[id++] = left[p++];
        }
        while (q < (r - m)) {
            nums[id++] = right[q++];
        }
    }
};