class Solution {
    public int maxDistToClosest(int[] seats) {
        int ans = -1, lastSeat = -1;
        for (int i = 0; i < seats.length; ++i) {
            if (seats[i] == 1) {
                if (lastSeat == -1) {
                    lastSeat = i;
                    ans = lastSeat;
                } else {
                    ans = Math.max(ans, (i - lastSeat)/2);
                    lastSeat = i;
                }
                
            }
        }
        ans = Math.max(ans, seats.length - 1 - lastSeat);
        return ans;
    }
}