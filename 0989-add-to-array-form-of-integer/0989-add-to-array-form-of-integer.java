class Solution {
    public ArrayList<Integer> get_digits(int N) {
        ArrayList<Integer> digits = new ArrayList<>();
        while (N > 0) {
            digits.add(N%10);
            N /= 10;
        }
        Collections.reverse(digits);
        return digits;
    }

    public List<Integer> addToArrayForm(int[] num, int k) {
        int n = num.length;
        ArrayList<Integer> digits = get_digits(k);
        List<Integer> sum = new ArrayList<Integer>();
        int i = n - 1, j = digits.size() - 1, carry = 0;
        while (i >= 0 || j >= 0) {
            int s = carry + (i >= 0 ? num[i] : 0) + (j >= 0 ? digits.get(j) : 0);
            sum.add(s % 10);
            carry = s / 10;
            if (i >= 0) --i;
            if (j >= 0) --j;
        }
        if (carry > 0) sum.add(carry);
        Collections.reverse(sum);
        return sum;
    }
}