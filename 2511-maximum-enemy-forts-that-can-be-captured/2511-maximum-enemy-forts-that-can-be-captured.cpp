class Solution {
public:
    int captureForts(vector<int>& forts) {
        int n = forts.size(), ans = 0, c = 0;
        bool a = false, b = false;
        for (int i = 0; i < n; ++i) {
            if (forts[i] == 1) {
                if (b == true)ans = max(ans, c);
                a = true; b = false;
                c = 0;
            } else if (forts[i] == -1) {
                if (a == true) ans = max(ans, c);
                b = true, a = false;
                c = 0;
            } else {
                c++;
            }
        }
        return ans;
    }
};