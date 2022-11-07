class Solution:
    def maximum69Number (self, num: int) -> int:
        arr = []
        while (num > 0):
            arr.append(num % 10)
            num = num // 10
        arr.reverse()
        for x in range(len(arr)):
            if (arr[x] == 6):
                arr[x] = 9
                break
        ans = 0
        for x in range(len(arr)):
            ans = (ans * 10) + arr[x]
        return ans