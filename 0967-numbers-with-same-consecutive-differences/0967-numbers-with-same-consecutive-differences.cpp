class Solution {
private:
    void dfs(int digit, int num, int len, int K, int N, vector<int>& numbers) {
        if (digit < 0 or digit > 9) return;
        if (len == N) {
            numbers.push_back(num);
            return;
        }
        dfs(digit + K, (num * 10) + (digit + K), len + 1, K, N, numbers);
        if (K) dfs(digit - K, (num * 10) + (digit - K), len + 1, K, N, numbers);
    }

public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> numbers;
        for (int i = 1; i < 10; ++i) dfs(i, i, 1, k, n, numbers);
        return numbers;
    }
};