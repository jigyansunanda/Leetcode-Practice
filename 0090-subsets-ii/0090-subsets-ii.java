class Solution {

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> subsets = new ArrayList<>();
        List<Integer> subset = new ArrayList<>();
        Arrays.sort(nums);
        solve(subset, subsets, 0, nums);
        return subsets;
    }
    
    public void solve(List<Integer> subset, List<List<Integer>> subsets, int index, int[] nums) {
        subsets.add(new ArrayList<>(subset));
        // print(subset);
        for (int next = index; next < nums.length; ++next) {
            if (next != index && nums[next] == nums[next - 1]) continue;
            subset.add(nums[next]);
            solve(subset, subsets, next+1, nums);
            subset.remove(subset.size() - 1);
        }
    }
    
    public void print(List<Integer> subset) {
        for (int i=0; i<subset.size(); ++i) {
            System.out.print(subset.get(i)+" ");
        }
        System.out.println();
    }
}
