class Solution {
public:
	bool reorderedPowerOf2(int n) {
		vector<long long> d;
		while (n) {
			d.push_back(n % 10);
			n /= 10;
		}
		sort(d.begin(), d.end());
		function<bool()> check = [&]() {
			if (d[0] == 0) return false;
			long long sum = 0;
			for (auto c : d) sum = (sum * 10) + c;
			return (sum & (sum - 1)) == 0;
		};
		do {
			bool isPossible = check();
			if (isPossible) return true;
		} while (next_permutation(d.begin(), d.end()));
		return false;
	}
};