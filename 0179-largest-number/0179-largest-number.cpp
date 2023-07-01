class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for (auto e : nums) v.push_back(to_string(e));
        sort(v.begin(), v.end(), [&](const auto& A, const auto& B) { return A + B > B + A; });
        string ans = "";
        for (auto e : v) ans += e;
        if (ans.front() == '0') return "0";
        return ans;
    }
};