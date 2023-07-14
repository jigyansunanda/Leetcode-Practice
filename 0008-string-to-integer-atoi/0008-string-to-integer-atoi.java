class Solution {
    private int getNonEmptyStartIndex(String s) {
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) != ' ')
                return i;
        }
        return s.length();
    }

    public int myAtoi(String s) {
        int n = s.length(), startIndex = getNonEmptyStartIndex(s);
        if (startIndex == n)
            return 0;
        boolean isNegative = false;
        if (s.charAt(startIndex) == '-') {
            isNegative = true;
            ++startIndex;
        } else if (s.charAt(startIndex) == '+') {
            ++startIndex;
        }
        int intValue = 0;
        final int MAX = Integer.MAX_VALUE;
        final int MIN = Integer.MIN_VALUE;
        while (startIndex < n && Character.isDigit(s.charAt(startIndex))) {
            int digit = s.charAt(startIndex) - '0';
            if ((MAX / 10 == intValue && digit > (MAX % 10)) || (MAX / 10 < intValue)) {
                return (isNegative ? MIN : MAX);
            }
            intValue = (intValue * 10) + digit;
            ++startIndex;
        }
        return intValue * (isNegative ? -1 : 1);
    }
}