var search = function (A, N, val) {
  let lo = -1;
  let hi = N;
  while (hi > lo + 1) {
    let mid = Math.floor((lo + hi) / 2);
    if (A[mid] > val) hi = mid;
    else lo = mid;
  }
  return N - hi;
};

var countPairs = function (A, B) {
  var n = A.length;
  for (let i = 0; i < n; ++i) A[i] -= B[i];
  A.sort(function(a, b){return a - b});
  var ans = 0;
  for (let j = 0; j < n; ++j) {
    //      A[i] + A[j] > 0
    // =>   A[i] > -A[j]
    var k = search(A, j, -A[j]);
    ans += k;
  }
  return ans;
};