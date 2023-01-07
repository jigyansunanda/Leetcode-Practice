class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasSpared = 0, gasRequired = 0;
        int startIndex = 0;
        for (int i = 0; i < gas.size(); ++i) {
            gasSpared += (gas[i] - cost[i]);
            if (gasSpared < 0) {
                startIndex = i + 1;
                gasRequired += abs(gasSpared);
                gasSpared = 0;
            }
        }
        return (gasSpared - gasRequired >= 0) ? startIndex : -1;
    }
};