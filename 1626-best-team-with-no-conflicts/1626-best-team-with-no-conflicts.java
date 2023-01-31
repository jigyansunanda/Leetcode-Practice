class Pair implements Comparable<Pair> {
    int score, age;
    Pair(int x, int y) {
        this.score = x;
        this.age = y;
    }
    @Override
    public int compareTo(Pair p) {
        if (this.score != p.score) return p.score - this.score;
        else return p.age - this.age;
    }
}

class Solution {
    public int bestTeamScore(int[] scores, int[] ages) {
        int n = scores.length;
        ArrayList<Pair> A = new ArrayList<>();
        for (int i = 0; i < n; ++i) A.add(new Pair(scores[i], ages[i]));
        Collections.sort(A);
        int[][] dp = new int[1002][1002];
        for (int i = 0; i < 1002; ++i) Arrays.fill(dp[i], -1);
        return solve(A, n, 0, 1001, dp);
    }

    static int solve(ArrayList<Pair> A, int n, int index, int max_age, int[][] dp) {
        if (index == n) return 0;
        if (dp[index][max_age] != -1) return dp[index][max_age];
        dp[index][max_age] = 0;
        dp[index][max_age] = solve(A, n, index + 1, max_age, dp);
        int choose = 0;
        if (max_age >= A.get(index).age) {
            choose = A.get(index).score + solve(A, n, index + 1, Math.min(max_age, A.get(index).age), dp);
        }
        return dp[index][max_age] = Math.max(dp[index][max_age], choose);
    }
}