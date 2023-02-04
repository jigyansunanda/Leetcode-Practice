class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int m = s1.length(), n = s2.length();
        if (n < m) return false;
        int[] A = new int[26]; int[] B = new int[26];
        for (int i=0; i<m; ++i) A[s1.charAt(i)-'a']++;
        for (int i=0; i+m-1<n; ++i) {
            if (i==0) {
                for (int j=0; j<=i+m-1; ++j) B[s2.charAt(j)-'a']++;
            }else {
                B[s2.charAt(i-1)-'a']--;
                B[s2.charAt(i+m-1)-'a']++;
            }
            if (match(A, B)) return true;
        }
        return false;
    }

    boolean match(int[] A, int[] B) {
        for (int i=0; i<26; ++i) {
            if (A[i] != B[i]) {
                return false;
            }
        }
        return true;
    }
}