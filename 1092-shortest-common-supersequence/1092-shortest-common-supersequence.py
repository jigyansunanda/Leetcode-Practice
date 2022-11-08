class Solution:
    def shortestCommonSupersequence(self, s: str, t: str) -> str:
        m = len(s)
        n = len(t)
        dp = [[0 for j in range(n+1)] for i in range(m+1)]
        for i in range(m+1):
            for j in range(n+1):
                if (i == 0 or j == 0):
                    dp[i][j] = i + j
                else:
                    if (s[i-1] == t[j-1]):
                        dp[i][j] = dp[i-1][j-1] + 1
                    else:
                        dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1
        a = m
        b = n
        ans = ""
        while (a != 0 or b != 0):
            if (a==0):
                ans += t[b-1]
                b -= 1
            elif (b==0):
                ans += (s[a-1])
                a -= 1
            elif (s[a-1] == t[b-1]):
                ans += (s[a-1])
                a -= 1
                b -= 1
            elif (dp[a-1][b] < dp[a][b-1]):
                ans += (s[a-1])
                a -= 1
            else:
                ans += (t[b-1])
                b -= 1
        return ans[::-1]