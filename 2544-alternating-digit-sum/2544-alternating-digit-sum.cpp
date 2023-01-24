class Solution {
public:
    int alternateDigitSum(int n) {
        int count = 0, sum = 0;
        while (n) {
            ++count;
            sum += ((count & 1) ? 1 : -1) * (n%10);
            n /= 10;
        }
        return ((count & 1) ? sum : -sum);
    }
};