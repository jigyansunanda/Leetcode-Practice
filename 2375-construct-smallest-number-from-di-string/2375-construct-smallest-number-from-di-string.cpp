class Solution {
public:
    string ans, p;
    string smallestNumber(string pattern) {
        int n = pattern.size();
        p = pattern;
        ans = "99999999999";
        string subans = "";
        vector<bool> vis(10, false);
        for (int i = 1; i <= 9; ++i) {
            char c = (char) ('0' + i);
            subans.push_back(c);
            vis[i] = true;
            solve(0, n, vis, subans);
            subans.pop_back();
            vis[i] = false;
        }
        return ans;
    }

    void solve(int index, int n, vector<bool>& vis, string subans) {
        if (index == n) {
            // debug("entered");
            ans = min(ans, subans);
            return;
        }
        char c = subans.back();
        int prev = c - '0';
        for (int i = 1; i <= 9; ++i) {
            if (!vis[i]) {
                if (p[index] == 'I' and i > prev) {
                    vis[i] = true;
                    char tt = (char) ('0' + i);
                    subans.push_back(tt);
                    solve(index + 1, n, vis, subans);
                    subans.pop_back();
                    vis[i] = false;
                }
                if (p[index] == 'D' and i < prev) {
                    vis[i] = true;
                    char tt = (char) ('0' + i);
                    subans.push_back(tt);
                    solve(index + 1, n, vis, subans);
                    subans.pop_back();
                    vis[i] = false;
                }
            }
        }
    }
};