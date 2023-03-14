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
    int sum;
    
    int sumNumbers(TreeNode* root) {
        sum = 0;
        auto dfs = [&](auto self, TreeNode* r, int x) {
            if (!r) return;
            x = (x * 10) + r->val;
            if (r->left == NULL and r->right == NULL) {
                sum += x;
                return;
            }
            self(self, r->left, x);
            self(self, r->right, x);
        }; 
        dfs(dfs, root, 0);
        return sum;
    }
};