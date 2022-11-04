class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int a[101] = {0};
        for (auto &log : logs) {
            a[log[0] - 1950] += 1;
            a[log[1] - 1950] -= 1;
        }
        int mx = a[0];
        for (int i = 1; i <= 100; ++i) {
            a[i] += a[i - 1];
            mx = max(mx, a[i]);
        }
        for (int i = 0; i < 101; ++i) {
            if (a[i] == mx) return 1950 + i;
        }
        return 2050;
    }
};