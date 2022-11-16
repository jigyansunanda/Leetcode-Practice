/**
 * @param {number[]} days
 * @param {number[]} costs
 * @return {number}
 */
function back(array) {
  return array[array.length - 1];
}

var mincostTickets = function (days, costs) {
  var dp = new Array(366).fill(10000000);
  const set = new Set(days);
  dp[0] = 0;
  for (let day = 1; day <= Math.max(365, back(days)); ++day) {
    if (set.has(day) == false) {
      dp[day] = dp[day - 1];
    } else {
      dp[day] = Math.min(dp[day], dp[Math.max(0, day - 1)] + costs[0]);
      dp[day] = Math.min(dp[day], dp[Math.max(0, day - 7)] + costs[1]);
      dp[day] = Math.min(dp[day], dp[Math.max(0, day - 30)] + costs[2]);
    }
  }
  return dp[back(days)];
};