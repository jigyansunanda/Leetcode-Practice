class HitCounter {
private:
	int total;
	deque<pair<int, int>> dq;

public:
	HitCounter() {
		total = 0;
	}

	void hit(int t) {
		total++;
		if (dq.empty() == false and dq.back().first == t) {
			dq.back().second++;
		} else {
			dq.emplace_back(t, 1);
		}
	}

	int getHits(int t) {
		while (!dq.empty()) {
			int currtime = dq.front().first;
			if (t - currtime >= 300) {
				total -= dq.front().second;
				dq.pop_front();
			} else break;
		}
		return total;
	}
};