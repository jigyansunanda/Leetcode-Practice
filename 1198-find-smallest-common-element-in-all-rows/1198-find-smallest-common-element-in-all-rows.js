/**
 * @param {number[][]} mat
 * @return {number}
 */
var smallestCommonElement = function(mat) {
    var m = mat.length;
    var n = mat[0].length;
    var c = new Array(10001).fill(0);
    for (let i=0; i<m; ++i) {
        for (let j=0; j<n; ++j) {
            c[mat[i][j]]++;
            if (c[mat[i][j]] == m) return mat[i][j];
        }
    }
    return -1;
};