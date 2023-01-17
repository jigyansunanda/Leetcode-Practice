class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        n = len(s)
        oneCount = 0
        for i in range(0, n):
            if s[i] == "1":
                oneCount += 1
        ans = n - oneCount
        onesTillNow = zerosTillNow = 0
        for i in range(0, n):
            if s[i] == "0":
                zerosTillNow += 1
            else:
                oneCount -= 1
            changes = (i + 1 - zerosTillNow) + (n - i - 1 - oneCount)
            ans = min(ans, changes)
        return ans