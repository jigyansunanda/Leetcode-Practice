class Solution {
public:
    double myPow(double x, int n) {
        double power = getPower(x, abs((long long) n));
        if (n < 0) return (1.00000 / power);
        else return power;
    }

    double getPower(double x, long long n) {
        double power = 1.00000;
        while (n > 0) {
            if (n & 1) power = power * x;
            x = x * x;
            n = n >> 1;
        }
        return power;
    }
};