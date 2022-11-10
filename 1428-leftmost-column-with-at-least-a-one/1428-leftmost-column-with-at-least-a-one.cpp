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
    int leftMostColumnWithOne(BinaryMatrix &m) {
        auto dim = m.dimensions();
        int row = dim[0], col = dim[1];
        int currRow = 0, currCol = col - 1;
        while (currRow < row and currCol >= 0) {
            if (m.get(currRow, currCol) == 0) {
                ++currRow;
            }else {
                --currCol;
            }
        }
        return (currCol == col-1) ? -1 : currCol+1;
    }
};