class Solution {
    public int passThePillow(int n, int time) {
        int parity = (time / (n-1)) % 2;
        time %= (n-1);
        if (parity == 1) {
            return n-time;
        }else{
            return 1+time;
        }
    }
}