class Solution {
    public boolean canCross(int[] stones) {
        int n = stones.length;
        HashMap<Integer, HashSet<Integer>> jumpSize = new HashMap<>();
        HashSet<Integer> positions = new HashSet<>();
        for (int stone : stones) {
            jumpSize.put(stone, new HashSet<>());
            positions.add(stone);
        }
        HashMap<Integer, Boolean> canReach = new HashMap<>();
        canReach.put(0, true);
        jumpSize.get(0).add(1);
        for (int i = 0; i < n; i++) {
            int stone = stones[i];
            if (!canReach.containsKey(stone)) continue;
            for (int jumpLength : jumpSize.get(stone)) {
                if (jumpLength == 0) continue;
                int position = stone + jumpLength;
                if (positions.contains(position)) {
                    canReach.put(position, true);
                    for (int j = -1; j <= 1; ++j) {
                        jumpSize.get(position).add(jumpLength + j);
                    }
                }
            }
        }
        return canReach.containsKey(stones[n - 1]);
    }
}