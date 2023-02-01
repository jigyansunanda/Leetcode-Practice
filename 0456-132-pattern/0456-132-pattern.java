class Solution {
    public boolean find132pattern(int[] nums) {
        int n = nums.length;
        int[] prefix_min = new int[n];
        prefix_min[0] = nums[0];
        for (int i = 1; i < n; ++i) prefix_min[i] = Math.min(prefix_min[i - 1], nums[i]);
        Stack<Integer> st = new Stack<>();
        for (int i = n - 1; i >= 0; --i) {
            while (st.isEmpty() == false && st.peek() < nums[i]) {
                if (st.peek() > prefix_min[i]) return true;
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
}