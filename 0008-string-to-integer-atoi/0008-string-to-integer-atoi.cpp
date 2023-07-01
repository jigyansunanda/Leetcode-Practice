class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int index = 0, sign = 1, ans = 0;
        while (index < n and s[index] == ' ') ++index;
        if (index < n and s[index] == '-') {
            sign = -1;
            ++index;
        } else if (index < n and s[index] == '+') ++index;
        while (index < n and isdigit(s[index])) {
            int d = s[index] - '0';
            if ((ans > INT_MAX / 10) or (ans == INT_MAX / 10 and d > INT_MAX % 10)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            ans = (ans * 10) + d;
            ++index;
        }
        return sign * ans;
    }
};