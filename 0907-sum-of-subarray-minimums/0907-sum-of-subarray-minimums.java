class Solution {
    public static long MOD = 1000000007;

    public int sumSubarrayMins(int[] arr) {
        int n = arr.length;
        long ans = 0;
        Stack<Integer> st = new Stack<>();
        for (int i=0; i<n; ++i) {
            while (!st.empty() && arr[i] <= arr[st.peek()]) {
                int index = st.pop();
                int leftIndex = (st.empty() ? -1 : st.peek());
                int rightIndex = i;
                long contribution = ((long) (rightIndex - index) * (long) (index - leftIndex))%MOD;
                contribution = (contribution * (long)arr[index])%MOD;
                ans = (ans + contribution) % MOD;
            }
            st.push(i);
        }
        while (!st.empty()) {
            int index = st.pop();
            int leftIndex = (st.empty() ? -1 : st.peek());
            int rightIndex = n;
            long contribution = ((long) (rightIndex - index) * (long) (index - leftIndex))%MOD;
            contribution = (contribution * (long)arr[index])%MOD;
            ans = (ans + contribution) % MOD;
        }
        return (int)ans;
    }
}