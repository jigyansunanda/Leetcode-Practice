class Solution {
public:
    int z = 1e6 + 1;
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(z, true);
        vector<int> primes;
        for (int i = 2; i <= z - 1; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
                for (int j = 2 * i; j < z; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        int p = -1, q = -1;
        int lo = -1, hi = primes.size();
        while (hi > lo + 1) {
            int mid = (lo + hi) >> 1;
            if (primes[mid] < left) lo = mid;
            else hi = mid;
        }
        p = hi;
        lo = -1, hi = primes.size();
        while (hi > lo + 1) {
            int mid = (lo + hi) >> 1;
            if (primes[mid] > right) hi = mid;
            else lo = mid;
        }
        q = lo;
        if ((q - p + 1) < 2) return { -1, -1};
        int maxdiff = 1e9, a = -1, b = -1;
        for (int i = p; i <= q - 1; ++i) {
            if (primes[i + 1] - primes[i] < maxdiff) {
                maxdiff = primes[i + 1] - primes[i];
                a = primes[i];
                b = primes[i + 1];
            }
        }
        return {a, b};
    }
};