class Solution {
    public int gcd(int x, int y) {
        if (y == 0) {
            return x;
        } else {
            return gcd(y, x % y);
        }    
    }
    public String gcdOfStrings(String str1, String str2) {
        String a = str1 + str2;
        String b = str2 + str1;
        if (a.compareTo(b) != 0) return "";
        int m = str1.length(), n = str2.length();
        int g = gcd(m,n);
        return str1.substring(0, g);
    }
}