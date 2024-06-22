class Solution {
    private int ans;

    public int pathSum(TreeNode root, int targetSum) {
        this.ans = 0;
        dfs(root, targetSum);
        return ans;
    }

    private void dfs(TreeNode root, int targetSum) {
        if (root != null) {
            checkFromNode(root, (long) targetSum);
            dfs(root.left, targetSum);
            dfs(root.right, targetSum);
        }
    }

    private void checkFromNode(TreeNode root, long targetSum) {
        if (root == null) return;
        targetSum -= (long) root.val;
        if (targetSum == 0L) ++ans;
        if (root.left != null) checkFromNode(root.left, targetSum);
        if (root.right != null) checkFromNode(root.right, targetSum);
    }
}