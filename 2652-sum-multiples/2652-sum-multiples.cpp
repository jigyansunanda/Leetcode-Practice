class Solution {
public:
    int sumOfMultiples(int n, int sum = 0) {
        for (int i=0; i<=n; ++i) {
            if (i%3 == 0 or i%5 == 0 or i%7 == 0) {
                sum += i;
            }
        }
        return sum;
    }
};