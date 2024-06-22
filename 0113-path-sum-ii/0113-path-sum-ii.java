class Solution {
    private List<List<Integer>> paths;

    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        this.paths = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        dfs(root, targetSum, path);
        return paths;
    }

    private void dfs(TreeNode root, int targetSum, List<Integer> path) {
        if (root == null) return;
        targetSum -= root.val;
        path.add(root.val);
        if (root.left == null && root.right == null) {
            if (targetSum == 0) paths.add(new ArrayList<>(path));
        } else {
            dfs(root.left, targetSum, path);
            dfs(root.right, targetSum, path);
        }
        targetSum += root.val;
        path.remove(path.size() - 1);
    }
}