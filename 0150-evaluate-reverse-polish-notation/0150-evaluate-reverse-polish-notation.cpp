class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<long long> st;
        for (auto &token : tokens) {
            if (token == "+") {
                auto num1 = st.back(); st.pop_back();
                auto num2 = st.back(); st.pop_back();
                st.push_back(num1 + num2);
            } else if (token == "-") {
                auto num1 = st.back(); st.pop_back();
                auto num2 = st.back(); st.pop_back();
                st.push_back(num2 - num1);
            } else if (token == "*") {
                auto num1 = st.back(); st.pop_back();
                auto num2 = st.back(); st.pop_back();
                st.push_back(num1 * num2);
            } else if (token == "/") {
                auto num1 = st.back(); st.pop_back();
                auto num2 = st.back(); st.pop_back();
                st.push_back(num2 / num1);
            } else {
                st.push_back(stoll(token));
            }
        }
        return st.back();
    }
};