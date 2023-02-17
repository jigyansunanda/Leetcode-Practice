class Solution {
    int ans, prev;

    public int minDiffInBST(TreeNode root) {
        ans = Integer.MAX_VALUE;
        prev = Integer.MAX_VALUE;
        solve(root);
        return ans;
    }

    public void solve(TreeNode root) {
        if (root != null) {
            solve(root.left);
            if (prev != Integer.MAX_VALUE) {
                // System.out.println(Math.abs(root.val - prev));
                ans = Math.min(ans, Math.abs(root.val - prev));
            }
            prev = root.val;
            solve(root.right);
        }
    }
}