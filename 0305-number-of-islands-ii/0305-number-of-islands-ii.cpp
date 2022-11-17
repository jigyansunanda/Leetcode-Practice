#include <bits/stdc++.h>
using namespace::std;

/* ------------------------------------- Debugger ------------------------------------------ */

template<typename A, typename B> std::ostream& operator<<(std::ostream &os, const std::pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template < typename T_container, typename T = typename std::enable_if < !std::is_same<T_container, std::string>::value, typename T_container::value_type >::type > std::ostream & operator<<(std::ostream &os, const T_container &v) { os << '{'; std::string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void debug() { std::cout << '\n'; }
template<typename Head, typename... Tail> void debug(Head H, Tail... T) { std::cout << ' ' << H; debug(T...); }

// void print(ListNode* head) {while (head) {cout << head->val << ' '; head = head->next;} cout << '\n';}

#ifdef LOCAL_MACHINE
#include "leetcode.h"
#define debug(...) std::cout << "(" << #__VA_ARGS__ << "):", debug(__VA_ARGS__)
#else
#define debug(...) 42
#define print(...) 42
#endif

/* ----------------------------------------------------------------------------------------- */

struct DSU {
public:
    int components;
    vector<int> Parent, Rank;

    DSU(int n) : components(0), Parent(n, -1), Rank(n, 1) {}

    int find(int x) {
        while (x != Parent[x]) x = Parent[x] = Parent[Parent[x]];
        return x;
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (Rank[x] > Rank[y]) swap(x, y);
        Parent[x] = y;
        Rank[y] += Rank[x];
        --components;
        return true;
    }

    void makeIsland(int id) {
        Parent[id] = id;
        ++components;
    }
};

class Solution {
public:
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};

    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> ans;
        DSU dsu(m * n);
        for (auto &pos : positions) {
            int i = pos[0], j = pos[1];
            int curr = (i * n) + j;
            if (dsu.Parent[curr] != -1) {
                ans.push_back(dsu.components);
                continue;
            }
            dsu.makeIsland(curr);
            for (int dir = 0; dir < 4; ++dir) {
                int x = i + dx[dir];
                int y = j + dy[dir];
                if (x < 0 or y < 0 or x >= m or y >= n) continue;
                int next = (x * n) + y;
                if (dsu.Parent[next] != -1) {
                    dsu.merge(curr, next);
                }
            }
            ans.push_back(dsu.components);
        }
        return ans;
    }
};

#ifdef LOCAL_MACHINE
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
}
#endif