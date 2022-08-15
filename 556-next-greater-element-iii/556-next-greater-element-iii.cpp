class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digits;
        while (n) {
            digits.push_back(n % 10);
            n /= 10;
        }
        reverse(digits.begin(), digits.end());
        long long int_max = (long long) INT_MAX;
        long long next_number = getNextNumber(digits);
        if (next_number == -1 or next_number > int_max) return -1;
        if (next_number == (long long) n) return -1;
        return (int) next_number;
    }

    long long getNextNumber(vector<int>& digits) {
        bool isNextPermutation = getNextPermutation(digits);
        if (!isNextPermutation) return -1;
        long long num = 0;
        for (auto e : digits) {
            num = (num * 10) + (long long) e;
        }
        return num;
    }

    bool getNextPermutation(vector<int>& digits) {
        int index = -1;
        for (int i = digits.size() - 2; i >= 0; --i) {
            if (digits[i] < digits[i + 1]) {
                index = i;
                break;
            }
        }
        if (index == -1) return false;
        int next = index + 1, largest = index + 1;
        while (next < digits.size()) {
            if (digits[next] > digits[index] and digits[largest] >= digits[next]) {
                largest = next;
            }
            ++next;
        }
        swap(digits[index], digits[largest]);
        reverse(digits.begin() + index + 1, digits.end());
        return true;
    }
};