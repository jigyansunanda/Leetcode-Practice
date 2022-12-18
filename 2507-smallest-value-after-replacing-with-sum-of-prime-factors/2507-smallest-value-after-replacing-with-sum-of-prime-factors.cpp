class Solution {
public:
    int smallestValue(int n) {
        vector<int> primes;
        vector<bool> p(100005, true); p[0] = p[1] = false;
        for (int i = 2; i <= 100004; ++i) {
            if (p[i]) {
                primes.push_back(i);
                for (int j = 2 * i; j < 100005; j += i) {
                    p[j] = false;
                }
            }
        }
        int prev = n;
        while (n > 2 and p[n] == false) {
            int curr = 0;
            int N = n;
            for (auto &e : primes) {
                if (e > N) break;
                if (N % e == 0) {
                    int count = 0;
                    while (N % e == 0) {
                        count++;
                        N /= e;
                    }
                    curr += (count * e);
                }
            }
            if (curr == prev) break;
            prev = n;
            n = curr;
        }
        return n;
    }
};