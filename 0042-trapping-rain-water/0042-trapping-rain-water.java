class Solution {
    public int trap(int[] height) {
        int n = height.length, ans = 0;
        Stack<Integer> stack = new Stack<>();
        for (int i=0; i<n; ++i) {
            while (!stack.empty() && height[i] > height[stack.peek()]) {
                int index = stack.pop();
                if (stack.empty()) break;
                int width = (i - 1 - (stack.peek() + 1) + 1);
                int waterHeight = Math.min(height[i], height[stack.peek()]) - height[index];
                ans += (width * waterHeight);
            }
            stack.push(i);
        }
        return ans;
    }
}