class Solution {
public:
    int dp[11][2][2];

    int solve(vector<int>& num, int index, int isTight, int isStart, string& s) {
        if (index == (int) s.size()) return 1;
        if (dp[index][isTight][isStart] != -1) return dp[index][isTight][isStart];
        int &ans = dp[index][isTight][isStart] = 0;
        if (isStart == 0) ans += solve(num, index + 1, 0, 0, s);
        int limit = isTight ? (s[index] - '0') : 9;
        for (int i = 0; i < (int)num.size(); ++i) {
            if (num[i] > limit) break;
            ans += solve(num, index + 1, isTight && (num[i] == limit), 1, s);
        }
        return ans;
    }

    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        vector<int> num(digits.size(), 0);
        for (int i = 0; i < (int)digits.size(); ++i) {
            num[i] = digits[i][0] - '0';
        }
        memset(dp, -1, sizeof dp);
        int ans = solve(num, 0, 1, 0, s);
        return ans - 1;
    }
};