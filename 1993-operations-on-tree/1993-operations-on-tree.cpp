class LockingTree {
public:
    int n;
    vector<vector<int>> tree;
    vector<int> locked_by, locked_child_count, locked_parent_count, parents;

    LockingTree(vector<int>& parent) {
        n = ((int) parent.size());
        tree.resize(n);
        for (int i = 1; i <= n - 1; ++i) tree[parent[i]].push_back(i);
        locked_by.resize(n, -1);
        locked_child_count.resize(n, 0);
        locked_parent_count.resize(n, 0);
        parents = parent;
    }

    bool lock(int num, int user) {
        if (locked_by[num] != -1) return false;
        locked_by[num] = user;
        update_all_child(num, 1);
        update_all_parent(num, 1);
        return true;
    }

    bool unlock(int num, int user) {
        if (locked_by[num] != user) return false;
        locked_by[num] = -1;
        update_all_child(num, -1);
        update_all_parent(num, -1);
        return true;
    }

    bool upgrade(int num, int user) {
        if (locked_by[num] != -1) return false;
        if (locked_child_count[num] == 0) return false;
        if (locked_parent_count[num]) return false;
        locked_by[num] = user;
        update_all_child(num, -2);
        update_all_parent(num, 1);
        return true;
    }

    // update all parent child lock count when a child is locked/unlocked
    void update_all_parent(int num, int lock) {
        int parentId = num;
        while (parentId != -1) {
            locked_child_count[parentId] += lock;
            parentId = parents[parentId];
        }
    }

    // update all the children lock count if parent is locked or upgraded
    void update_all_child(int num, int lock) {
        queue<int> q;
        q.push(num);
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int cur = q.front();
                q.pop();
                for (auto& c : tree[cur]) {
                    // clear all child locks and keep
                    // locked_parent_count count
                    if (lock == -2) {
                        locked_parent_count[c] = 1;
                        locked_by[c] = -1;
                    } else locked_parent_count[c] += lock;

                    q.push(c);
                }
            }
        }
    }
};