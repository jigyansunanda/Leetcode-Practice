class Solution {
    private int lengthOfLIS(int[] arr, int n) {
        int ans = 0;
        int[] dp = new int[n];
        for (int x : arr) {
            int index = Arrays.binarySearch(dp, 0, ans, x);
            if (index < 0)
                index = -(index + 1);
            dp[index] = x;
            if (index == ans)
                ++ans;
        }
        return ans;
    }

    public int maxEnvelopes(int[][] envelopes) {
        Arrays.sort(envelopes, new Comparator<int[]>() {
            public int compare(int[] A, int[] B) {
                if (A[0] != B[0])
                    return A[0] - B[0];
                return B[1] - A[1];
            }
        });
        int n = envelopes.length;
        int[] arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = envelopes[i][1];
        }
        return lengthOfLIS(arr, n);
    }
}