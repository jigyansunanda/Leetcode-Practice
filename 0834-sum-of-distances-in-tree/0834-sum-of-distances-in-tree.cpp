class Solution {
public:
    int n;
    vector<vector<int>> tree;
    vector<int> nodeCount; // nodeCount[u] = # of nodes in subtree rooted at u
    vector<int> dp1; // dp1[u] = sum of distances from u to all nodes rooted in subtree of u
    vector<int> dp2; // dp2[u] = sum of distances from u to all nodes NOT rooted in subtree of u

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this->n = n;
        tree.resize(n);
        for (auto &e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        nodeCount.resize(n, 0);
        getNodeCount(0, 0);
        // print(nodeCount);

        dp1.resize(n, 0);
        dfs1(0, 0);
        // print(dp1);

        dp2.resize(n, 0);
        dfs2(0, 0);
        // print(dp2);

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            ans.push_back(dp1[i] + dp2[i]);
        }
        return ans;
    }

    void dfs2(int u, int p) {
        if (u != 0) {
            dp2[u] += (dp2[p] + n - nodeCount[p] + 1);
        }
        if (u != 0) {
            for (auto &siblings : tree[p]) {
                if (siblings == u or nodeCount[siblings] > nodeCount[p]) continue;
                dp2[u] += (dp1[siblings] + (2 * nodeCount[siblings]));
            }
        }
        for (auto &v : tree[u]) {
            if (v != p) {
                dfs2(v, u);
            }
        }
    }

    void dfs1(int u, int p) {
        for (int &v : tree[u]) {
            if (v != p) {
                dfs1(v, u);
                dp1[u] += (dp1[v] + nodeCount[v]);
            }
        }
    }

    void getNodeCount(int u, int p) {
        nodeCount[u] += 1;
        for (int &v : tree[u]) {
            if (v != p) {
                getNodeCount(v, u);
                nodeCount[u] += nodeCount[v];
            }
        }
    }
};