#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

class Solution {
public:
	int numberOfWeakCharacters(vector<vector<int>>& properties, int ans = 0) {
		sort(begin(properties), end(properties), [](const auto& a, const auto& b) {
			return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
		});
		int max_defense = 0;
		for (int index = properties.size() - 1; index >= 0; --index) {
			ans += (properties[index][1] < max_defense);
			max_defense = max(max_defense, properties[index][1]);
		}
		debug(properties);
		return ans;
	}
};