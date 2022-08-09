class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        function<bool(char, char)> match = [&](char a, char b) {
            return ((a == '(' and b == ')') or (a == '[' and b == ']') or (a == '{' and b == '}'));
        };
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(' or s[i] == '[' or s[i] == '{') {
                st.push(s[i]);
            } else {
                if (st.empty()) return false;
                else if (!match(st.top(), s[i])) return false;
                else st.pop();
            }
        }
        return st.empty();
    }
};