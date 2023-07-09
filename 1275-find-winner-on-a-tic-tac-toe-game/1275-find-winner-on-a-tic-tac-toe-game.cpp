class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int D = 0, AD = 0;
        int r[3] = {0};
        int c[3] = {0};
        int p = 1;
        for (auto move : moves) {
            r[move[0]] += p;
            c[move[1]] += p;
            if (move[0] == move[1]) D += p;
            if (move[0] + move[1] == 2) AD += p;
            if (r[move[0]] == 3 or c[move[1]] == 3 or D == 3 or AD == 3) return "A";
            if (r[move[0]] == -3 or c[move[1]] == -3 or D == -3 or AD == -3) return "B";
            p *= -1;
        }
        return (((int) moves.size()) == 9) ? "Draw" : "Pending";
    }
};