class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x % 10 == 0 and x != 0) return false;
        int numFromRight = 0;
        while (x > numFromRight) {
            numFromRight = (numFromRight * 10) + (x % 10);
            x /= 10;
        }
        return (x == numFromRight or x == (numFromRight/10));
    }
};