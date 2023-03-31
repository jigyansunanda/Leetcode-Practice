class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> edge_scores(n, 0);
        long long max_score = 0;
        for (int i = 0; i < n; ++i) {
            edge_scores[edges[i]] += i;
            max_score = max(max_score, edge_scores[edges[i]]);
        }
        for (int i = 0; i < n; ++i) {
            if (edge_scores[i] == max_score) return i;
        }
        return -1;
    }
};