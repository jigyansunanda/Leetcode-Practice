class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        HashSet<String> dictionary = new HashSet<>(wordDict);
        int n = s.length();
        boolean[] dp = new boolean[n + 1];
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (!dp[j]) continue;
                String suffix = s.substring(j, i);
                if (dictionary.contains(suffix)) dp[i] = true;
            }
        }
        return dp[n];
    }
}