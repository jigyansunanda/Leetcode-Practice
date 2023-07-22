class Solution {
public:
    vector<int> nextPermutation(vector<int>& A) {
        int n = A.size();
        int index = -1;
        for (int i = n - 1; i >= 1; --i) {
            if (A[i] > A[i - 1]) {
                index = i - 1;
                break;
            }
        }
        if (index == -1) return {};
        else {
            int maxIndex = index + 1;
            for (int i = maxIndex; i <= n - 1; ++i) {
                if (A[i] > A[index]) maxIndex = i;
                else break;
            }
            swap(A[index], A[maxIndex]);
            reverse(A.begin() + index + 1, A.end());
            return A;
        }
    }

    int nextGreaterElement(int n) {
        vector<int> digits;
        while (n) {
            digits.push_back(n % 10);
            n /= 10;
        }
        reverse(digits.begin(), digits.end());
        auto v = nextPermutation(digits);
        if (v.empty()) return -1;
        int ans = 0;
        for (auto e : v) {
            if (ans > (INT_MAX / 10) or (ans == (INT_MAX / 10) and e > (INT_MAX % 10))) return -1;
            ans = (ans * 10) + e;
        }
        return ans;
    }
};