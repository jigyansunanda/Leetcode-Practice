class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx and ty >= sy) {
            if (tx == ty) break;
            else if (tx > ty) {
                if (ty == sy) return (tx - sx) % sy == 0;
                else tx %= ty;
            } else {
                if (tx == sx) return (ty - sy) % tx == 0;
                else ty %= tx;
            }
        }
        return (sx == tx and sy == ty);
    }
};