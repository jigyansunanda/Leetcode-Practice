struct DSU {
public:
    int components;
    vector<int> Parent, Rank;

    DSU(int n) : components(n), Parent(n), Rank(n, 1) { iota(Parent.begin(), Parent.end(), 0); }

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
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);
        map<string, int> emailToID;
        for (int i = 0; i < (int)accounts.size(); ++i) {
            int m = accounts[i].size();
            for (int j = 1; j < m; ++j) {
                string email = accounts[i][j];
                if (emailToID.find(email) == emailToID.end()) {
                    emailToID[email] = i;
                } else {
                    dsu.merge(i, emailToID[email]);
                }
            }
        }
        map<int, vector<string>> nameIDtoEmail;
        for (auto &e : emailToID) {
            int id = dsu.find(e.second);
            nameIDtoEmail[id].push_back(e.first);
        }
        vector<vector<string>> answer;
        for (auto &e : nameIDtoEmail) {
            vector<string> subans;
            subans.push_back(accounts[e.first][0]);
            for (auto &s : e.second) {
                subans.push_back(s);
            }
            sort(subans.begin() + 1, subans.end());
            answer.push_back(subans);
        }
        return answer;
    }
};