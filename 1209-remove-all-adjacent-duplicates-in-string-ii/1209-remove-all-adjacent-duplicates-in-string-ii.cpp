using pci = pair<char, int>;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack<pci> st;
        for (int i = 0; i < n; ++i) {
            if (st.empty() or st.top().first != s[i]) {
                st.push({s[i], 1});
            } else {
                st.top().second += 1;
                if (st.top().second == k) st.pop();
            }
        }
        string ans = "";
        while (!st.empty()) {
            auto k = st.top();
            string tmp(k.second, k.first);
            ans += tmp;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};