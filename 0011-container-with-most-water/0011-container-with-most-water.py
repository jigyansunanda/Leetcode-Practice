class Solution:
    def maxArea(self, height: List[int]) -> int:
        lo = 0
        hi = len(height)-1
        ans = 0
        while (lo < hi):
            width = hi - lo
            area = min(height[lo], height[hi]) * width
            ans = max(ans, area)
            if (height[lo] <= height[hi]):
                lo += 1
            else:
                hi -= 1
        return ans
        