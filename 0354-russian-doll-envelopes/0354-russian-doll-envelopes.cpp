class Solution {
private:
    int search(vector<int>& dp, int x) {
        int lo = -1, hi = dp.size();
        while (hi > lo + 1) {
            int mid = (lo + hi) >> 1;
            if (dp[mid] < x) lo = mid;
            else hi = mid;
        }
        return hi;
    }

public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [&](const auto& A, const auto& B) { return (A[0] == B[0]) ? A[1] > B[1] : A[0] < B[0]; });
        int n = envelopes.size();
        vector<int> dp;
        for (int i = 0; i < n; ++i) {
            if (dp.empty()) dp.push_back(envelopes[i][1]);
            else {
                int index = search(dp, envelopes[i][1]);
                if (index == ((int) dp.size())) {
                    dp.push_back(envelopes[i][1]);
                } else {
                    dp[index] = min(dp[index], envelopes[i][1]);
                }
            }
        }
        return dp.size();
    }
};