class Solution {
private:
    int getRandomNumber(int L, int R) {
        int len = R - L + 1;
        return L + (rand() % len);
    }

public:
    int findKthLargest(vector<int>& A, int K) {
        int N = A.size();
        int L = 0, R = N - 1;
        while (L <= R) {
            int pivotIndex = partition(A, L, R);
            if (pivotIndex == N - K) return A[pivotIndex];
            else if (pivotIndex < N - K) L = pivotIndex + 1;
            else R = pivotIndex - 1;
        }
        return -1;
    }

    int partition(vector<int>& A, int L, int R) {
        int randomIndex = getRandomNumber(L, R);
        swap(A[randomIndex], A[R]);
        int index = L;
        for (int i = L; i <= R; ++i) {
            if (A[i] <= A[R]) {
                swap(A[index++], A[i]);
            }
        }
        return index - 1;
    }
};