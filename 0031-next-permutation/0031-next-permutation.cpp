class Solution {
public:
    void nextPermutation(vector<int>& A) {
        int n = A.size();
        int index = -1;
        for (int i = n - 1; i >= 1; --i) {
            if (A[i] > A[i - 1]) {
                index = i - 1;
                break;
            }
        }
        if (index == -1) {
            reverse(A.begin(), A.end());
            return;
        } else {
            int maxIndex = index + 1;
            for (int i = maxIndex; i <= n - 1; ++i) {
                if (A[i] > A[index]) maxIndex = i;
                else break;
            }
            swap(A[index], A[maxIndex]);
            reverse(A.begin() + index + 1, A.end());
        }
    }
};