var maxLength = function (ribbons, k) {
  let lo = 0,
    hi = 1000000000;
  while (hi > lo + 1) {
    let mid = Math.floor((lo + hi) / 2);
    if (Possible(ribbons, mid, k)) lo = mid;
    else hi = mid;
  }
  return lo;
};

var Possible = function (ribbons, m, k) {
  var count = 0;
  for (let i = 0; i < ribbons.length; ++i) {
    count += Math.floor(ribbons[i] / m);
  }
  return count >= k;
};
