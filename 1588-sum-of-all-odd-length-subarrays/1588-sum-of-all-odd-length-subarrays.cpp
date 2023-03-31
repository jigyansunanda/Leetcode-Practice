class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = ((int) arr.size());
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int k = (i + 1) * (n - i);
            k = (k + 1) / 2;
            sum += (arr[i] * k);
        }
        return sum;
    }
};