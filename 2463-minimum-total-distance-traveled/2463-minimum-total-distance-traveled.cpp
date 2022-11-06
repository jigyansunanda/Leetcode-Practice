class Solution {
public:
    const long long inf = 1e18;
    vector<int> robot;
    vector<vector<int>> factory;
    int n;
    long long dp[111][111][111];

    long long minimumTotalDistance(vector<int>& _robot, vector<vector<int>>& _factory) {
        this->robot = _robot;
        this->factory = _factory;
        n = factory.size();
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        memset(dp, -1, sizeof dp);
        return solve(0, 0, factory[0][1]);
    }

    long long solve(int robot_index, int factory_index, int cnt) {
        if (robot_index == (int) robot.size()) return 0;
        if (factory_index == (int) factory.size()) return inf;
        if (cnt == 0) return solve(robot_index, factory_index + 1, (factory_index + 1 == n) ? 0 : factory[factory_index + 1][1]);
        if (dp[robot_index][factory_index][cnt] != -1) return dp[robot_index][factory_index][cnt];
        long long &ans = dp[robot_index][factory_index][cnt];
        ans = inf;
        long long subans1 = solve(robot_index + 1, factory_index, cnt - 1) ;
        if (subans1 != inf) subans1 += abs(robot[robot_index] - factory[factory_index][0]);
        long long subans2 = solve(robot_index, factory_index + 1, (factory_index + 1 == n) ? 0 : factory[factory_index + 1][1]);
        ans = min({ans, subans1, subans2});
        return ans;
    }
};