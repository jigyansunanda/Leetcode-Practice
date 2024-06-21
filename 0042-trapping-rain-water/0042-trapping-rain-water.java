class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int waterTrapped = 0;
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && height[i] > height[stack.peek()]) {
                int index = stack.pop();
                if (stack.isEmpty()) break;
                int leftIndex = stack.peek();
                int rightIndex = i;
                int width = i - leftIndex - 1;
                int h = Math.min(height[leftIndex], height[rightIndex]) - height[index];
                waterTrapped += (h * width);
            }
            stack.push(i);
        }
        return waterTrapped;
    }
}