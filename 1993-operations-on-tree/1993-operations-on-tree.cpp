class LockingTree {
public:
    LockingTree(vector<int>& _parent) {
        parent = _parent;
        timestamp = 0;
        lockedBy = std::vector<int>(parent.size(), -1);
        upgradeTime = std::vector<int>(parent.size(), -1);
        lockTime = std::vector<int>(parent.size(), -2);
        lockedDescendents = std::vector<int>(parent.size(), 0);
    }
    
    bool lock(int num, int user) {
        if(!validLock(num)) {
            lockedBy[num] = user;
            lockTime[num] = timestamp++;
            propagateUp(num, 1);
            return true;
        }
        
        return false;
    }
    
    bool unlock(int num, int user) {
        if (validLock(num)) {
            if(lockedBy[num] == user) {
                lockedBy[num] = -1;
                lockTime[num] = -2;
                propagateUp(num, -1);
                return true;
            }
            return false;
        }
        return false;
    }
    
    bool upgrade(int num, int user) {
        if (!validLock(num) && !hasLockedAncestor(num) && (lockedDescendents[num] != 0)) {
            lockedBy[num] = user;
            lockTime[num] = upgradeTime[num] = timestamp++;
            propagateUp(num, 1-lockedDescendents[num]);
            lockedDescendents[num] = 0;
            return true;
        }
        
        return false;
    }
        
    bool validLock(int num) {
        if(lockedBy[num] == -1) return false;
        
        int p{parent[num]};
        while (p != -1) {
            if (upgradeTime[p] > lockTime[num]) {
                return false;
            }
            p = parent[p];
        }
        
        return true;
    }
        
    bool hasLockedAncestor(int num) {
        int p{parent[num]};
        
        int maxLockTime{-2};
        
        while (p != -1) {
            maxLockTime = std::max(maxLockTime, lockTime[p]);
            if (upgradeTime[p] > maxLockTime) {
                maxLockTime = -2;
            }
            p = parent[p];
        }

        return maxLockTime != -2;
    }
        
    void propagateUp(int num, int v) {
        
        int p = parent[num];
        
        while(p != -1) {
            lockedDescendents[p] += v;
            p = parent[p];
        }
    }
    
    std::vector<int> parent;
    std::vector<int> lockedBy;
    std::vector<int> upgradeTime;
    std::vector<int> lockTime;
    std::vector<int> lockedDescendents;
    int timestamp;
};