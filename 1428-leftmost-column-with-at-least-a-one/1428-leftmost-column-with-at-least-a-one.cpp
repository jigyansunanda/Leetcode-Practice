/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        auto d = binaryMatrix.dimensions();
        int m = d[0], n = d[1];
        int lo = -1, hi = n;
        while (hi > lo + 1) {
            int mid = (lo + hi) >> 1;
            bool ok = false;
            for (int i = 0; i < m; ++i) {
                if (binaryMatrix.get(i, mid) == 1) {
                    ok = true;
                    break;
                }
            }
            if (ok) hi = mid;
            else lo = mid;
        }
        return (hi == n) ? -1 : hi;
    }
};