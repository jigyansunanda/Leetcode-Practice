class Solution {
public:
    int search(vector<int>& A, int x) {
        int l = 0, r = A.size() - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (A[mid] == x) return mid;
            // binary search based on "which side of mid is sorted ? left or right
            // find out by comparing A[l] and A[mid]"
            else if (A[l] <= A[mid]) {
                if (A[l] <= x and x < A[mid]) r = mid - 1;
                else l = mid + 1;
            } else {  // A[l] > A[mid]
                if (A[mid] < x and x <= A[r]) l = mid + 1;
                else r = mid - 1;
            }
        }
        return -1;
    }
};