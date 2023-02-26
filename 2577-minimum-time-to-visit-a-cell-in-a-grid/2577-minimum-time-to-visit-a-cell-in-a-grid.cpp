using cell = pair<int, pair<int, int>>;  
// cell = {min_time_required_to_reach_cell(x, y), {x, y}}

class Solution {
public:
    int dx[4] = {1, -1, 0, 0};  // x-direction move
    int dy[4] = {0, 0, 1, -1};  // y-direction move

    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        auto comp = [&](const auto& A, const auto& B) { return A.first > B.first; };
        priority_queue<cell, vector<cell>, decltype(comp)> pq(comp);
        pq.push({0, {0, 0}});
        vector<vector<int>> time_required(m, vector<int>(n, INT_MAX));
        int visited_count = 0;
        time_required[0][0] = 0;
        int lasttime = 0;
        while (!pq.empty()) {
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int timer = pq.top().first;
            ++timer;
            pq.pop();
            ++visited_count;
            for (int d = 0; d < 4; ++d) {
                int r = x + dx[d];
                int c = y + dy[d];
                if (r >= 0 and c >= 0 and r < m and c < n) {
                    if (time_required[r][c] == INT_MAX) {
                        if (visited_count == 1) {
                            if (grid[r][c] <= timer and time_required[r][c] > 1) {
                                time_required[r][c] = 1;
                                pq.push({1, {r, c}});
                            }
                        } else {
                            if (grid[r][c] <= timer) {
                                time_required[r][c] = timer;
                                pq.push({timer, {r, c}});
                            } else {
                                if ((timer % 2) == (grid[r][c] % 2)) {
                                    pq.push({grid[r][c], {r, c}});
                                    time_required[r][c] = grid[r][c];
                                } else {
                                    pq.push({grid[r][c] + 1, {r, c}});
                                    time_required[r][c] = grid[r][c] + 1;
                                }
                            }
                        }
                    }
                }
            }
        }
        return (time_required[m - 1][n - 1] == INT_MAX) ? -1 : time_required[m - 1][n - 1];
    }
};