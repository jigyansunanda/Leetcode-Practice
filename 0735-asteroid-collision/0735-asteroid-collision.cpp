class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (auto e : asteroids) {
            if (e > 0) st.push(e);
            else {
                if (st.empty()) st.push(e);
                else {
                    bool isAsteroidDestroyed = false;
                    while (!st.empty() and (st.top() > 0)) {
                        if (abs(st.top()) == abs(e)) {
                            st.pop();
                            isAsteroidDestroyed = true;
                            break;
                        } else if (abs(st.top()) < abs(e)) {
                            st.pop();
                        } else {
                            isAsteroidDestroyed = true;
                            break;
                        }
                    }
                    if (!isAsteroidDestroyed) st.push(e);
                }
            }
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};