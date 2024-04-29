class Solution:
    def addedInteger(self, A: List[int], B: List[int]) -> int:
        return min(B) - min(A)
        