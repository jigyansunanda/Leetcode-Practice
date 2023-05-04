class Solution {
    public static int solve(String s1, String s2, String s3, int n1, int n2, int n3, int[][][] dp) {
        if (n1 + n2 + n3 == 0)
            return 1;
        if (n3 == 0)
            return 0;
        if (dp[n1][n2][n3] != -1)
            return dp[n1][n2][n3];
        int ans = 0;
        if (n1 > 0 && s1.charAt(n1 - 1) == s3.charAt(n3 - 1))
            ans = ans | solve(s1, s2, s3, n1 - 1, n2, n3 - 1, dp);
        if (n2 > 0 && s2.charAt(n2 - 1) == s3.charAt(n3 - 1))
            ans = ans | solve(s1, s2, s3, n1, n2 - 1, n3 - 1, dp);
        return dp[n1][n2][n3] = ans;
    }

    public static boolean isInterleave(String s1, String s2, String s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        if (n1 + n2 != n3)
            return false;
        int[] cnt = new int[26];
        for (int i = 0; i < n1; ++i)
            cnt[s1.charAt(i) - 'a']++;
        for (int i = 0; i < n2; ++i)
            cnt[s2.charAt(i) - 'a']++;
        for (int i = 0; i < n3; ++i)
            cnt[s3.charAt(i) - 'a']--;
        for (int i = 0; i < 26; ++i)
            if (cnt[i] != 0)
                return false;
        int[][][] dp = new int[n1 + 1][n2 + 1][n3 + 1];
        for (int i = 0; i <= n1; ++i) {
            for (int j = 0; j <= n2; ++j) {
                for (int k = 0; k <= n3; ++k) {
                    dp[i][j][k] = -1;
                }
            }
        }
        int ans = solve(s1, s2, s3, n1, n2, n3, dp);
        return (ans == 1) ? true : false;
    }
}