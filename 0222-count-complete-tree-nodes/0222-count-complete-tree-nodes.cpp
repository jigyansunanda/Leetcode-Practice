class Solution {
private:
    int get_leftmost_height(TreeNode* root) {
        int h = 0;
        while (root) {
            ++h;
            root = root->left;
        }
        return h;
    }

    int get_rightmost_height(TreeNode* root) {
        int h = 0;
        while (root) {
            ++h;
            root = root->right;
        }
        return h;
    }

public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int left_height = get_leftmost_height(root);
        int right_height = get_rightmost_height(root);
        if (left_height == right_height) return (1 << left_height) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};