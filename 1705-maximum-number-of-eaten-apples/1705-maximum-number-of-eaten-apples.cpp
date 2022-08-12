class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int ans = 0, day = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (day = 0; day < apples.size(); ++day) {
            if (apples[day]) {
                pq.push(make_pair(day + days[day], day));
            }
            while (!pq.empty() and pq.top().first <= day) {
                pq.pop();
            }
            if (pq.empty()) continue;
            apples[pq.top().second]--;
            ans++;
            if (apples[pq.top().second] == 0) pq.pop();
        }
        while (!pq.empty()) {
            while (!pq.empty() and pq.top().first <= day) {
                pq.pop();
            }
            if (pq.empty()) continue;
            apples[pq.top().second]--;
            ans++;
            if (apples[pq.top().second] == 0) pq.pop();
            day++;
        }
        return ans;
    }
};