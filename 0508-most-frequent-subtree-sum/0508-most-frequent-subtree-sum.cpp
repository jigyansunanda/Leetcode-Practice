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
class Solution {
public:
#define tn TreeNode

    int mx;

    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int, int> mp;
        mx = INT_MIN;
        dfs(root, mp);
        vector<int> ans;
        for (auto &e : mp) {
            if (e.second == mx) {
                ans.push_back(e.first);
            }
        }
        return ans;
    }

    int dfs(tn* root, map<int, int> &mp) {
        if (root == NULL) return 0;
        int k1 = dfs(root->left, mp);
        int k2 = dfs(root->right, mp);
        int sum = k1 + k2 + root->val;
        mp[sum]++;
        mx = max(mx, mp[sum]);
        return sum;
    }
};