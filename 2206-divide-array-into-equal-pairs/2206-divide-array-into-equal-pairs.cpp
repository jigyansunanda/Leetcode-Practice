class Solution {
public:
	bool divideArray(vector<int>& nums) {
		int c[501] = {0};
		for (auto &e : nums) c[e]++;
		int count = count_if(c, c + 501, [](int x) {return (x & 1);});
		return (count == 0);
	}
};