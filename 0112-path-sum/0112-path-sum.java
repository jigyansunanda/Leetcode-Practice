class Solution {
    public boolean hasPathSum(TreeNode root, int targetSum) {
        if (root == null)
            return false;
        else if (root.left == null && root.right == null) {
            return root.val == targetSum;
        } else {
            boolean hasPathSumTarget = false;
            hasPathSumTarget |= hasPathSum(root.left, targetSum - root.val);
            if (hasPathSumTarget) return true;
            hasPathSumTarget |= hasPathSum(root.right, targetSum - root.val);
            return hasPathSumTarget;
        }
    }
}