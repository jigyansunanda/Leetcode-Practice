class Solution {
    public boolean isCompleteTree(TreeNode root) {
        int n = countTotalNodes(root);
        return check(root, 0, n);
    }

    public boolean check(TreeNode root, int index, int n) {
        if (root == null) return true;
        if (index >= n) return false;
        return check(root.left, (index << 1) + 1, n) && check(root.right, (index << 1) + 2, n);
    }

    public int countTotalNodes(TreeNode root) {
        if (root == null) return 0;
        return 1 + countTotalNodes(root.left) + countTotalNodes(root.right);
    }
}