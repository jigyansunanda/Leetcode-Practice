class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<vector<int>> v;
        for (auto e : arr) {
            v.push_back({e, __builtin_popcount(e)});
        }
        sort(v.begin(), v.end(), [&](const auto& A, const auto& B) {
            if (A[1] != B[1]) return A[1] < B[1];
            return A[0] < B[0];
        });
        vector<int> ans;
        for (auto e : v) ans.push_back(e[0]);
        return ans;
    }
};