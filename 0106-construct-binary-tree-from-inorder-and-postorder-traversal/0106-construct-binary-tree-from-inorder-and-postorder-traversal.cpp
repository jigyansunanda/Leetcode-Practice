class Solution {
public:
    // inorder = left -> root -> right
    // postorder = left -> right -> root
    int n, rootindex;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        n = inorder.size();
        rootindex = n - 1;
        return makeTree(inorder, postorder, 0, n - 1);
    }

    TreeNode* makeTree(vector<int>& inorder, vector<int>& postorder, int l, int r) {
        if (l > r) return NULL;
        if (l == r) {
            TreeNode* root = new TreeNode(postorder[rootindex]);
            --rootindex;
            return root;
        }
        TreeNode* root = new TreeNode(postorder[rootindex--]);
        int index = -1;
        for (int i = l; i <= r; ++i) {
            if (inorder[i] == root->val) {
                index = i;
                break;
            }
        }
        root->right = makeTree(inorder, postorder, index + 1, r);
        root->left = makeTree(inorder, postorder, l, index - 1);
        return root;
    }
};