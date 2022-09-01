using tn = TreeNode;
using pii = pair<int, int>;

class Solution {
public:
	vector<vector<int>> verticalTraversal(TreeNode* root) {
		map<int, vector<pii>> mp;
		dfs(root, 0, 0, mp);
		vector<vector<int>> ans;
		for (auto it : mp) {
			auto &vec = it.second;
			sort(vec.begin(), vec.end());
			vector<int> sub;
			for (auto &p : vec) {
				sub.push_back(p.second);
			}
			ans.push_back(sub);
		}
		return ans;
	}

	void dfs(tn* root, int row, int col, map<int, vector<pii>> &mp) {
		if (!root) return;
		mp[col].emplace_back(row, root->val);
		dfs(root->left, row + 1, col - 1, mp);
		dfs(root->right, row + 1, col + 1, mp);
	}
};