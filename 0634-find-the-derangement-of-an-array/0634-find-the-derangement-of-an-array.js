var findDerangement = function (n) {
  if (n <= 1) return 0;
  const mod = 1e9 + 7;
  let dp = new Array(n + 1);
  for (let i = 0; i < n + 1; ++i) dp[i] = 0;
  // dp[i] = # of derangements of first i numbers
  dp[0] = dp[1] = 0;
  dp[2] = 1;
  for (let i = 3; i < n + 1; ++i) {
    dp[i] =
      ((((i - 1) * dp[i - 2]) % mod) + (((i - 1) * dp[i - 1]) % mod)) % mod;
  }
  return dp[n];
};
