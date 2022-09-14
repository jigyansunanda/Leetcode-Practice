class Solution {
public:
	int countHighestScoreNodes(vector<int>& parents) {
		vector<long long>score(parents.size(), 0);
		vector<int> tree[parents.size()];
		for (int i = 1; i <= parents.size() - 1; ++i) {
			tree[parents[i]].push_back(i);
		}
		function<long long(int)> dfs = [&](int u) {
			long long sum = 0, prod = 1;
			for (auto &v : tree[u]) {
				long long k = dfs(v);
				sum += k;
				prod *= k;
			}
			if (u == 0) score[u] = prod;
			else score[u] = prod * (parents.size() - sum - 1);
			return sum+1;
		};
		dfs(0);
		long long maxscore = *max_element(score.begin(), score.end());
		return count(score.begin(), score.end(), maxscore);
	}
};