/**
 * @param {number[]} arr
 * @return {number}
 */
var minimumMoves = function (arr) {
  var n = arr.length;
  var dp = Array.from(Array(n), () => new Array(n).fill(n));
  for (let i = 0; i < n; ++i) {
    dp[i][i] = 1;
    if (i + 1 < n) {
      if (arr[i] == arr[i + 1]) dp[i][i + 1] = 1;
      else dp[i][i + 1] = 2;
    }
  }
  for (let len = 3; len <= n; ++len) {
    for (let i = 0; i + len - 1 < n; ++i) {
      let j = i + len - 1;
      if (arr[i] == arr[j]) {
        dp[i][j] = dp[i + 1][j - 1];
      }
      for (let mid = i; mid < j; ++mid) {
        dp[i][j] = Math.min(dp[i][j], dp[i][mid] + dp[mid + 1][j]);
      }
    }
  }
  return dp[0][n - 1];
};