class Solution {
    static class OriginDistanceComparator implements Comparator<int[]> {
        public int compare(int[] a, int[] b) {
            return getDistanceFromOrigin(b) - getDistanceFromOrigin(a);
        }
    }

    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<int[]> heap = new PriorityQueue<int[]>(new OriginDistanceComparator());
        for (int i = 0; i < points.length; ++i) {
            heap.add(points[i]);
            if (heap.size() > k) heap.poll();
        }
        int[][] ans = new int[k][2];
        for (int i = k - 1; i >= 0; --i) {
            ans[i][0] = heap.peek()[0];
            ans[i][1] = heap.peek()[1];
            heap.poll();
        }
        return ans;
    }

    private static int getDistanceFromOrigin(int[] point) {
        return (point[0] * point[0]) + (point[1] * point[1]);
    }
}