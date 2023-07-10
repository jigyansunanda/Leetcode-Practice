class Solution {
    static final int MAXRATING = (int) (1e5);

    private void add(int[] BIT, int index, int value) {
        while (index < BIT.length) {
            BIT[index] += value;
            index = index | (index + 1);
        }
    }

    private int get(int[] BIT, int index) {
        int sum = 0;
        while (index >= 0) {
            sum += BIT[index];
            index = (index & (index + 1)) - 1;
        }
        return sum;
    }

    private int get(int[] BIT, int l, int r) {
        int sum = get(BIT, r);
        if (l - 1 >= 0)
            sum -= get(BIT, l - 1);
        return sum;
    }

    public int numTeams(int[] rating) {
        int n = rating.length;
        int[] prefixBIT = new int[MAXRATING + 1];
        int[] suffixBIT = new int[MAXRATING + 1];
        int ans = 0;
        for (int i = n - 1; i >= 1; --i) {
            add(suffixBIT, rating[i], 1);
        }
        for (int i = 1; i <= n - 2; ++i) {
            add(prefixBIT, rating[i - 1], 1);
            add(suffixBIT, rating[i], -1);
            int lesserOnLeft = get(prefixBIT, 0, rating[i] - 1);
            int greaterOnRight = get(suffixBIT, rating[i] + 1, MAXRATING);
            ans += (lesserOnLeft * greaterOnRight);
            int greaterOnLeft = get(prefixBIT, rating[i] + 1, MAXRATING);
            int lesserOnRight = get(suffixBIT, 0, rating[i] - 1);
            ans += (lesserOnRight * greaterOnLeft);
        }
        return ans;
    }
}