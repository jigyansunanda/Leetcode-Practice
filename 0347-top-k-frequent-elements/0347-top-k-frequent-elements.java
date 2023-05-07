class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
        }
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> mp.get(a) - mp.get(b));
        for (int a : mp.keySet()) {
            pq.add(a);
            if (pq.size() > k)
                pq.poll();
        }
        int[] ans = new int[k];
        for (int i = 0; i < k; ++i) {
            ans[i] = pq.poll();
        }
        return ans;
    }
}