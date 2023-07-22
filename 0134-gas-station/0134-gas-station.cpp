class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currentPetrol = 0, prevPetrol = 0, startIndex = 0;
        for (int i = 0; i < ((int) gas.size()); ++i) {
            currentPetrol += (gas[i] - cost[i]);
            if (currentPetrol < 0) {
                startIndex = i + 1;
                prevPetrol += currentPetrol;
                currentPetrol = 0;
            }
        }
        return (currentPetrol + prevPetrol >= 0) ? startIndex : -1;
    }
};