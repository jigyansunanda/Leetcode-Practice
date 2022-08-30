class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		stack<int> st;
		int maxArea = 0;
		for (int i = 0; i < heights.size(); ++i) {
			while (st.empty() == false and heights[i] <= heights[st.top()]) {
				int index = st.top(); st.pop();
				int currentHeight = heights[index];
				int rightBoundary = i - 1;
				int leftBoundary = (st.empty()) ? 0 : st.top() + 1;
				int currentWidth = rightBoundary - leftBoundary + 1;
				int currentArea = currentWidth * currentHeight;
				maxArea = max(maxArea, currentArea);
			}
			st.push(i);
		}
		while (st.empty() == false) {
			int index = st.top(); st.pop();
			int currentHeight = heights[index];
			int rightBoundary = heights.size() - 1;
			int leftBoundary = (st.empty()) ? 0 : st.top() + 1;
			int currentWidth = rightBoundary - leftBoundary + 1;
			int currentArea = currentWidth * currentHeight;
			maxArea = max(maxArea, currentArea);
		}
		return maxArea;
	}
};