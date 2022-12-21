class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m = mat.size(), n = mat[0].size(), r1 = 0, c1 = 0, r2 = 0, c2 = 0;
        for (int i = 1; i <= (m + n - 1); ++i) {
            int R1 = r1, C1 = c1, R2 = r2, C2 = c2;
            if ((i & 1) == 0) {
                swap(R1, R2);
                swap(C1, C2);
            }
            int r = R1, c = C1;
            while (true) {
                ans.push_back(mat[r][c]);
                if (r == R2 and c == C2) break;
                r -= ((i & 1) ? 1 : -1);
                c += ((i & 1) ? 1 : -1);
            }
            // update (r1, c1) and (r2, c2)
            if (r1 + 1 >= m) c1 += 1;
            else r1 += 1;
            if (c2 + 1 >= n) r2 += 1;
            else c2 += 1;
        }
        return ans;
    }
};
