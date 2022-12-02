/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var twoSumLessThanK = function (nums, k) {
    let n = nums.length;
    let count = new Array(1001).fill(0);
    for (let i = 0; i < nums.length; ++i) count[nums[i]]++;
    let lo = 1,
        hi = 1000,
        ans = -1;
    while (hi >= lo) {
        if (count[lo] == 0) {
            ++lo;
            continue;
        }
        if (count[hi] == 0) {
            --hi;
            continue;
        }
        if (lo + hi < k) {
            if (lo != hi) {
                ans = Math.max(ans, lo + hi);
            } else if (count[lo] > 1) {
                ans = Math.max(ans, 2 * lo);
            }
            ++lo;
        } else {
            --hi;
        }
    }
    return ans;
};
