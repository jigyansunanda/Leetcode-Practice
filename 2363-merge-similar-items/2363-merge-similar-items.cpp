class Solution {
public:
	vector<vector<int>> mergeSimilarItems(vector<vector<int>>& a, vector<vector<int>>& b) {
		set<int> w;
		int wt[1005] = {0};
		for (auto &e : a) {wt[e[0]] += e[1]; w.insert(e[0]);}
		for (auto &e : b) {wt[e[0]] += e[1]; w.insert(e[0]);}
		vector<vector<int>> ans;
		for (auto e : w) {
			ans.push_back({e, wt[e]});
		}
		return ans;
	}
};