class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1) {
            sort(s.begin(), s.end()); return s;
        } else {
            string ans = s;
            for (int i = 1; i < (int)s.size(); ++i) {
                string subans = s.substr(i) + s.substr(0, i);
                ans = min(ans, subans);
            }
            return ans;
        }
    }
};