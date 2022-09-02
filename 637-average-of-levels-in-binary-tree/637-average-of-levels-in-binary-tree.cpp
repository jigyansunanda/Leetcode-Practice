/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
using tn = TreeNode;

class Solution {
public:
	vector<double> averageOfLevels(TreeNode* root) {
		if (!root) return {};
		map<int, vector<double>> mp;
		queue<tn*> q;
		q.push(root);
		int level = 0;
		while (!q.empty()) {
			for (int i = q.size(); i > 0; --i) {
				auto u = q.front();
				int val = u->val;
				q.pop();
				mp[level].push_back((double)val);
				if (u->left) q.push(u->left);
				if (u->right) q.push(u->right);
			}
			++level;
		}
		vector<double> v;
		for (auto &it : mp) {
			double sum = accumulate(it.second.begin(), it.second.end(), 0.0);
			v.push_back(sum/(double)(it.second.size()));
		}
		return v;
	}
};