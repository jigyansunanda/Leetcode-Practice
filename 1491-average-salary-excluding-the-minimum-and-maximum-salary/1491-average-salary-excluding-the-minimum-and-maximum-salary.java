class Solution {
    public double average(int[] salary) {
        int n = salary.length;
        if (n == 2) return 0;
        Arrays.sort(salary);
        double sum = 0;
        for (int i=1; i<n-1; ++i) {
            sum = sum + (salary[i]);
        }
        return sum / (n-2);
    }
}