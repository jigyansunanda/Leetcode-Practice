class Solution {
    public int longestConsecutive(int[] nums) {
        HashSet<Integer> hash = new HashSet<>();
        for (int e : nums) hash.add(e);
        int ans = 0;
        for (int e : hash) {
            if (hash.contains(e - 1)) continue;
            int curr = 1;
            while (hash.contains(e + curr)) {
                ++curr;
            }
            ans = Math.max(ans, curr);
        }
        return ans;
    }
}