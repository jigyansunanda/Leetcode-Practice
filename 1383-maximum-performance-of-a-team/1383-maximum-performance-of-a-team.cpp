class Solution {
public:
	int maxPerformance(int n, vector<int>& speed, vector<int>& eff, int k) {
		const long long mod = 1e9 + 7;
		vector<pair<long long, long long>> v;
		for (int i = 0; i < n; ++i) v.emplace_back(eff[i], speed[i]);
		sort(v.begin(), v.end());
		priority_queue<long long, vector<long long>, greater<long long>> pq; // minheap
		long long currsum = 0;  // current sum of elements inside heap
		vector<long long> ans(n, 0);
		for (int i = n - 1; i >= 0; --i) {
			long long minEfficiency = v[i].first; // considering current efficiency
			long long sumOfSpeed = currsum;
			if (pq.size() == k) {
				sumOfSpeed = (sumOfSpeed - pq.top());
			}
			sumOfSpeed = (sumOfSpeed + v[i].second); // added own speed
			ans[i] = (sumOfSpeed * minEfficiency); // calculated answer
			pq.push(v[i].second); // enter current speed into heap
			currsum = (currsum + v[i].second); // updated total heap sum
			if (pq.size() > k) {
				currsum = (currsum - pq.top()); // updated heap sum for size
				pq.pop();
			}
		}
		return (*max_element(ans.begin(), ans.end())) % mod;
	}
};