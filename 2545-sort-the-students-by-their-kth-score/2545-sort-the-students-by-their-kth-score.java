class Solution {
    public int[][] sortTheStudents(int[][] score, int k) {
        Arrays.sort(score, (s1, s2) -> s2[k] - s1[k]);
        return score;
    }
}