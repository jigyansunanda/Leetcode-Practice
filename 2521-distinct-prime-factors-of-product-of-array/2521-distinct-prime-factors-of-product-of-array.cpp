class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        vector<bool> isPrime(1001, true);
        vector<int> primes;
        for (int i = 2; i <= 1000; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
                for (int j = 2 * i; j < 1001; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        unordered_set<int> st;
        for (auto e : nums) {
            int n = e;
            for (int i = 0; i<primes.size() and n>1; ++i) {
                if (n % primes[i] == 0) {
                    st.insert(primes[i]);
                    while (n % primes[i] == 0) n /= primes[i];
                }
            }
        }
        return st.size();
    }
};