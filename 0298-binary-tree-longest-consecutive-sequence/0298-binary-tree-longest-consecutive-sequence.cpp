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
    int ans;

    int longestConsecutive(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }

    int dfs(TreeNode* root) {
        if (!root) return 0;
        int curr = 1;
        if (root->left) {
            int left = dfs(root->left);
            if (root->left->val - 1 == root->val) curr = max(curr, left + 1);
            ans = max(ans, curr);
        }
        if (root->right) {
            int right = dfs(root->right);
            if (root->right->val - 1 == root->val) curr = max(curr, right + 1);
            ans = max(ans, curr);
        }
        ans = max(ans, curr);
        return curr;
    }
};