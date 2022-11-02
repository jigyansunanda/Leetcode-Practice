class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        bank.push_back(start);
        int n = bank.size();
        vector<int> g[n];
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isMutated(bank[i], bank[j])) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        vector<int> d(n, INT_MAX);
        queue<int> q;
        q.push(n - 1);
        d[n - 1] = 0;
        while (q.empty() == false) {
            int u = q.front();
            q.pop();
            if (bank[u] == end) return d[u];
            for (int v : g[u]) {
                if (d[v] == INT_MAX) {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
        return -1;
    }

    bool isMutated(string &A, string &B) {
        int count = 0;
        for (int i = 0; i < 8; ++i) {
            count += (A[i] != B[i]);
        }
        return (count == 1);
    }
};