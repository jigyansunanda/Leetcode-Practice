class Solution {
    public int reachNumber(int target) {
        if (target < 0) return reachNumber(Math.abs(target));
        int steps = 0, total = 0;
        while (total < target) {
            steps++;
            total += steps;
        }
        while (Math.abs(total - target) % 2 == 1) {
            steps++;
            total += steps;
        }
        return steps;
    }
}