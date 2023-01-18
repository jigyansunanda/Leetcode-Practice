class Solution:
    def maxSubarraySumCircular(self, nums: list[int]) -> int:
        ans = self.maxSubarraySum(nums)
        n: int = len(nums)
        totalSum: int = 0
        for i in range(0, n):
            totalSum += nums[i]
            nums[i] = -nums[i]
        minSubarraySum: int = self.maxSubarraySum(nums)
        if minSubarraySum + totalSum != 0:
            ans = max(ans, minSubarraySum + totalSum)
        return ans

    def maxSubarraySum(self, nums: list[int]) -> int:
        n: int = len(nums)
        globalMax: int = nums[0]
        localMax: int = nums[0]
        for i in range(1, n):
            localMax = max(localMax + nums[i], nums[i])
            globalMax = max(globalMax, localMax)
        return globalMax