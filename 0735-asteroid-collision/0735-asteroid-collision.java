class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> stack = new Stack<>();
        for (int asteroid : asteroids) {
            if (asteroid > 0) {
                stack.push(asteroid);
            } else {
                if (stack.isEmpty() || stack.peek() < 0) {
                    stack.push(asteroid);
                } else {
                    boolean isExploded = false;
                    while (!stack.isEmpty() && stack.peek() > 0) {
                        int collideWith = stack.pop();
                        if (Math.abs(collideWith) == Math.abs(asteroid)) {
                            isExploded = true;
                            break;
                        } else if (Math.abs(asteroid) < Math.abs(collideWith)) {
                            isExploded = true;
                            stack.push(collideWith);
                            break;
                        } else {
                            continue;
                        }
                    }
                    if (!isExploded) stack.push(asteroid);
                }
            }
        }
        int[] ans = new int[stack.size()];
        int index = ans.length - 1;
        while (index >= 0) {
            ans[index] = stack.pop();
            --index;
        }
        return ans;
    }
}