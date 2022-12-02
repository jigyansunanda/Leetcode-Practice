/**
 * @param {number[]} arr1
 * @param {number[]} arr2
 * @param {number[]} arr3
 * @return {number[]}
 */
var arraysIntersection = function (arr1, arr2, arr3) {
    let p = 0,
        q = 0,
        r = 0;
    var ans = [];
    while (p < arr1.length && q < arr2.length && r < arr3.length) {
        if (arr1[p] == arr2[q] && arr2[q] == arr3[r]) {
            ans.push(arr1[p]);
            ++p;
            ++q;
            ++r;
        } else {
            if (arr1[p] < arr2[q]) ++p;
            else if (arr2[q] < arr3[r]) ++q;
            else ++r;
        }
    }
    return ans;
};
