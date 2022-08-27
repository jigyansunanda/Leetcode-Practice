class Solution {
public:

	int dp[1005][1005];

	int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
		memset(dp, -1, sizeof dp);
		return minHeightShelves(books, shelfWidth, 0, 0, 0);
	}

	int minHeightShelves(vector<vector<int>> &books, int shelfWidth, int index, int width, int height) {
		if (index >= books.size()) return height;
		if (dp[index][width] != -1) return dp[index][width];
		dp[index][width] = minHeightShelves(books, shelfWidth, index + 1, books[index][0], books[index][1]) + height;
		if (width + books[index][0] <= shelfWidth) {
			int ans = minHeightShelves(books, shelfWidth, index + 1, width + books[index][0], max(height, books[index][1]));
			dp[index][width] = min(ans, dp[index][width]);
		}
		return dp[index][width];
	}
};