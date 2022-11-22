class Solution {
public:
    int d;
    int dp[11][2][2][11];

    int digitsCount(int d, int low, int high) {
        this->d = d;
        vector<int> digits;
        while (high) {
            digits.push_back(high % 10);
            high /= 10;
        }
        reverse(digits.begin(), digits.end());
        memset(dp, -1, sizeof dp);
        int ans = solve(0, 1, 1, 0, digits);
        digits.clear();
        low--;
        while (low) {
            digits.push_back(low % 10);
            low /= 10;
        }
        reverse(digits.begin(), digits.end());
        memset(dp, -1, sizeof dp);
        ans -= solve(0, 1, 1, 0, digits);
        return ans;
    }

    int solve(int index, int isTight, int isStart, int count, vector<int>& digits) {
        if (index == (int) digits.size()) return count;
        if (dp[index][isTight][isStart][count] != -1) return dp[index][isTight][isStart][count];
        int &ans = dp[index][isTight][isStart][count] = 0;
        int limit = isTight ? digits[index] : 9;
        for (int i = 0; i < limit + 1; ++i) {
            if (isStart and i == 0) {
                ans += solve(index + 1, 0, 1, count, digits);
            } else {
                ans += solve(index + 1, isTight && (i == limit), 0, count + (i == d), digits);
            }
        }
        return ans;
    }
};