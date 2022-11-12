/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int n = reader.length();
        int l = 0, r = n-1;
        while (r > l + 1) {
            int v;
            int m = (l + r) >> 1;
            int size = (r - l + 1);
            if (size % 2 == 1) {
                v = reader.compareSub(l, m, m, r);
            }else {
                v = reader.compareSub(l, m, m+1, r);
            }
            if (v == 0) return m;
            else if (v == 1) r = m;
            else l = m;
        }
        if (reader.compareSub(l,l,r,r) == 1) return l;
        return r;
    }
};