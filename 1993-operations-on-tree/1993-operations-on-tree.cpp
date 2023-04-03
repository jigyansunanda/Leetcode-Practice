class LockingTree {
public:
    int query_time;
    vector<int> parents, locked_by, locked_child_count, lock_time, upgrade_time;

    LockingTree(vector<int>& parent) {
        int n = parent.size();
        query_time = 0;
        parents = parent;
        locked_by.resize(n, -1);
        locked_child_count.resize(n, 0);
        lock_time.resize(n, -2);
        upgrade_time.resize(n, -1);
    }

    bool lock(int num, int user) {
        if (is_still_locked(num)) return false;
        locked_by[num] = user;
        lock_time[num] = ++query_time;
        update_locked_child_count(num, 1);
        return true;
    }

    bool unlock(int num, int user) {
        if (is_still_locked(num)) {
            if (locked_by[num] != user) return false;
            locked_by[num] = -1;
            lock_time[num] = -2;
            update_locked_child_count(num, -1);
            return true;
        }
        return false;
    }

    bool upgrade(int num, int user) {
        if (is_still_locked(num)) return false;
        if (has_locked_ancestor(num)) return false;
        if (locked_child_count[num] == 0) return false;
        locked_by[num] = user;
        lock_time[num] = upgrade_time[num] = ++query_time;
        update_locked_child_count(num, -locked_child_count[num] + 1);
        return true;
    }

    bool has_locked_ancestor(int num) {
        int ancestor = parents[num];
        int max_lock_time = -2;
        while (ancestor != -1) {
            max_lock_time = max(max_lock_time, lock_time[ancestor]);
            if (upgrade_time[ancestor] > max_lock_time) max_lock_time = -2;
            ancestor = parents[ancestor];
        }
        return (max_lock_time != -2);
    }

    bool is_still_locked(int num) {
        if (locked_by[num] == -1) return false;
        int ancestor = parents[num];
        while (ancestor != -1) {
            if (upgrade_time[ancestor] > lock_time[num]) return false;
            ancestor = parents[ancestor];
        }
        return true;
    }

    void update_locked_child_count(int num, int count) {
        num = parents[num];
        while (num != -1) {
            locked_child_count[num] += count;
            num = parents[num];
        }
    }
};