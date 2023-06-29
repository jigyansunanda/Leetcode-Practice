class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        for (auto& item : items) {
            mp[item[0]].push(item[1]);
            if (mp[item[0]].size() > 5) mp[item[0]].pop();
        }
        vector<vector<int>> ans;
        for (auto e : mp) {
            int sum = 0;
            while (mp[e.first].empty() == false) {
                sum += mp[e.first].top();
                mp[e.first].pop();
            }
            ans.push_back({e.first, sum / 5});
        }
        return ans;
    }
};