class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        string ans = "";
        for (auto &c : s) {
            if (ans.empty() or abs(ans.back() - c) != 32) ans.push_back(c);
            else ans.pop_back();
        }
        return ans;
    }
};