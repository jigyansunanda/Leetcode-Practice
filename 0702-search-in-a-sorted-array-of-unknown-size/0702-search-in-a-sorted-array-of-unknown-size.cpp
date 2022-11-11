/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int lo = -1, hi = 1e4+1;
        while (hi > lo + 1) {
            int mid = (lo + hi) >> 1;
            int num = reader.get(mid);
            if (num >= target) hi = mid;
            else lo = mid;
        }
        return (reader.get(hi) != target) ? -1 : hi;
    }
};