class Solution {
public:
	int trap(vector<int>& height) {
		stack<int> st;
		int ans = 0;
		for (int i = 0; i < height.size(); ++i) {
			while (st.empty() == false and height[st.top()] < height[i]) {
				int index = st.top();
                st.pop();
				if (st.empty()) break;
				int w = i - st.top() - 1;
				int h = min(height[st.top()], height[i]) - height[index];
				ans += (h * w);
			}
			st.push(i);
		}
		return ans;
	}
};