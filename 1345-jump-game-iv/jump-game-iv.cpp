class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        map<int, vector<int>> mp;
        for (int i = 0; i < arr.size(); ++i) {
            mp[arr[i]].push_back(i);
        }
        vector<int> d(n, INT_MAX);
        queue<int> q;
        q.push(0);
        d[0] = 0;
        while (!q.empty()) {
            int index = q.front();
            q.pop();
            if (index + 1 < arr.size() and d[index + 1] == INT_MAX) {
                d[index + 1] = d[index] + 1;
                q.push(index + 1);
            }
            if (index - 1 >= 0 and d[index - 1] == INT_MAX) {
                d[index - 1] = d[index] + 1;
                q.push(index - 1);
            }
            vector<int> &ids = mp[arr[index]];
            for (auto &id : ids) {
                if (d[id] == INT_MAX) {
                    d[id] = d[index] + 1;
                    q.push(id);
                }
            }
            ids.clear();
        }
        return d[arr.size() - 1];
    }
};
