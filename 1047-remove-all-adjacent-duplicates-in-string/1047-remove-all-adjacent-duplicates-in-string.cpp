class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        for (auto &c: s) {
            if (ans.empty() or ans.back() != c) ans.push_back(c);
            else ans.pop_back();
        }
        return ans;
    }
};