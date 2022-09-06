using tn = TreeNode;

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) return root;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (!root->left and !root->right and (root->val != 1)) return NULL;
        else return root;
    }
};