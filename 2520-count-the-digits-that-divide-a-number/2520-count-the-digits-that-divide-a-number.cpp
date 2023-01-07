class Solution {
public:
    int countDigits(int num) {
        int ans = 0;
        int n = num;
        while (num) {
            int rem = num % 10;
            num /= 10;
            ans += (n % rem == 0);
        }
        return ans;
    }
};