class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& A, vector<vector<int>>& B) {
        int i = 0, j = 0, m = A.size(), n = B.size();
        stack<pair<int, int>> st;
        while (i < m || j < n) {
            if (i >= m or j >= n) break;
            if (A[i][1] == 0) {
                ++i;
                continue;
            }
            if (B[j][1] == 0) {
                ++j;
                continue;
            }
            int minFre = min(A[i][1], B[j][1]);
            int product = A[i][0] * B[j][0];
            if (st.empty() or st.top().first != product) {
                st.push({product, minFre});
            } else {
                st.top().second += minFre;
            }
            A[i][1] -= minFre;
            B[j][1] -= minFre;
        }
        vector<vector<int>> ans;
        while (!st.empty()) {
            ans.push_back({st.top().first, st.top().second});
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};