class Solution {
public:
	int totalFruit(vector<int>& fruits) {
		int n = fruits.size();
		int l = 0, d = 0;
		int color[100002] = {0};
		int maxFruits = 0;
		for (int r = 0; r < n; ++r) {
			color[fruits[r]]++;
			if (color[fruits[r]] == 1) d++;
			while (d > 2) {
				color[fruits[l]]--;
				if (color[fruits[l]] == 0) d--;
				++l;
			}
			if (d < 3) {
				maxFruits = max(maxFruits, r - l + 1);
			}
		}
		return maxFruits;
	}
};