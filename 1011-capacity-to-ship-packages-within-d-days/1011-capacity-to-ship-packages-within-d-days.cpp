class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        if (days == 1) return accumulate(weights.begin(), weights.end(), 0);
        int lo = *max_element(weights.begin(), weights.end())-1;
        int hi = accumulate(weights.begin(), weights.end(), 0);
        while (hi > lo + 1) {
            int mid = (lo + hi) >> 1;
            if (check(weights, days, mid)) hi = mid;
            else lo = mid;
        }
        return hi;
    }

    bool check(vector<int>& weights, int day, int w) {
        int currday = 0, currweight = 0;
        for (auto &weight : weights) {
            if (weight > w) return false;
            else if (currweight + weight < w) currweight += weight;
            else if (currweight + weight == w) {currweight = 0; currday++;}
            else {currweight = weight; currday++;}
        }
        if (currweight) currday++;
        return (currday <= day);
    }
};