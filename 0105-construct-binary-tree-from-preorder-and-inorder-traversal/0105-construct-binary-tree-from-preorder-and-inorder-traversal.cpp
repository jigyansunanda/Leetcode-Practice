class Solution {
public:
    using tn = TreeNode;
    int n, rootindex;

    // preorder = root -> left -> right
    // inorder = left -> root -> right

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        n = preorder.size();
        rootindex = 0;
        return getTree(preorder, inorder, 0, n - 1);
    }

    tn* getTree(vector<int>& preorder, vector<int>& inorder, int l, int r) {
        if (l == r) {
            tn* root = new tn(preorder[rootindex]);
            rootindex++;
            return root;
        }
        if (l > r) return NULL;
        tn* root = new tn(preorder[rootindex]);
        int index = l;
        for (int i = l; i <= r; ++i) {
            if (inorder[i] == preorder[rootindex]) {
                index = i;
                break;
            }
        }
        ++rootindex;
        root->left = getTree(preorder, inorder, l, index - 1);
        root->right = getTree(preorder, inorder, index + 1, r);
        return root;
    }
};