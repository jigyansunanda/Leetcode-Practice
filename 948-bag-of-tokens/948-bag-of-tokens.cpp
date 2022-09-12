class Solution {
public:
	int bagOfTokensScore(vector<int>& tokens, int power, int ans = 0) {
		sort(tokens.begin(), tokens.end());
		int score = 0, l = 0, r = tokens.size() - 1;
		while (l <= r and (power >= tokens[l] or score > 0)) {
			while (l <= r and power >= tokens[l]) {
				power -= tokens[l++];
				score++;
				ans = max(ans, score);
			}
			if (l <= r and score > 0) {
				--score;
				power += tokens[r--];
			}
		}
		return ans;
	}
};