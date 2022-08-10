#define fr(i, n) for (int i = 0; i < (int)n; i++)
#define frr(i, a, b) for (int i = (int)a; i <= (int)b; i++)
#define fro(i, a, b) for (int i = (int)a; i >= (int)b; i--)

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> g[n];
        fr(i, n) if (edges[i] != -1) g[i].push_back(edges[i]);
        vector<int> d1(n, INT_MAX), d2(n, INT_MAX);
        bfs(node1, d1, g);
        bfs(node2, d2, g);
        int maxd = INT_MAX, ans = -1;
        fr(i, n) {
            if (d1[i] == INT_MAX or d2[i] == INT_MAX) continue;
            int md = max(d1[i], d2[i]);
            if (md < maxd) {
                maxd = md;
                ans = i;
            }
        }
        return ans;
    }

    void bfs(int node, vector<int>& d, vector<int> *g) {
        queue<int> q;
        q.push(node);
        d[node] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                if (d[v] == INT_MAX or d[v] > d[u] + 1) {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
    }
};