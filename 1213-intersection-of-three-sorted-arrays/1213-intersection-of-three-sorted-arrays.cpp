class Solution {
public:
    vector<int> arraysIntersection(vector<int>& a, vector<int>& b, vector<int>& c) {
        int p = 0, q = 0, r = 0;
        vector<int> ans;
        while (p < a.size() and q < b.size() and r < c.size()) {
            if (a[p] == b[q] and b[q] == c[r]) {
                ans.push_back(a[p]);
                ++p; ++q; ++r;
            } else {
                if (a[p] < b[q]) ++p;
                else if (b[q] < c[r]) ++q;
                else ++r;
            }
        }
        return ans;
    }
};