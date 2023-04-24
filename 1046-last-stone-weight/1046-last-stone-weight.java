class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for (int stone: stones) pq.add(stone);
        while (pq.size() > 1) {
            int x = pq.peek();
            pq.poll();
            int y = pq.peek();
            pq.poll();
            if (x!=y) pq.add(Math.abs(x-y));
        }
        if (pq.isEmpty()) return 0;
        return pq.peek();
    }
}