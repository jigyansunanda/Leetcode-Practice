class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& tmp) {
		vector<int> ans(tmp.size(), 0);
		stack<int> st;
		for (int i = 0; i < tmp.size(); ++i) {
			while (!st.empty() and tmp[i] > tmp[st.top()]) {
				int index = st.top(); st.pop();
				ans[index] = i - index;
			}
			st.push(i);
		}
		return ans;
	}
};