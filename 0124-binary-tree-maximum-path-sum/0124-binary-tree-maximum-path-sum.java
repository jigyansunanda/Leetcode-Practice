class Solution {
    public int maxPathSum(TreeNode root) {
        int[] pathSum = new int[] {Integer.MIN_VALUE};
        maxPathSum(root, pathSum);
        return pathSum[0];
    }

    private int maxPathSum(TreeNode root, int[] pathSum) {
        if (root == null) {
            return Integer.MIN_VALUE;
        }
        int left = maxPathSum(root.left, pathSum);
        int right = maxPathSum(root.right, pathSum);
        int leftPathSum = (left == Integer.MIN_VALUE ? 0 : left);
        int rightPathSum = (right == Integer.MIN_VALUE ? 0 : right);
        int leftChildIncluded = leftPathSum + root.val;
        int rightChildIncluded = rightPathSum + root.val;
        int completePath = leftPathSum + rightPathSum + root.val;
        int maxPathSum = Math.max(Math.max(leftChildIncluded, rightChildIncluded), Math.max(completePath, root.val));
        pathSum[0] = Math.max(pathSum[0], maxPathSum);
        int returnToTop = Math.max(root.val, Math.max(leftChildIncluded, rightChildIncluded));
        // System.out.println("Node: " + root.val + " send: " + returnToTop + " maxTillNow: " + pathSum[0]);
        return returnToTop;
    }
}