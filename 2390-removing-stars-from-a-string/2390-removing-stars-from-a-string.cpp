class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        stack<char> st;
        for (auto c: s) {
            if (c == '*') {
                st.pop();
            }else {
                st.push(c);
            }
        }
        string ans = "";
        while (st.empty() == false) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};