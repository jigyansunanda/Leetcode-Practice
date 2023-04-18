class Solution {
private:
    int get_random_number(int l, int r) {
        int _range = (r - l + 1);
        return l + (rand() % _range);
    }
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return kth_smallest_element(nums, 0, n - 1, n - k + 1);
    }
    
    int kth_smallest_element(vector<int>& nums, int l, int r, int k) {
        while (l <= r) {
            int p = partition(nums, l, r);
            if (p == k - 1) return nums[p];
            if (p < (k-1)) l = p + 1;
            else r = p - 1;
        }
        return -1;
    }
    
    int partition(vector<int>& nums, int l, int r) {
        int pivot_index = get_random_number(l, r);
        int pivot = nums[pivot_index];
        swap(nums[r], nums[pivot_index]);
        int index = l;
        for (int i = l; i <= r; ++i) {
            if (nums[i] <= pivot) {
                swap(nums[i], nums[index]);
                ++index;
            }
        }
        return index - 1;
    }
};