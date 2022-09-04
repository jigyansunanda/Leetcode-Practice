class Solution {
public:
	int mostBooked(int n, vector<vector<int>>& meetings) {
		sort(meetings.begin(), meetings.end());
		vector<int> meet(101, 0);
		priority_queue<int, vector<int>, greater<int>> availableRoom;
		for (int i = 0; i < n; ++i) availableRoom.push(i);
		priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busyRoom;
		for (auto &m : meetings) {
			while (!busyRoom.empty() and busyRoom.top().first <= m[0]) {
				availableRoom.push(busyRoom.top().second);
				busyRoom.pop();
			}
			long long startTime = (availableRoom.empty()) ? busyRoom.top().first : m[0];
			long long duration = m[1] - m[0];
			int nextAvailable = (availableRoom.empty()) ? busyRoom.top().second : availableRoom.top();
			if (availableRoom.empty()) busyRoom.pop();
			else availableRoom.pop();
			meet[nextAvailable]++;
			busyRoom.push({startTime + duration, nextAvailable});
		}
		return max_element(meet.begin(), meet.end()) - meet.begin();
	}
};