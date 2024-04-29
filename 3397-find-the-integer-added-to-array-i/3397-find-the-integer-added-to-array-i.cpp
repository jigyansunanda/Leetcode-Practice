class Solution {
public:
    int addedInteger(vector<int>& A, vector<int>& B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        return B[0] - A[0];
    }
};