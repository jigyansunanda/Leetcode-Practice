/**
 * @param {number[]} nums
 * @return {number}
 */
var maxCoins = function (nums) {
  var n = nums.length;
  var dp = Array.from(Array(n), () => new Array(n).fill(-1));
  return solve(nums, 0, n - 1, dp);
};

var solve = function (nums, l, r, dp) {
  if (l > r) return 0;
  if (l == r)
    return (
      nums[l] *
      (l - 1 >= 0 ? nums[l - 1] : 1) *
      (r + 1 < nums.length ? nums[r + 1] : 1)
    );
  if (dp[l][r] != -1) return dp[l][r];
  var ans = 0;
  for (let last = l; last <= r; ++last) {
    var leftCoins = solve(nums, l, last - 1, dp);
    var rightCoins = solve(nums, last + 1, r, dp);
    var currCoins = nums[last];
    if (l - 1 >= 0) currCoins *= nums[l - 1];
    if (r + 1 < nums.length) currCoins *= nums[r + 1];
    ans = Math.max(ans, leftCoins + currCoins + rightCoins);
  }
  return (dp[l][r] = ans);
};