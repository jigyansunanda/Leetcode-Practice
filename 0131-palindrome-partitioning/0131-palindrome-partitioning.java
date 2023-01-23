class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> ans = new ArrayList<>();
        List<String> subans = new ArrayList<>();
        int n = s.length();
        int[][] dp = new int[n][n];
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
            if (i + 1 < n && s.charAt(i) == s.charAt(i + 1)) {
                dp[i][i + 1] = 1;
            }
        }
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                dp[i][j] = ((dp[i + 1][j - 1] == 1) && (s.charAt(i) == s.charAt(j))) ? 1 : 0;
            }
        }
        solve(s, 0, ans, subans, dp);
        return ans;
    }

    public void solve(String s, int index, List<List<String>> ans, List<String> subans, int[][] dp) {
        if (index == s.length()) {
            ans.add(new ArrayList<>(subans));
            return;
        }
        for (int next = index + 1; next <= s.length(); ++next) {
            if (dp[index][next - 1] == 1) {
                subans.add(s.substring(index, next));
                solve(s, next, ans, subans, dp);
                subans.remove(subans.size() - 1);
            }
        }
    }
}